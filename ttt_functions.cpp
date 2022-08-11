#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
void showGrid(std::vector<char> grid) {
    cout << "-------\n";
    cout << "|" << grid[0] << "|" << grid[1] << "|" << grid[2] << "|" << "\n";
    cout << "|-|-|-|\n";
    cout << "|" << grid[3] << "|" << grid[4] << "|" << grid[5] << "|" << "\n";
    cout << "|-|-|-|\n";
    cout << "|" << grid[6] << "|" << grid[7] << "|" << grid[8] << "|" << "\n";
    cout << "-------\n";
}

void playerTurn(std::vector<char>& grid, int turns) {
    int square;
    bool valid = false;
    while (valid == false) {
        cout << "Pick a square to place your marker: ";
        cin >> square;
        while (square > 9 || square < 1) {
            cout << "Number is out of range!\n";
            cout << "Pick a square to place your marker: ";
            cin >> square;
        }
        if (grid[square - 1] == 'X' || grid[square - 1] == 'O') {
            cout << "Invalid square\n";
        }
        else {
            if (turns % 2 == 0) {
                grid[square - 1] = 'O';
            }
            else {
                grid[square - 1] = 'X';
            }
            //X is placed in the picked square
            valid = true;
        }
    }
}

void computerTurn(std::vector<char>& grid, int turns) {
    //check the corresponding grid number if in use, create a new number
    //repeat until valid move
    srand(time(NULL));
    int square;
    bool valid = false;
    while (valid == false) {
        square = rand() % 9;
        if (grid[square] == 'X' || grid[square] == 'O'){
            valid = false;
        }
        else {
            grid[square] = 'O';
            valid = true;
        }
    }
}

bool winCondition(std::vector<char> grid, bool& win) {
    for (int i = 0; i < grid.size(); i++) {
        //Vertical
        if (i == 0 || i == 1 || i == 2) {
            if (grid[i] == grid[i + 3] && grid[i] == grid[i + 6]) {
                if (grid[i] == 'X') {
                    cout << "Player 1 Wins!";
                }
                else {
                    cout << "Player 2 Wins!";
                }
                return win = true;
            }
        }
        //Horizontal
        if (i == 0 || i == 3 || i == 6) {
            if (grid[i] == grid[i + 1] && grid[i] == grid[i + 2]) {
                if (grid[i] == 'X') {
                    cout << "Player 1 Wins!";
                }
                else {
                    cout << "Player 2 Wins!";
                }
                return win = true;
            }
        }
    }
    //Diagonal
    if (grid[0] == grid[4] && grid[0] == grid[8]) {
        if (grid[0] == 'X') {
            cout << "Player 1 Wins!";
        }
        else {
            cout << "Player 2 Wins!";
        }
        return win = true;
    }
    else if (grid[2] == grid[4] && grid[2] == grid[6]) {
        if (grid[0] == 'X') {
            cout << "Player 1 Wins!";
        }
        else {
            cout << "Player 2 Wins!";
        }
        return win = true;
    }
    //If there is no 3 in a row, return false
    return win = false;
}