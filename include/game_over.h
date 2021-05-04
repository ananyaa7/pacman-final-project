#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "pacman.h"
#include "pacman_engine.h"
#include "ghost.h"

namespace PacmanGame {

class GameOverScreen {
public:
  /**
   * default constructor for GamOverScreen
   */
  GameOverScreen();

  /**
   * Draws the game over screen
   */
  void Draw();

  /**
   * Function to set the state of the game
   */
  void SetState(PacmanEngine::GameState state);

private:
  Pacman pacman_;
  std::vector<Ghost> ghosts_;
  PacmanEngine::GameState state_;
  std::string display_text_;

  const std::vector<std::string> kGhostColors = {"red", "purple", "orange"};

  const std::vector<char> kGhostNames = {'B', 'I', 'C'};


};

} // namespace PacmanGame

