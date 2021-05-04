#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "map.h"
#include <queue>

namespace PacmanGame {

typedef std::pair<size_t, size_t> Coordinates;

typedef std::chrono::time_point<std::chrono::system_clock> TimePoint;

class Ghost {
public:

  /**
   * constructor for ghost class
   * @param position the position of the ghost on the map
   * @param color the color of the ghost
   * @param name the first letter of the name
   */
  Ghost(const glm::vec2 &position, const std::string& color, char name);

  /**
   * Draws the ghost
   */
  void Draw();

  /**
   * Updates the position of the ghost
   * @param map_bricks the 2d array of the bricks of the map
   * @param pacman_location gives pacman location
   * @param map loads the map for the game
   */
  void Update(const std::vector<std::vector<char>>& map_bricks, const
  Coordinates& pacman_coordinates, const Map& map);

  /**
  * Respawns the ghost back to its initial coordinates
  */
  void Respawn();

  /**
   * Gets the starting coordinates of the ghost
   * @param map_tiles the 2d array of the map tiles
   */
  void GetStartingGhostCoordinates(const std::vector<std::vector<char>>
                                  &map_tiles);

  const glm::vec2 &GetPosition() const;
  const std::pair<size_t, size_t> &GetGhostCoordinates() const;

  enum State {
    SCATTER, CHASE, FRIGHTEN
  };

  void SetState(const State& state);

  State GetState() const;

  enum Move {
    UP, DOWN, RIGHT, LEFT
  };

  void SetSize(double size);


private:

  /**
   * draws the pupil of the ghost(similar to pacman mouth)
   */
  void DrawPupils();

  /**
   * Draws the eyes of the ghost
   */
  void DrawEyes();

  /**
   * Moves the ghost up
   */
  void MoveUp();

  /**
   * Moves the ghost down
   */
  void MoveDown();

  /**
   * Moves the ghost left
   */
  void MoveLeft();

  /**
   * Moves the ghost right
   */
  void MoveRight();

  /**
   * Scatters the movement of the ghost
   */
  void Scatter(const std::vector<std::vector<char>>& map_tiles);

  /**
   * Chases Pacman
   * @param pacman_location the location of Pacman
   */
  void Chase(const std::vector<std::vector<char>>& map_tiles, const
  Coordinates& pacman_coordinates);

    /**
     * frightened state of ghost
     */
  void Frighten(const std::vector<std::vector<char>>& map_tiles);

  /**
   * Gets the neighboring position vectors surrounding the ghost
   * @return a map of the move and the neighboring position vector
   */
  std::vector<Coordinates> GetNeighbors(const Coordinates& coordinates);


  /**
   * finds path to a certain wall brick
   * @param map_bricks the 2d array of bricks of map
   * @param destination the coordinates of the destination
   * @return a vector of coordinates that represents the path to the destination
   */
  std::vector<Coordinates> FindPathToBrick(const std::vector<std::vector<char>>&
  map_bricks, const Coordinates& destination);

  /**
   * constructs the path from the ghost to pacman
   * @param prev_coord the 2d vector of the previous coordinates before the step is
   * made
   * @param destination the destination of the ghost
   * @return a vector of coordinates that represents the path to the destination
   */
  std::vector<Coordinates> ConstructPath(const
                                           std::vector<std::vector<Coordinates>>& prev_coord, const Coordinates& destination);


  char name_;
  State state_;
  Move last_move_;
  size_t update_count_;
  glm::vec2 starting_position_;
  glm::vec2 position_;
  Coordinates ghost_coordinates_;
  Coordinates starting_ghost_coordinates_;
  ci::Color color_;
  ci::Color normal_color_;
  ci::Color frighten_color_;
  TimePoint begin_time_;
  double size_;
  constexpr static double kGhost_Speed = 40;
};

} // namespace PacmanGame

