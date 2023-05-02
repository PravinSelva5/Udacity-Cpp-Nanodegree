#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "menu.h"
#include "highscore.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  
  Menu menu;
  HighScore highscore;
  bool menu_running = true;

  while (menu_running) {
    Menu::MenuOption option = menu.ShowMenu();

    switch (option) {
      case Menu::MenuOption::kPlay: {
        game.Run(controller, renderer, kMsPerFrame);
        highscore.AddHighScore(menu.GetPlayerName(), game.GetScore());
        highscore.SaveHighScores();
        break;
      }
      case Menu::MenuOption::kHighScores: {
        menu.ShowHighScores(highscore);
        break;
      }
      case Menu::MenuOption::kQuit:
        menu_running = false;
        break;
    }
  }

  std::cout << "Game has terminated successfully!\n";
  return 0;
}
