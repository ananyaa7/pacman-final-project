#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"


namespace PacmanGame {

class Wall {
public:

  /**
   * constructor function
   * @param top_left the top left corner position
   * @param bottom_right the bottom right corner position
   */
  Wall(const glm::vec2 &top_left, const glm::vec2 &bottom_right);

  /**
   * function to draw a wall based on its location
   */
  void Draw();

  const glm::vec2 &GetTopLeft() const;
  const glm::vec2 &GetBottomRight() const;
private:
  glm::vec2 top_left_corner;
  glm::vec2 bottom_right_corner;
};

} // namespace PacmanGame