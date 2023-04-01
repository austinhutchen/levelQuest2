#pragma ONCE
#include <iostream>
#include <vector>
class player {
public:
  player(int bound, std::string model) {
    lvl=0;
    hp=0;
    this->locationx = 0;
    this->locationy = 0;
    setchar(model);
    for (int i = 0; i < bound; i++) {
      health.push_back("❤️");
    }
    std::cout << std::endl;
  }
 void sethp(short unsigned nhp){
 this->hp=nhp;
 return;
 }
  void setchar(std::string input) { this->model = input; }

  void gethp() {
       #pragma omp parallel for
    std::cout << this->model << "HEALTH :" << std::endl;
    for (int i = 0; i < health.size(); i++) {
      std::cout << health[i];
    }
    hp=health.size();
    std::cout << std::endl;
  }
 short unsigned rethp(){
  // 7 IS MAX HP VALUE, ENSURE VECTOR DOES NOT GET GREATER THAN 7
  return  this->hp;
 }
  unsigned int getx() { return locationx; }
  unsigned int gety() { return locationy; }
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
  void levelup(){
  lvl++;
  }
  unsigned short level(){
    return this->lvl;
  }
  //for FILE I/O
  void setlevel(short unsigned nlvl){
  this->lvl=nlvl;
  return;
  }
private:
  // used for moving around graph/map data structure
  short unsigned lvl;
  unsigned int locationx;
  unsigned int locationy;
  std::string model;
  std::vector<std::string> health;
  short unsigned hp;
  unsigned int boundx;
  unsigned int boundy;
};