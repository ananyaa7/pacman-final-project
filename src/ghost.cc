#include "ghost.h"
#include "cinder/Rand.h"
#include <queue>

namespace PacmanGame {

Ghost::Ghost(const glm::vec2 &position, const std::string& color, char name) {
  name_ = name;
  starting_position_ = position;
  normal_color_ = ci::Color(color.c_str());
  size_ = Map::kWindowHeight / 60;
  color_ = normal_color_;
  frighten_color_ = ci::Color("blue");
  begin_time_ = std::chrono::system_clock::now();
  state_ = CHASE;
  update_count_ = 0;
  last_move_ = LEFT;
  position_ = starting_position_;
}

void Ghost::Draw() {

  ci::gl::color(color_);
  ci::gl::drawSolidCircle(position_, size_);

  DrawEyes();

  ci::gl::color(color_);

  // Get the centers for the ghost's legs and draws them
  glm::vec2 center1 = glm::vec2(position_.x - size_ / 1.5, position_.y + size_);
  glm::vec2 center2 = glm::vec2(position_.x, position_.y + size_);
  glm::vec2 center3 = glm::vec2(position_.x + size_ / 1.5, position_.y + size_);

  // Draws the lower part of the ghosts body
  glm::vec2 top_left = glm::vec2(position_.x - size_, position_.y);
  glm::vec2 bottom_right = glm::vec2(position_.x + size_, position_.y + size_);
  ci::Rectf body(top_left, bottom_right);
  ci::gl::drawSolidRect(body);

  ci::gl::drawSolidEllipse(center1, size_ / 3, size_ / 2);
  ci::gl::drawSolidEllipse(center2, size_ / 3, size_ / 2);
  ci::gl::drawSolidEllipse(center3, size_ / 3, size_ / 2);

}

//similar to pacman's mouth, understood from youtube

void Ghost::DrawEyes() {
  ci::gl::color(ci::Color("white"));
  glm::vec2 left_eye_location;
  glm::vec2 right_eye_location;

  double eye_size = size_ / 3;

  left_eye_location = glm::vec2(position_.x - eye_size, position_.y -
                                                        eye_size);
  right_eye_location = glm::vec2(position_.x + eye_size, position_.y -
                                                         eye_size);

  // Draws the eyes
  ci::gl::color(ci::Color("white"));
  ci::gl::drawSolidCircle(left_eye_location, eye_size);
  ci::gl::drawSolidCircle(right_eye_location, eye_size);

  if (color_ != frighten_color_) {
    DrawPupils();
  }
}

void Ghost::DrawPupils() {
  glm::vec2 left_eye_pupil_location;
  glm::vec2 right_eye_pupil_location;

  double eye_size = size_ / 3;
  double pupil_size = size_ / 6;

  // draws the pupil in the direction of the ghost's movements
  switch (last_move_) {
  case UP:
    left_eye_pupil_location = glm::vec2(position_.x - eye_size, position_.y
                                                                - eye_size - pupil_size);

    right_eye_pupil_location = glm::vec2(position_.x + eye_size, position_.y
                                                                 - eye_size - pupil_size);
    break;

  case DOWN:
    left_eye_pupil_location = glm::vec2(position_.x - eye_size,
                                        position_.y - eye_size + pupil_size);

    right_eye_pupil_location = glm::vec2(position_.x + eye_size, position_.y
                                                                 - eye_size + pupil_size);
    break;

  case RIGHT:
    left_eye_pupil_location = glm::vec2(position_.x - eye_size +
                                        pupil_size, position_.y - eye_size);

    right_eye_pupil_location = glm::vec2(position_.x + eye_size +
                                         pupil_size,position_.y - eye_size);

    break;

  case LEFT:
    left_eye_pupil_location = glm::vec2(position_.x - eye_size - pupil_size,
                                        position_.y - eye_size);

    right_eye_pupil_location = glm::vec2(position_.x + eye_size - pupil_size,
                                         position_.y - eye_size);
    break;
  }

  ci::gl::color(ci::Color("gray"));
  ci::gl::drawSolidCircle(left_eye_pupil_location, pupil_size);
  ci::gl::drawSolidCircle(right_eye_pupil_location, pupil_size);
}

void Ghost::GetStartingGhostCoordinates(const std::vector<std::vector<char>>
                                       &map_bricks) {
  for (size_t i= 0; i < map_bricks.size(); i++) {
    for (size_t j = 0; j < map_bricks[i].size(); j++) {
      //checking if the location is the intiial location on the map,if so then
      //break out of the loop
      if (map_bricks[i][j] == name_) {
        ghost_coordinates_ = starting_ghost_coordinates_ = Coordinates(i, j);
        break;
      }
    }
  }
}

void Ghost::Update(const std::vector<std::vector<char>>& map_bricks, const
Coordinates& pacman_coordinates, const Map& map) {

  //we want to update the ghosts after every 15 turns to set their speed and accuracy
  update_count_++;
  if (update_count_ % 15 != 0) {
    return;
  }

  if (state_ == FRIGHTEN) {
    Frighten(map_bricks);
    return;
  }

  // Get the current runtime duration of program to determine ghost state
  auto end_time = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_time = end_time - begin_time_;

  // after every 10 seconds chase pacman
  if ((int) (elapsed_time.count()) % 10 == 0) {
    state_ = CHASE;

    // after 25 seconds scatter to a corner
  } else if ((int) (elapsed_time.count()) % 25 == 0) {
    state_ = SCATTER;
  }

  // Don't do anything while the temporary walls are still there
  if (!(map.GetTempWalls().empty())) {
    return;
  }

  // Change back to their normal color if they were still in their frightened
  // color
  if (color_ == frighten_color_) {
    color_ = normal_color_;
  }

  if (state_ == SCATTER) {
    Scatter(map_bricks);

  } else {
    Chase(map_bricks, pacman_coordinates);
  }
}

void Ghost::Scatter(const std::vector<std::vector<char>>& map_tiles) {
  Coordinates corner_coordinates;

  // We send the ghosts to different corners depending on their name
  if (name_ == Map::kBlinky) {
    corner_coordinates = Coordinates(1, 1);
  } else if (name_ == Map::kInky) {
    corner_coordinates = Coordinates(19, 31);
  } else if (name_ == Map::kClyde) {
    corner_coordinates = Coordinates(1, 31);
  }

  // Get the path to their corner
  std::vector<Coordinates> path_to_corner = FindPathToBrick(map_tiles, corner_coordinates);

  // If they are already there, just return and don't do anything
  if (path_to_corner.size() == 0) {
    return;
  }

  // Moves the ghost to the next tile in the path
  Coordinates next_tile = path_to_corner[1];

  // Checks direction to move, then moves
  if (next_tile.first > ghost_coordinates_.first) {
    MoveDown();

  } else if (next_tile.first < ghost_coordinates_.first) {
    MoveUp();

  } else if (next_tile.second > ghost_coordinates_.second) {
    MoveRight();

  } else if (next_tile.second < ghost_coordinates_.second) {
    MoveLeft();
  }
}

void Ghost::Chase(const std::vector<std::vector<char>>& map_tiles, const
Coordinates& pacman_coordinates) {

  // Get the path to Pacman
  std::vector<Coordinates> path_to_pacman = FindPathToBrick
      (map_tiles, pacman_coordinates);

  Coordinates next_tile = path_to_pacman[1];

  // if it is empty, it is where pacman is
  if (path_to_pacman.empty()) {
    return;
  }

  if (next_tile.first > ghost_coordinates_.first) {
    MoveDown();

  } else if (next_tile.first < ghost_coordinates_.first) {
    MoveUp();

  } else if (next_tile.second > ghost_coordinates_.second) {
    MoveRight();

  } else if (next_tile.second < ghost_coordinates_.second) {
    MoveLeft();
  }
}

void Ghost::Frighten(const std::vector<std::vector<char>> &map_tiles) {
  color_ = ci::Color("blue");
  // Get the path to their initial coordinates
  std::vector<Coordinates> path_to_beginning = FindPathToBrick(map_tiles,
                                                              starting_ghost_coordinates_);

  // If they are already there, just return and don't do anything
  if (path_to_beginning.size() == 1) {
    return;
  }

  // Moves the ghost to the next tile in the path
  Coordinates next_tile = path_to_beginning[1];

  // checks direction to move in, then moves
  if (next_tile.first > ghost_coordinates_.first) {
    MoveDown();

  } else if (next_tile.first < ghost_coordinates_.first) {
    MoveUp();

  } else if (next_tile.second > ghost_coordinates_.second) {
    MoveRight();

  } else if (next_tile.second < ghost_coordinates_.second) {
    MoveLeft();
  }
}

void Ghost::MoveUp() {
  position_.y -= kGhost_Speed;
  last_move_ = UP;
  ghost_coordinates_.first--;
}

void Ghost::MoveDown() {
  position_.y += kGhost_Speed;
  last_move_ = DOWN;
  ghost_coordinates_.first++;
}

void Ghost::MoveRight() {
  position_.x += kGhost_Speed;
  last_move_ = RIGHT;
  ghost_coordinates_.second++;
}

void Ghost::MoveLeft() {
  position_.x -= kGhost_Speed;
  last_move_ = LEFT;
  ghost_coordinates_.second--;
}

std::vector<Coordinates> Ghost::FindPathToBrick(const
                                               std::vector<std::vector<char>>& map_bricks, const Coordinates& destination) {

  //this initialises a visited tiles queue
  std::queue<Coordinates> visited_tiles;
  std::vector<std::vector<bool>> visited(100, std::vector<bool>(100,false));
  std::vector<std::vector<Coordinates>> prev_coord(100, std::vector<Coordinates>(100));

  // First push to the queue the initial coordinates of the ghost and mark it
  // as visited
  visited_tiles.push(ghost_coordinates_);
  visited[ghost_coordinates_.first][ghost_coordinates_.second] = true;

  // Loop until the queue is empty
  while (!visited_tiles.empty()) {

    // Pop from the queue and get the coordinates
    Coordinates coordinates = visited_tiles.front();
    visited_tiles.pop();

    // If the coordinates are the destination, then we reconstruct the path
    // from the destination to the ghost coordinates based on the previous
    // tiles traversed to get the destination
    if (coordinates.first == destination.first && coordinates.second == destination.second) {
      return ConstructPath(prev_coord, destination);
    }

    // If we haven't reached the destination, we get the neighbors of the
    // current tile
    std::vector<Coordinates> neighbors = GetNeighbors(coordinates);

    // Loop through each neighbor
    for (const Coordinates& neighbor : neighbors) {

      // Check if the bounds are within the map
      if (neighbor.first > map_bricks.size() - 1 || neighbor.first < 0 ||
          neighbor.second > map_bricks[0].size() - 1|| neighbor.second < 0) {
        continue;
      }

        // Check if we have visited the tile already
      else if (visited[neighbor.first][neighbor.second]) {
        continue;

        // Check if the tile is a wall or not
      } else if (map_bricks[neighbor.first][neighbor.second] == 'W') {
        continue;
      }

      // We add to the prev 2d array the initial coordinates we were at
      prev_coord[neighbor.first][neighbor.second] = coordinates;

      // Push the neighbor ot the queue
      visited_tiles.push(neighbor);

      // Mark the tile as visited
      visited[neighbor.first][neighbor.second] = true;
    }
  }
  return std::vector<Coordinates>();
}

std::vector<Coordinates> Ghost::GetNeighbors(const Coordinates& coordinates) {
  std::vector<Coordinates> neighbors;
  Coordinates top = Coordinates(coordinates.first - 1, coordinates.second);
  Coordinates down = Coordinates(coordinates.first + 1,
                                 coordinates.second);
  Coordinates right = Coordinates(coordinates.first,
                                  coordinates.second + 1);
  Coordinates left = Coordinates(coordinates.first,
                                 coordinates.second - 1);

  // add the vectors to their respective coordinates
  neighbors.push_back(top);
  neighbors.push_back(down);
  neighbors.push_back(left);
  neighbors.push_back(right);
  return neighbors;
}

std::vector<Coordinates> Ghost::ConstructPath(const
                                                std::vector<std::vector<Coordinates>>& prev_coord, const Coordinates& destination) {
  Coordinates place_holder = destination;
  std::vector<Coordinates> path;
  path.push_back(destination);

  // Loop until the temp coordinate is equal to the ghost coordinates
  while (place_holder != ghost_coordinates_) {

    //loads steps from our earlier array
    Coordinates step = prev_coord[place_holder.first][place_holder.second];
    path.push_back(step);
    place_holder = step;
  }

  //this reverses the path
  std::reverse(path.begin(), path.end());
  return path;
};

void Ghost::Respawn() {
  ghost_coordinates_ = starting_ghost_coordinates_;
  position_ = starting_position_;
  color_ = normal_color_;
  state_ = CHASE;
}

const glm::vec2 &Ghost::GetPosition() const {
  return position_;
}
void Ghost::SetState(const State& state) {
  state_ = state;
}
const Coordinates &Ghost::GetGhostCoordinates() const {
  return ghost_coordinates_;
}

void Ghost::SetSize(double size) {
  size_ = size;
}

Ghost::State Ghost::GetState() const {
  return state_;
}

} // namespace PacmanGame
