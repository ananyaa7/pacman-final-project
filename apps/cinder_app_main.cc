#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

#include "my_app.h"

using PacmanGame::PacmanApp;

void prepareSettings(PacmanApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(PacmanApp, ci::app::RendererGl, prepareSettings);
