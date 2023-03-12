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
}







private:

unsigned int columns;
unsigned int rows;
player *p;
enemy *e;







};