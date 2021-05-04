#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"

namespace PacmanGame {

class Snack {
public:
  /**
   * constructor class for snack
   * (explicit to remove unwanted implicit type conversion)
   * @param position - position for the snack
   */
  explicit Snack(const glm::vec2 &position);
  /**
   * getter for the position of the snack
   * @return the constant position of the snacks
   */

  const glm::vec2 &GetPosition() const;

  /**
   * function to draw the snack
   */
  void Draw();

  const static size_t kSnack_Radius = 3;

private:
  glm::vec2 position_;


};

} // namespace PacmanGame
