#include "pacman_engine.h"

namespace PacmanGame {

PacmanEngine::PacmanEngine() {
  begin_time_ = std::chrono::system_clock::now();
  pacman_state_ = ALIVE;
  game_state_ = ACTIVE;
  score_ = 0;
  lives_ = 3;
}

void PacmanEngine::SetUpGame(const std::string& map) {
  map_.LoadInMap(map);
  pacman_.SetPosition(map_.GetPacmanLocation());
  const std::vector<glm::vec2>& ghost_locations = map_.GetGhostLocations();

  // Get the map bricks and store it
  map_bricks_ = map_.GetMapBricks();
  GetStartingPacmanCoordinates();

  // Create ghosts based on their locations and color
  for (size_t i = 0; i < ghost_locations.size(); i++) {
    ghosts_.emplace_back(ghost_locations[i], kGhostColors[i], kGhostNames[i]);
    ghosts_[i].GetStartingGhostCoordinates(map_.GetMapBricks());
  }

}

void PacmanEngine::GetStartingPacmanCoordinates() {
  for (size_t i = 0; i < map_bricks_.size(); i++) {
    for (size_t j = 0; j < map_bricks_[i].size(); j++) {
      if (map_bricks_[i][j] == Map::kPacman) {
        pacman_coordinates_ = starting_pacman_coordinates_ = std::make_pair(i, j);
        break;
      }
    }
  }
}

void PacmanEngine::DrawGame() {
  map_.DrawMap(begin_time_);

  DrawLives();

  for (Ghost& ghost: ghosts_) {
    ghost.Draw();
  }

  // Only draw Pacman if he's alive
  if (pacman_state_ == ALIVE) {
    pacman_.Draw();
  }
}

void PacmanEngine::DrawLives() const {
  ci::gl::drawStringCentered(
      "Lives: ",
      glm::vec2(Map::kWindowWidth * .88, Map::kWindowHeight * .3),
      ci::Color("white"), ci::Font("Arial", 40));

  for (size_t i = 0; i < lives_; i++) {

    //draws pacman's lives
    ci::gl::color(ci::Color("yellow"));
    glm::vec2 center = glm::vec2(Map::kWindowWidth * .85 + 85 * i,
                                 Map::kWindowHeight * .4);
    ci::gl::drawSolidCircle(center,pacman_.GetRadius() * 1.3);

    ci::gl::color(ci::Color("black"));
    glm::vec2 pt2 = glm::vec2(center.x + pacman_.GetRadius() * 2, center.y +
                                                                  pacman_.GetRadius());
    glm::vec2 pt3 = glm::vec2(center.x + pacman_.GetRadius() * 2, center.y -
                                                                  pacman_.GetRadius());
    ci::gl::drawSolidTriangle(center, pt2, pt3);
  }
}

void PacmanEngine::RespawnPacman() {
  pacman_state_ = ALIVE;
  pacman_.SetPosition(map_.GetPacmanLocation());
}

void PacmanEngine::UpdateGame() {

  // game is empty/won if there are no more snacks
  if (map_.GetSnacks().empty()) {
    game_state_ = WON;
    return;
  }

  UpdatePacmanState();

  for (Ghost& ghost : ghosts_) {
    ghost.Update(map_.GetMapBricks(), pacman_coordinates_, map_);

    //if pacman and ghost are on the same bricks then check if pacman is powered
    //up or not.
    if (HasPacmanDied(ghost) && pacman_state_ != DEAD) {
      if (pacman_.GetState() == Pacman::NORMAL) {

        // Set Pacman's coordinates back to starting ones
        pacman_coordinates_ = starting_pacman_coordinates_;
        lives_--;

        // If we have no more lives, the game state is over
        if (lives_ == 0) {
          game_state_ = END;
        }
        pacman_state_ = DEAD;
        ScatterGhosts();

        // We've eaten a ghost
      } else {
        score_ += 100;
        ghost.Respawn();
      }
    }
  }
}

void PacmanEngine::MovePacman(const std::string& direction) {

  //if pacman has died do nothing
  if (pacman_state_ == DEAD) {
    return;
  }

  if (direction == "left") {
    if (IsLeftWallCollision()) {
      return;
    }
    pacman_coordinates_.second--;
    pacman_.MoveLeft();

  } else if (direction == "right") {
    if (IsRightWallCollision()) {
      return;
    }
    pacman_coordinates_.second++;
    pacman_.MoveRight();

  } else if (direction == "up") {
    if (IsUpWallCollision()) {
      return;
    }
    pacman_coordinates_.first--;
    pacman_.MoveUp();

  } else if (direction == "down") {
    if (IsDownWallCollision()) {
      return;
    }
    pacman_coordinates_.first++;
    pacman_.MoveDown();
  }

  if (HasEatenSnack()) {
    score_++;
  }

  if (HasEatenPowerUp()) {
    pacman_.SetState(Pacman::POWERED_UP);
    for (Ghost& ghost : ghosts_) {
      ghost.SetState(Ghost::FRIGHTEN);
    }
  }

}


void PacmanEngine::UpdatePacmanState() {
  TimePoint end_time = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_time = end_time - begin_time_;
  if (pacman_.GetState() == Pacman::POWERED_UP) {

    // If Pacman is powered up, only power up for a set duration
    if ((int) elapsed_time.count() % kPowerUpDuration == 0) {
      pacman_.SetState(Pacman::NORMAL);
      for (Ghost& ghost : ghosts_) {
        ghost.SetState(Ghost::CHASE);
      }
    }

  } else if (pacman_state_ == DEAD) {
    if ((int) elapsed_time.count() % kPowerUpDuration == 0) {
      RespawnPacman();
    }
  }
}

void PacmanEngine::ScatterGhosts() {
  for (Ghost& ghost : ghosts_) {
    ghost.SetState(Ghost::SCATTER);
  }
}

bool PacmanEngine::HasPacmanDied(const Ghost& ghost) {
  if (pacman_coordinates_ == ghost.GetGhostCoordinates()) {
    return true;
  }
  return false;
}

bool PacmanEngine::IsUpWallCollision() {

  Coordinates up = Coordinates(pacman_coordinates_.first - 1,
                               pacman_coordinates_.second);
  if (map_bricks_[up.first][up.second] == Map::kWall) {
    return true;
  }
  return false;
}

bool PacmanEngine::IsDownWallCollision() {
  Coordinates up = Coordinates(pacman_coordinates_.first + 1,
                               pacman_coordinates_.second);
  if (map_bricks_[up.first][up.second] == Map::kWall) {
    return true;
  }
  return false;
}

bool PacmanEngine::IsLeftWallCollision() {
  Coordinates left = Coordinates(pacman_coordinates_.first,
                                 pacman_coordinates_.second - 1);
  if (map_bricks_[left.first][left.second] == Map::kWall) {
    return true;
  }
  return false;
}

bool PacmanEngine::IsRightWallCollision() {
  Coordinates right = Coordinates(pacman_coordinates_.first,
                                  pacman_coordinates_.second + 1);
  if (map_bricks_[right.first][right.second] == Map::kWall) {
    return true;
  }
  return false;
}

bool PacmanEngine::HasEatenSnack() {
  std::vector<Snack>& all_snacks = map_.GetSnacks();
  glm::vec2 active_pos = pacman_.GetPosition();

  for (size_t i = 0; i < all_snacks.size(); i++) {

    // Just like ideal gas,if distance between pacman and snack is less than the
    //sum of their radii then he has eaten the snack
    if (glm::distance(all_snacks[i].GetPosition(), active_pos) <=
        Snack::kSnack_Radius + pacman_.GetRadius()) {
      all_snacks.erase(all_snacks.begin() + i);
      return true;
    }
  }
  return false;
}

bool PacmanEngine::HasEatenPowerUp() {
  std::vector<PowerUp>& all_power_ups = map_.GetPowerUps();
  glm::vec2 active_pos = pacman_.GetPosition();

  for (size_t i = 0; i < all_power_ups.size(); i++) {
    if (glm::distance(all_power_ups[i].GetPosition(), active_pos) <=
        Snack::kSnack_Radius + pacman_.GetRadius()) {
      all_power_ups.erase(all_power_ups.begin() + i);
      return true;
    }
  }
  return false;
}

size_t PacmanEngine::GetScore() const {
  return score_;
}

const Map &PacmanEngine::GetMap() const {
  return map_;
}

const std::vector<Ghost> &PacmanEngine::GetGhosts() const {
  return ghosts_;
}

PacmanEngine::GameState PacmanEngine::GetGameState() const {
  return game_state_;
}

} // namespace PacmanGame