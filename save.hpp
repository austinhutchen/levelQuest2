#pragma ONCE
#include "./enemy.hpp"
#include "./player.hpp"
#include <stack>
using namespace std;
class stats {
  // write a new splitstring function, this one is messy
  // use stack to pop until valid seperator found, seperate into a vector where
  // each location is split
  public:
  void stacksplice(vector<string> spliced, string str, char delim) {
    // vector has each spliced index of string plassed into it
    // string will be pushed onto stack and popped
    // temp string for popping off stack
    string temp;
    // clear stack for use
    clear();
    int i = str.size();

    for (; i > 0; i--) {
      this->splice.push(str[i]);
    }

    while (!this->splice.empty()) {
      if (this->splice.top() == delim) {
        spliced.push_back(temp);
        temp = "";
      } else {
        temp += this->splice.top();
      }
      this->splice.pop();
    }
  }

  stats() {
    int defeated = 0;
    int health = 0;
    int level = 0;
    string character = "";
    difficulty = 0;
  }

  bool setsave(player *p) {
    ofstream file1("saves.txt");
    if (file1.fail()) {
      cout << "File could not be opened. " << endl;
      return 0;
    }
    file1 << p->getchar() << ", " << p->level() << " , " << p->rethp() << " ,"
          << inventory << " ," << difficulty << endl;
    file1.close();
    return 1;
  }

  int getsave(player *p) {
    ifstream fin;
    string line;
    fin.open("saves.txt");
    if (fin.fail()) {
      cout << "File could not be opened. " << endl;
      return -1;
    }
    fin.seekg(0, ios::beg);
    vector<string> split;
    while (getline(fin, line)) {
      split.clear();
      stacksplice(split, line, ',');
      // error testing above
      p->setchar(split[0]);
      p->setlevel(stoi(split[1]));
      p->sethp(stoi(split[2]));
      inventory = stoi(split[3]);
      difficulty = stoi(split[4]);
      fin.close();
      return 1;
    }
    fin.close();
    return -1;
  }

  int clear() {
    ofstream fout("saves.txt");
    if (fout.fail()) {
      cout << "File could not be opened. " << endl;
      return -1;
    } else {
      return 1;
    }
  }

private:
  std::stack<char> splice;
  int inventory;
  int difficulty;
};
