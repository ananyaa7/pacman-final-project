
#include "my_app.h"

using PacmanGame::PacmanApp;

void prepareSettings(PacmanApp::Settings* settings) {
  settings->setResizable(true);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(PacmanApp, ci::app::RendererGl, prepareSettings);
