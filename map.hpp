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
// all info about player or enemy such as location is stored at these pointers on the heap
player* player(){
 return this->p;
}
enemy* enemy(){
 return this->e;
}



private:
// 2d dynamic array for building map size
std::vector<std::vector<std::string> >mat;
unsigned int columns;
unsigned int rows;
std::string icon;
class player *p;
class enemy *e;







};