#pragma ONCE
#include <vector>

class player{
public:

void setchar(char input){
 this->model=input;
}
 void gethp(){

 }


private:
// used for moving around graph/map data structure
int locationx;
int locationy;
char model;
std::vector <int> health;



};