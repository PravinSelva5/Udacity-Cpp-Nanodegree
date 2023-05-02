#include "highscore.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>

HighScore::HighScore() { LoadHighScores(); }

void HighScore::LoadHighScores() {
  std::ifstream file("highscores.txt");
  if (!file) {
    std::cerr << "Error opening highscores.txt file.\n";
    return;
  }

  high_scores.clear();
  std::string line;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string name;
    int score;
    iss >> name >> score;
    high_scores.push_back({name, score});
  }

  file.close();
}

void HighScore::SaveHighScores() {
  std::ofstream file("highscores.txt");
  if (!file) {
    std::cerr << "Error opening highscores.txt file.\n";
    return;
  }

  for (const auto &entry : high_scores) {
    file << entry.first << " " << entry.second << std::endl;
  }

  file.close();
}

void HighScore::AddHighScore(const std::string &name, int score) {
  high_scores.push_back({name, score});
  std::sort(high_scores.begin(), high_scores.end(),
          [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) { return a.second > b.second; });


  if (high_scores.size() > kMaxHighScores) {
    high_scores.pop_back();
  }
}

void HighScore::DisplayHighScores() const {
  std::cout << "\nHigh Scores:\n";
  for (const auto &entry : high_scores) {
    std::cout << entry.first << ": " << entry.second << std::endl;
  }
  std::cout << std::endl;
}
