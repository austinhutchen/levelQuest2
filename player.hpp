#pragma ONCE
#include <iostream>
#include <vector>

class player {
public:
  player(int bound,std::string model) {
   setchar(model);
    for (int i = 0; i < bound; i++) {
      health.push_back("❤️");
    }
    std::cout << std::endl;
  }

  void setchar(std::string input) { this->model = input; }

  void gethp() {
    std::cout << this->model << "HEALTH :" << std::endl;
    for (int i = 0; i < health.size(); i++) {
      std::cout << health[i];
    }
    std::cout << std::endl;
  }

private:
  // used for moving around graph/map data structure
  int locationx;
  int locationy;
  std::string model;
  std::vector<std::string> health;
};