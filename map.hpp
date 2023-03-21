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
#pragma omp parallel for
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
#pragma omp parallel for
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
    unsigned int ex = enemy()->getx();
    unsigned int ey = enemy()->gety();
    unsigned int px = player()->getx();
    unsigned int py = player()->gety();
    if (mat.size() == 0) {
      std::cout << "empty map" << std::endl;
      return;
    } else {
#pragma omp parallel for
      for (int i = 0; i < rows; i++) {
        for (int k = 0; k < columns; k++) {
          mat[i][k] = this->icon;
          if (i == px) {
            if (k == py) {
              mat[i][k] = player()->getchar();
            }
          }
          if (i == ex) {
            if (k == ey) {
              mat[i][k] = enemy()->getchar();
            }
          }
        }
      }
    }
  }
  void clower(char s) {
    if (s >= 'A' && s <= 'Z') {
      s -= ('A' - 'a');
    }
  }

  void slower(std::string s) {
#pragma omp parallel for
    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') {
        s[i] -= ('A' - 'a');
      }
    }
  }
  void move(bool &exit) {
    char choice;
    std::cout << " Where would you like to move to?" << std::endl;
    std::cout << "USE wasd FOR UP-DOWN-LEFT-RIGHT" << std::endl;
    std::cin >> choice;
    switch (choice) {
    case 'w': {
      p->up();
      e->move();
      break;
    }
    case 'a': {
      p->left();
      e->move();
      break;
    }
    case 's': {
      p->down();
      e->move();
      break;
    }

    case 'd': {
      p->right();
      e->move();
      break;
    }

    default: {
      std::cout << "Exiting.." << std::endl;
      exit = true;
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