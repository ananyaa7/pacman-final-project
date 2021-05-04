#pragma once
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "map.h"

namespace PacmanGame {

typedef std::chrono::time_point<std::chrono::system_clock> TimePoint;

class Pacman {
public:

  /**
   * default constructor for Pacman class
   */
  Pacman();

  /**
   * Draws Pacman
   */
  void Draw();

  //functions to move pacman
  void MoveUp();
  void MoveDown();
  void MoveLeft();
  void MoveRight();

  //getters and setters for pacman
  void SetPosition(const glm::vec2 &position);
  const glm::vec2 &GetPosition() const;
  double GetRadius() const;
  void SetRadius(double radius);

  enum State {NORMAL, POWERED_UP};

  State GetState() const;
  void SetState(State state);

  constexpr static double kSpeed = 40;

private:
  enum Direction {UP, DOWN, LEFT, RIGHT};
  Direction direction_;
  TimePoint begin_time_;
  glm::vec2 position_;
  double radius_;
  State state_;

};

} // namespace Pacman
