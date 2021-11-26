#include <iostream>
#include <vector>

void showGrid(std::vector<char> grid){
  std::cout << "-------\n";
    std::cout << "|" << grid[0] << "|" << grid[1] << "|" << grid[2] << "|" << "\n";
    std::cout << "|-|-|-|\n";
    std::cout << "|" << grid[3] << "|" << grid[4] << "|" << grid[5] << "|" << "\n";
    std::cout << "|-|-|-|\n";
    std::cout << "|" << grid[6] << "|" << grid[7] << "|" << grid[8] << "|" << "\n";
    std::cout << "-------\n";
}

void playerTurn(std::vector<char> &grid, int turns){
  int square;
  bool valid = false;
  while (valid == false){
    if (turns % 2 == 0){
        std::cout << "Player 2\n";
      }
      else{
        std::cout << "Player 1\n";
      }
    std::cout << "Pick a square to place your marker: ";
    std::cin >> square;
    if (grid[square - 1] == 'X' || grid[square - 1] == 'O'){
      std::cout << "Invalid square\n";
    }
    else{
      if (turns % 2 == 0){
        grid[square - 1] = 'O';
      }
      else{
        grid[square - 1] = 'X';
      }
      //X is placed in the picked square
      valid = true;
    }
  }
}



bool winCondition(std::vector<char> grid, bool &win){
  for (int i = 0; i < grid.size(); i++){
    //Vertical
    if (i == 0 || i == 1 || i == 2){
      if (grid[i] == grid[i+3] && grid[i] == grid[i+6]){
        if(grid[i] == 'X'){
          std::cout << "Player 1 Wins!";
        }
        else{
          std::cout << "Player 2 Wins!";
        }
        return win = true;
      }
    }
    //Horizontal
    if (i == 0 || i == 3 || i == 6){
      if (grid[i] == grid[i+1] && grid[i] == grid[i+2]){
        if(grid[i] == 'X'){
          std::cout << "Player 1 Wins!";
        }
        else{
          std::cout << "Player 2 Wins!";
        }
        return win = true;
      }
    }
  }
  //Diagonal
  if (grid[0] == grid[4] && grid[0] == grid[8]){
    if(grid[0] == 'X'){
          std::cout << "Player 1 Wins!";
        }
        else{
          std::cout << "Player 2 Wins!";
        }
    return win = true;
  }
  else if(grid[2] == grid[4] && grid[2] == grid[6]){
    if(grid[0] == 'X'){
          std::cout << "Player 1 Wins!";
        }
        else{
          std::cout << "Player 2 Wins!";
        }
    return win = true;
  }
  //If there is no 3 in a row, return false
  return win = false;
}