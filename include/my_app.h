
#ifndef FINAL_PROJECT_ANANYAA7_MY_APP_H
#define FINAL_PROJECT_ANANYAA7_MY_APP_H

#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "pacman_engine.h"
#include "ghost.h"

namespace PacmanGame {

class PacmanApp : public ci::app::App {
public:
  PacmanApp();

  void draw() override;
  void update() override;
  void setup() override;
  void keyDown(ci::app::KeyEvent event) override;

private:
  PacmanEngine pacman_engine_;
  const std::string kMapPath = "map.txt";
};

} // namespace PacmanGame


#endif // FINAL_PROJECT_ANANYAA7_MY_APP_H
