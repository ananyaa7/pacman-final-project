#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"

namespace PacmanGame {

class PowerUp {
public:
  /**
   * constructor for the power up class
   * @param position the position of the power up
   */
  PowerUp(const glm::vec2 &position);

  /**
   * Draws a power up based on its location
   */
  void Draw();

  /**
   * getter for the power up position
   * @return the position for the power up snack
   */
  const glm::vec2 &GetPosition() const;

private:
  glm::vec2 position_;

  //needs to be bigger than the normal snack
  const static size_t kRadius = 6;

};

} // namespace PacmanGame