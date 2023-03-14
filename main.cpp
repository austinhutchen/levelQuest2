
#include "./include.h"
// above is the include file for seperate libraries needed to run game
void menu(player *me, enemy *they) {
  cout << "====MAIN MENU====" << endl;
  cout << "1: New save" << endl;
  cout << "2. Load Save" << endl;
  cout << "3. Choose character" << endl;
  cout << "4. Exit" << endl;
  short int main_choice;
  // choice is reused for choices requiring integer or character input
  char choice;
  cin >> main_choice;
  switch (main_choice) {
  case 1: {
    // actual game body
    cout << "How big is your map?" << endl;
    cout << "PRESS (A) FOR BIG ADVENTURE" << endl;
    cout << "PRESS (B) FOR MEDIUM ADVENTURE" << endl;
    cout << "PRESS (C) FOR SMALL ADVENTURE" << endl;
    cin >> choice;
    switch (choice) {
    case 'a': {
      // large map construction of 2d vector on the heap
      map *nmap = new map(45, 50, me, they, "⠂");
      // MAIN GAME LOOP NOW GOES HERE WITH PLAYER OPTIONS <-----------
      int i = 0;
      // overall movement structure for game, modify loop condition for
      // turn-based movement
      while (true) {
        nmap->refresh();
        nmap->displaymap();
        nmap->move();
        i++;
      }
      break;
    }
    case 'b': {
      // medium map construct of 2d vector on heap
      map *nmap = new map(30, 35, me, they, "⠂");
      int i = 0;
      // overall movement structure for game, modify loop condition for
      // turn-based movement
      while (true) {
        nmap->refresh();
        nmap->displaymap();
        nmap->move();
        i++;
      }
      break;
    }
    case 'c': {
      // small map construct of 2d vector on heap
      map *nmap = new map(15, 20, me, they, "⠂");
      // overall movement structure for game
      int i = 0;
      // overall movement structure for game, modify loop condition for
      // turn-based movement
      while (true) {
        nmap->refresh();
        nmap->displaymap();
        nmap->move();
        i++;
      }
      // MAIN GAME LOOP NOW GOES HERE WITH PLAYER OPTIONS <-----------

      break;
    }
    default: {
      cout << "INPUT ONLY A, B, OR C. NO NUMBERS OR EXTRANEOUS CHARACTERS "
              "ALLOWED"
           << endl;
      return menu(me, they);
    }
    }
    break;
  }

  case 2: {
    // file read
    cout << "Loading.." << endl;
    cout << "not done yet" << endl;
    return menu(me, they);
    break;
  }

  case 3: {
    // choose a character
    cout << "not done yet" << endl;
    return menu(me, they);
    break;
  }

  case 4: {
    // quit
    cout << "Goodbye!" << endl;
    return;
  }

  default: {
    cout << "fix yo input dawg" << endl;
    return menu(me, they);
  }
  }
}

int main() {
  cout << "WELCOME, ADVENTURER, TO THE LONG AWAITED JOURNEY" << endl;
  cout << "[--------LVLQUEST 2.0-------]" << endl;
  enemy *evil = new enemy(10, "😡");
  player *you = new player(10, "ℸ");
  menu(you, evil);
  delete evil;
  delete you;
  evil = nullptr;
  you = nullptr;
  return 0;
}