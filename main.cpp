
#include "./include.h"
// above is the include file for seperate libraries needed to run game
using namespace std;

void menu(player *me, enemy *they) {
  cout << "----->MAIN MENU<-----" << endl;
  cout << "1: Load save" << endl;
  cout << "2. Start" << endl;
  cout << "3. Exit" << endl;
  cout << "4. Choose character" << endl;
  short int main_choice;
  // choice is reused for choices requiring integer or character input
  char choice;
  cin >> main_choice;
  switch (main_choice) {
  case 1: {
    // file read
    cout << "not done yet" << endl;
    break;
  }

  case 2: {
    // actual game body
    cout << "How big is your map?" << endl;
    // changes the max size of nxn matrix generation
    // generate within a range modulo an upper bound for nxn matrix dimension
    cout << "PRESS (A) FOR BIG ADVENTURE" << endl;
    cout << "PRESS (B) FOR MEDIUM ADVENTURE" << endl;
    cout << "PRESS (C) FOR SMALL ADVENTURE" << endl;
    cin >> choice;
    switch (choice) {
    case 'a': {
      // large map construction
      map nmap = map(30, 30, me, they);
      nmap.displaymap();
      break;
    }
    case 'b': {
      // medium map construct
      map nmap = map(20, 20, me, they);
      nmap.displaymap();
      break;
    }
    case 'c': {
      // small map construct
      map nmap = map(10, 10, me, they);
      nmap.displaymap();
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

  case 3: {
    // choose a character
    cout << "not done yet" << endl;
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
  char choice;
  char choice2;
  enemy *evil = new enemy();
  player *you = new player();
  string main_choice;
  menu(you, evil);

  {}
}