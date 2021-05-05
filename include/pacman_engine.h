#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "pacman.h"
#include "map.h"
#include "ghost.h"

namespace PacmanGame {

typedef std::chrono::time_point<std::chrono::system_clock> TimePoint;

class PacmanEngine {
public:

  /**
   * Default constructor for the engine class
   */
  PacmanEngine();

  /**
   * to draw the game
   */
  void DrawGame();

  /**
   * Moves Pacman
   * @param event the keyboard event from Cinder
   */
  void MovePacman(const std::string& direction);

  /**
   * Sets up the game by loading in the map
   * @param map the path to the map
   */
  void SetUpGame(const std::string& map);

  /**
  * Updates the state of the game
  */
  void UpdateGame();

  size_t GetScore() const;
  const Map &GetMap() const;
  const std::vector<Ghost> &GetGhosts() const;

  const std::vector<std::string> kGhostColors = {"red", "purple", "orange"};
  const std::vector<char> kGhostNames = {'B', 'I', 'C'};

  enum GameState {ACTIVE, END, WON};
  enum PacmanState {ALIVE, DEAD};

  GameState GetGameState() const;

private:
  Pacman pacman_;
  PacmanState pacman_state_;
  Coordinates pacman_coordinates_;
  Map map_;
  TimePoint begin_time_;
  size_t score_;
  Coordinates starting_pacman_coordinates_;
  std::vector<std::vector<char>> map_bricks_;
  std::vector<Ghost> ghosts_;
  size_t lives_;
  GameState game_state_;

  //hpw long the power up will last
  const static size_t kPowerUpDuration = 5;

  /**
  * Gets the starting coordinates of Pacman
  */
  void GetStartingPacmanCoordinates();

  /**
   * checks for collision with wall above pacman
   * @return bool for true/false collision
   */
  bool IsUpWallCollision();

  /**
   * checks for collision with wall below pacman
   * @return bool for true/false collision
   */
  bool IsDownWallCollision();

  /**
   * checks for collision with wall left to pacman
   * @return bool for true/false collision
   */
  bool IsLeftWallCollision();

  /**
   * checks for collision with wall right to pacman
   * @return bool for true/false collision
   */
  bool IsRightWallCollision();

  /**
   * displays the number of lives
   */
  void DrawLives() const;

  /**
   * Checks if Pacman has eaten a snack
   * @return a bool for true/false snack eaten
   */
  bool HasEatenSnack();

  /**
   * Checks if Pacman has eaten a power up
   * @return bool for true/false power up eaten
   */
  bool HasEatenPowerUp();

  /**
   * Checks if Pacman has died
   * @param ghost the ghost in the map
   * @return bool for true/false alive pacman
   */
  bool HasPacmanDied(const Ghost &ghost);

  /**
   * Respawns Pacman back at its initial location
   */
  void RespawnPacman();

  /**
  * Updates the DEAD/ALIVE state and NORMAL/POWERED UP state of Pacman
  */
  void UpdatePacmanState();

  /**
   * Scatters the ghosts
   */
  void ScatterGhosts();

};

} // namespace PacmanGam
