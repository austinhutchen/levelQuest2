#pragma ONCE
#include <vector>
#include <iostream>

class player{
public:
player(int bound){
 std::cout << this->model << "HEALTH :" << bound << std::endl;
 for(int i=0;i<bound;i++){
 health.push_back("hp");
 }
}
void setchar(char input){
 this->model=input;
}
 void gethp(){
for(int i=0;i<health.size();i++){
 std::cout << health[i];
}
 }


private:
// used for moving around graph/map data structure
int locationx;
int locationy;
char model;
std::vector <std::string> health;



};