#include <my_app.h>

namespace PacmanGame {

PacmanApp::PacmanApp() {
  ci::app::setWindowSize(Map::kWindowWidth, Map::kWindowHeight);
}

void PacmanApp::draw() {
  ci::Color8u background_color(0, 0, 0);  // This is for black bg
  ci::gl::clear(background_color);

  // if the game state is active we draw the game otherwise we draw game over screen
  if (pacman_engine_.GetGameState() == PacmanEngine::GameState::ACTIVE) {
    pacman_engine_.DrawGame();
    ci::gl::drawStringCentered(
        "Score: " + std::to_string(pacman_engine_.GetScore()),
        glm::vec2(Map::kWindowWidth * .7, Map::kWindowHeight * .1),
        ci::Color("white"), ci::Font("Arial", 40));

  } else {

    // displays game over screen based on whether you have lost or won
    game_over_screen_.SetState(pacman_engine_.GetGameState());
    game_over_screen_.Draw();
  }
}
void PacmanApp::update() {
  // keep uppdating the game while the state is active
  if (pacman_engine_.GetGameState() == PacmanEngine::GameState::ACTIVE) {
    pacman_engine_.UpdateGame();
  } else {
    return;
  }
}

void PacmanApp::setup() {
  pacman_engine_.SetUpGame(kMapPath);
}

void PacmanApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
  case ci::app::KeyEvent::KEY_LEFT:
    pacman_engine_.MovePacman("left");
    break;

  case ci::app::KeyEvent::KEY_RIGHT:
    pacman_engine_.MovePacman("right");
    break;

  case ci::app::KeyEvent::KEY_UP:
    pacman_engine_.MovePacman("up");
    break;

  case ci::app::KeyEvent::KEY_DOWN:
    pacman_engine_.MovePacman("down");
    break;

  case ci::app::KeyEvent::KEY_ESCAPE:
    std::exit(0);
  }
}


} // namespace PacmanGame