#include <iostream>
#include <vector>
#include "ttt.hpp"
//Global variable. Will store X or O for each space. Left to right, top row to bottom
std::vector<char> grid = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool win = false;

int main(){
  int turns = 1;
  //Greeting
  std::cout << "============\n";
  std::cout << "TIC-TAC-TOE\n";
  std::cout << "============\n";
  
  while (turns <= 9 && !win){
    std::cout << "Turn " << turns << "\n";
    //Display the grid
    showGrid(grid);
    //Calls function for the players turn
    playerTurn(grid, turns);
    //Checks win condition
    winCondition(grid, win);
    //Increments turns by 1 to stop an endless loop
    turns++;
  }
  showGrid(grid);
  if (!win){
    std::cout << "Draw!";
  }
}