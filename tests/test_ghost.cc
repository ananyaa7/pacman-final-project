#include <catch2/catch.hpp>
#include <pacman_engine.h>
#include "ghost.h"

using namespace PacmanGame;

TEST_CASE("Update position of ghosts") {
  PacmanEngine pacman_engine;
  pacman_engine.SetUpGame("/Users/ananyaagarwal/Desktop/cinder_0.9.2_mac/my_projects/final-project-ananyaa7/tests/test_map.txt");
  Map test_map = pacman_engine.GetMap();
  std::vector<Ghost> ghosts = pacman_engine.GetGhosts();
  std::vector<Coordinates> orig_positions;

  for (const Ghost& ghost : ghosts) {
    orig_positions.push_back(ghost.GetGhostCoordinates());
  }

  for (size_t i = 0; i < 16; i++) {
    pacman_engine.UpdateGame();
  }

  std::vector<Ghost> updated_ghosts = pacman_engine.GetGhosts();

  SECTION("updated position for every ghost") {
    bool correct_test = true;

    for (size_t i = 0; i < ghosts.size(); i++) {
      if (updated_ghosts[i].GetGhostCoordinates() == orig_positions[i]) {
        correct_test = false;
      }
    }
    REQUIRE(correct_test);
  }

  SECTION("moves upward in the beginning to chase pacman") {
    bool is_successful = false;

    for (size_t i = 0; i < ghosts.size(); i++) {
      if (updated_ghosts[i].GetGhostCoordinates().first == orig_positions[i].first - 1) {
        is_successful = true;
      }
    }
    REQUIRE(is_successful);

  }
}