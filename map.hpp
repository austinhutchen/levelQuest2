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
for(int i=0;i<rows;i++){
 std::vector<char> dub;
 mat.push_back(dub);
 for(int k=0;k<columns;k++){
 mat[i].push_back('*');
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
std::vector<std::vector<char> >mat;
unsigned int columns;
unsigned int rows;
player *p;
enemy *e;







};