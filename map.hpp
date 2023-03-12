#pragma ONCE
#include "./player.hpp"
#include "./enemy.hpp"
class map{



public:

map(unsigned int n, unsigned int m, player* p, enemy *e){
this->rows=n;
this->columns=m;
this->p=p;
this->e=e;
this->icon="🚛";
for(int i=0;i<rows;i++){
 std::vector<std::string> dub;
 mat.push_back(dub);
 // change the icon pushed back in relation to player and enemy pointer position
 for(int k=0;k<columns;k++){
 mat[i].push_back(icon);
 }
}

}
void displaymap(){
for(int i=0;i<rows;i++){

for(int k=0;k<columns;k++){
 std::cout << mat[i][k] ;
}
std::cout << std::endl;
}

}






private:
// 2d dynamic array for building map size
std::vector<std::vector<std::string> >mat;
unsigned int columns;
unsigned int rows;
std::string icon;
player *p;
enemy *e;







};