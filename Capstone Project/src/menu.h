#ifndef MENU_H
#define MENU_H

#include <string>
#include "highscore.h"

class Menu {
 public:
  enum class MenuOption { kPlay, kHighScores, kQuit };

  MenuOption ShowMenu();
  std::string GetPlayerName();
  void ShowHighScores(const HighScore &highscore);

 private:
  MenuOption menu_option{MenuOption::kPlay};
};

#endif