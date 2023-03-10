#pragma ONCE
#include <iostream>
#include <vector>

class enemy {

public:
  enemy() {
    for (int i = 0; i < 10; i++) {
      health.push_back("hp");
    }
  }
  
  unsigned short gethp() {
    unsigned short int hp = 0;
    for (int i = 0; i < this->health.size(); i++) {
      if (this->health[i] == "hp") {
        hp++;
      }
    }
    return hp;
  }

  void setchar(char val) { this->model = val; }

private:
  std::vector<std::string> health;
  char model;
  int locationx;
  int location;
};