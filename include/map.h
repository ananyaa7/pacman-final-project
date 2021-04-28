#pragma once

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "wall.h"
#include "snack.h"
#include "power_up.h"
#include <string>
#include <vector>

namespace PacmanGame {

//Gets the time during the running of the apllication
typedef std::chrono::time_point<std::chrono::system_clock> TimePoint;

class Map {
public:
  // Constants for the GUI window size
  const static size_t kWindowHeight = 750;
  const static size_t kWindowWidth = 1200;

  //gets the constant wall tile
  const std::vector<Wall> &GetWalls() const;
  std::vector<std::vector<char>> &GetMapTiles();

  //getters which get the snacks and powerups(not constant cause can be eaten)
  std::vector<Snack> &GetSnacks();
  std::vector<PowerUp> &GetPowerUps();

  //getters for location of pacman,ghost and temp walls
  const glm::vec2 &GetPacmanLocation() const;
  const std::vector<glm::vec2> &GetGhostLocations() const;
  const std::vector<Wall> &GetTempWalls() const;

  const static char kWall = 'W';
  const static char kBlinky = 'B';
  const static char kInky = 'I';
  const static char kClyde = 'C';
  const static char kPacman = 'P';

  /**
   * Default constructor for Map class
   */
  Map();

  /**
   * Loads in a map from a text file and stores the walls, snacks, etc
   * @param map the path to the map file
   */
  void LoadInMap(const std::string& map);

  /**
   * Loads in and draws the map from a txt file
   * @param map the path to the txt file with the map
   */
  void DrawMap(const TimePoint& begin_time);

private:
  std::vector<std::vector<char>> map_tiles_;
  glm::vec2 pacman_location_;
  std::vector<Wall> walls_;
  std::vector<Wall> temp_walls_;
  std::vector<Snack> snacks_;
  std::vector<PowerUp> power_ups_;
  std::vector<glm::vec2> ghost_locations_;

  // This constant scales the size and placement of the walls
  const static int kScalingFactor = (int) kWindowWidth / 80;
  const int kLoopingFactor = kScalingFactor / 10;

  // These constants represent the chars used for walls, snacks etc. from the
  // map
  const static char kTempWall = 'T';
  const static char kSnack = '-';
  const static char kPowerUp = 'U';
  const static size_t kTempWallDuration = 10;

};
}

#ifndef FINAL_PROJECT_ANANYAA7_PACMAN_MAP_H
#define FINAL_PROJECT_ANANYAA7_PACMAN_MAP_H

#endif // PACMAN_MAP_H
