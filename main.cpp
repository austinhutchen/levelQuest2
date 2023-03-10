#include "./include.h"
#include "./enemy.hpp"
#include "./player.hpp"
#include "./algo.hpp"
// above is the include file for seperate libraries needed to run game
#include <cstdint>
#include <iostream>
using namespace std;

void menu(player *p, enemy*e){
cout << "----->MAIN MENU<-----" << endl;
  cout << "1: Load save" << endl;
  cout << "2. Start" << endl;
  cout << "3: Choose character" << endl;
  cout << "4: Item shop " << endl;
  cout << "5: Change map size " << endl;
  cout << "6. Set difficulty " << endl;
  cout << "7: Quit " << endl;
short int main_choice;
// choice is reused for choices requiring integer or character input
char choice;
  cin >> main_choice;
  switch (main_choice){
   case 1:{
   // file read

   }

   case 2:{
// actual game body
cout << "How big is your map?" <<endl;
cout << "PRESS (A) FOR BIG ADVENTURE" <<endl;
cout << "PRESS (B) FOR MEDIUM ADVENTURE" <<endl;
cout << "PRESS (C) FOR SMALL ADVENTURE" <<endl;
cin >> choice;

   }



   case 3:{
// choose a character


   }

   case 4:{
// quit
cout << "Goodbye!" << endl;
return;
   }

   default:{
    cout << "fix yo input dawg" <<endl;
   return menu(p,e);
   }
  }
}

int main(){
cout << "WELCOME, ADVENTURER, TO THE LONG AWAITED JOURNEY" <<endl;
cout << "[--------LVLQUEST 2.0-------]" <<endl;
char choice;
char choice2;
enemy *evil = new enemy();
player *you = new player();
string main_choice;
menu(you,evil);


  {




}}