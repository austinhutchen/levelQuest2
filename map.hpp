#pragma ONCE
#include "./enemy.hpp"
#include "./player.hpp"
class map {

public:
  map(unsigned int n, unsigned int m, player *p, enemy *e, std::string icon) {
    this->icon = icon;
    this->rows = n;
    this->columns = m;
    this->p = p;
    this->e = e;
    this->icon = icon;
    p->setboundx(n);
    p->setboundy(m);
    e->setboundx(n);
    e->setboundy(m);
    for (int i = 0; i < rows; i++) {
      std::vector<std::string> dub;
      mat.push_back(dub);
      // change the icon pushed back in relation to player and enemy pointer
      // position
      for (int k = 0; k < columns; k++) {
        mat[i].push_back(icon);
      }
    }
  }

  void displaymap() {
    for (int i = 0; i < rows; i++) {

      for (int k = 0; k < columns; k++) {
        std::cout << mat[i][k];
      }
      std::cout << std::endl;
    }
  }
  // all info about player or enemy such as location is stored at these pointers
  // on the heap
  player *player() { return this->p; }
  enemy *enemy() { return this->e; }

  void refresh() {
    if (mat.size() == 0) {
      std::cout << "empty map" << std::endl;
      return;
    } else {
      for (int i = 0; i < rows; i++) {
        for (int k = 0; k < columns; k++) {
          mat[i][k] = this->icon;
          if (i == player()->getx()) {
            if (k == player()->gety()) {
              mat[i][k] = player()->getchar();
            }
          }
        }
      }
    }
  }

  void move() {
    char choice;
    std::cout << " Where would you like to move to?" << std::endl;
    std::cout << "USE wasd FOR UP-DOWN-LEFT-RIGHT" << std::endl;
    std::cin >> choice;
    switch (choice) {
    case 'w': {
      p->up();
      break;
    }
    case 'a': {
      p->left();
      break;
    }
    case 's': {
      p->down();
      break;
    }

    case 'd': {
      p->right();
      break;
    }

    default: {
      std::cout << "Exiting.." << std::endl;
      return;
    }
    }
  }
  // build destructor for player, enemy, and map array
  void destroy() {}

private:
  // 2d dynamic array for building map size
  // since map is stored locally, only needs to be stored once, and won't need
  // to be regenerated player will just be moved around map and replaced with
  // each call of refresh
  std::vector<std::vector<std::string> > mat;
  unsigned int columns;
  unsigned int rows;
  std::string icon;
  class player *p;
  class enemy *e;
};