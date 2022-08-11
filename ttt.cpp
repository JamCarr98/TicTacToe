#include <iostream>
#include <vector>
#include "ttt.hpp"
//Global variable. Will store X or O for each space. Left to right, top row to bottom
using namespace std;
vector<char> grid = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
bool win = false;
//Move cout for player turns into main, turns in definition isn't needed either
int main() {
    int turns = 1;
    int mode = 0;
    //Greeting
    cout << "============\n";
    cout << "TIC-TAC-TOE\n";
    cout << "============\n";
    do {
        cout << "1. Player vs Player\n";
        cout << "2. Computer vs Player\n";
        cout << "Choose Game Mode:";
        cin >> mode;
    } while (mode != 1 && mode != 2);
    while (turns <= 9 && !win){
        cout << "------------\n";
        cout << "Turn " << turns << "\n";
        //Display the grid
        showGrid(grid);
        if (turns % 2 == 0) {
            if (mode == 1) {
                cout << "Player 2\n";
                //Calls function for the players turn
                playerTurn(grid, turns);
            }
            else {
                cout << "Computer Turn\n";
                //calls functions for the computers turn
                computerTurn(grid, turns);
            }
        }
        else {
            cout << "Player 1\n";
            //Calls function for the players turn
            playerTurn(grid, turns);
        }
        //Checks win condition
        winCondition(grid, win);
        //Increments turns by 1 to stop an endless loop
        turns++;
    }
    showGrid(grid);
    if (!win) {
        cout << "Draw!";
    }
}