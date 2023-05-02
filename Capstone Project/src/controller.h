#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "menu.h"

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake) const;
  void HandleMenuInput(bool &menu_running, Menu &menu, HighScore &highscore);


 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif