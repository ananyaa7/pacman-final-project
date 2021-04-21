
#ifndef FINAL_PROJECT_ANANYAA7_MY_APP_H
#define FINAL_PROJECT_ANANYAA7_MY_APP_H

#include <cinder/app/App.h>


namespace myapp {

class MyApp : public cinder::app::App {
public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
};

}  // namespace myapp

#endif // FINAL_PROJECT_ANANYAA7_MY_APP_H
