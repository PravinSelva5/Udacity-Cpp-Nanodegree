#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <string>
#include <vector>
#include <utility>

class HighScore {
 public:
  HighScore();
  void LoadHighScores();
  void SaveHighScores();
  void AddHighScore(const std::string &name, int score);
  void DisplayHighScores()const;

 private:
  std::vector<std::pair<std::string, int>> high_scores;
  const std::string highscore_file = "highscores.txt";
  const std::size_t kMaxHighScores = 10;
};

#endif
