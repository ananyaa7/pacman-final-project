//
// Created by ANANYA AGARWAL on 23/04/21.
//
#include "wall.h"

namespace PacmanGame {

Wall::Wall(const glm::vec2 &top_left, const glm::vec2 &bottom_right) {
  top_left_corner= top_left;
  bottom_right_corner = bottom_right;
}

void Wall::Draw() {
  ci::gl::color(ci::Color("blue"));
  ci::Rectf wall(top_left_corner, bottom_right_corner);
  ci::gl::drawSolidRect(wall);
}

const glm::vec2 &Wall::GetTopLeft() const {
  return top_left_corner;
}
const glm::vec2 &Wall::GetBottomRight() const {
  return bottom_right_corner;
}

} // namespace PacmanGame