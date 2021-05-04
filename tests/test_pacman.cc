#include <catch2/catch.hpp>
#include "pacman.h"

using namespace PacmanGame;

TEST_CASE("Pacman moves correctly") {
  Pacman pacman;
  glm::vec2 curr_pos = pacman.GetPosition();

  SECTION("Move up") {
    pacman.MoveUp();
    glm::vec2 updated_pos = pacman.GetPosition();
    REQUIRE(curr_pos.y - Pacman::kSpeed == updated_pos.y);
  }

  SECTION("Move down") {
    pacman.MoveDown();
    glm::vec2 updated_pos = pacman.GetPosition();
    REQUIRE(curr_pos.y + Pacman::kSpeed == updated_pos.y);
  }

  SECTION("Moves right") {
    pacman.MoveRight();
    glm::vec2 updated_pos = pacman.GetPosition();
    REQUIRE(curr_pos.x + Pacman::kSpeed == updated_pos.x);
  }

  SECTION("Moves left") {
    pacman.MoveLeft();
    glm::vec2 updated_pos = pacman.GetPosition();
    REQUIRE(curr_pos.x - Pacman::kSpeed == updated_pos.x);
  }
}