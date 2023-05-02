#include "menu.h"
#include <iostream>

Menu::MenuOption Menu::ShowMenu() {
  int choice;
  std::cout << "Welcome to the Snake Game!" << std::endl;
  std::cout << "1. Play Game" << std::endl;
  std::cout << "2. High Scores" << std::endl;
  std::cout << "3. Quit" << std::endl;
  std::cout << "Enter your choice (1-3): ";
  std::cin >> choice;

  switch (choice) {
    case 1:
      return MenuOption::kPlay;
    case 2:
      return MenuOption::kHighScores;
    case 3:
      return MenuOption::kQuit;
    default:
      std::cout << "Invalid choice. Exiting." << std::endl;
      return MenuOption::kQuit;
  }
}

std::string Menu::GetPlayerName() {
  std::string player_name;
  std::cout << "Enter your name: ";
  std::cin.ignore();
  std::getline(std::cin, player_name);
  return player_name;
}

void Menu::ShowHighScores(const HighScore &highscore) {
  std::cout << "High Scores:" << std::endl;
  highscore.DisplayHighScores();
}
