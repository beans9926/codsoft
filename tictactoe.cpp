#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

void printBoard(const vector<char>& board) {
	system("clear");
    cout << "\n\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
}

bool isMovePossible(const vector<char>& board, int move) {
    return board[move] == EMPTY;
}

void makeMove(vector<char>& board, char player, int move) {
    board[move] = player;
}

bool hasWon(const vector<char>& board, char player) {
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (board[i] == player && board[i + 1] == player && board[i + 2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }

    return false;
}

bool isBoardFull(const vector<char>& board) {
    for (char cell : board) {
        if (cell == EMPTY) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(0));  // Seed the random number generator

    vector<char> board(9, EMPTY);
    char currentPlayer = PLAYER_X;
    bool gameOver = false;

    while (!gameOver) {
        printBoard(board);

        int move;
        do {
            cout << "Player " << currentPlayer << ", enter your move (0-8): ";
            cin >> move;
        } while (!isMovePossible(board, move));

        makeMove(board, currentPlayer, move);

        if (hasWon(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else if (isBoardFull(board)) {
            printBoard(board);
            cout << "It's a tie!" << endl;
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
    }

    return 0;
}
