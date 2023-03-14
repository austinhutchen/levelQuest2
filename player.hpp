#pragma ONCE
#include <iostream>
#include <vector>

class player {
public:
  player(int bound, std::string model) {
    this->locationx = 0;
    this->locationy = 0;
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

  int getx() { return locationx; }
  int gety() { return locationy; }
  std::string getchar() { return this->model; }
  void up() {
    if (locationx != 0) {
      this->locationx--;
    }
  }
  void right() {
    if (locationy != boundy - 1) {
      this->locationy++;
    }
  }
  void left() {
    if (locationy != 0) {
      this->locationy--;
    }
  }
  void down() {
    if (locationx != boundx - 1) {
      this->locationx++;
    }
  }
  void setboundx(unsigned xbound) { this->boundx = xbound; }
  void setboundy(unsigned ybound) { this->boundy = ybound; }

private:
  // used for moving around graph/map data structure
  int locationx;
  int locationy;
  std::string model;
  std::vector<std::string> health;
  unsigned int boundx;
  unsigned int boundy;
};