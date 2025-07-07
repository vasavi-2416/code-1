#include <iostream>
#include <vector>
using namespace std;

void printBoard(const vector<char>& board) {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << "\n";
            if (i != 8) cout << "---+---+---\n";
        } else {
            cout << "|";
        }
    }
    cout << "\n";
}

bool isValidMove(const vector<char>& board, int pos) {
    return pos >= 1 && pos <= 9 && board[pos - 1] == ' ';
}

void makeMove(vector<char>& board, int pos, char player) {
    board[pos - 1] = player;
}

bool checkWin(const vector<char>& board, char player) {
    // 8 winning positions
    int wins[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, // rows
        {0,3,6}, {1,4,7}, {2,5,8}, // columns
        {0,4,8}, {2,4,6}           // diagonals
    };
    for (auto &win : wins) {
        if (board[win[0]] == player && board[win[1]] == player && board[win[2]] == player)
            return true;
    }
    return false;
}

bool isDraw(const vector<char>& board) {
    for (char c : board) {
        if (c == ' ') return false;
    }
    return true;
}

char switchPlayer(char current) {
    return (current == 'X') ? 'O' : 'X';
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";

    bool playAgain = true;
    while (playAgain) {
        vector<char> board(9, ' ');  // empty board
        char currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            printBoard(board);
            int move;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (!isValidMove(board, move)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            makeMove(board, move, currentPlayer);

            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins! Congratulations!\n";
                gameOver = true;
            } else if (isDraw(board)) {
                printBoard(board);
                cout << "Game ended in a draw!\n";
                gameOver = true;
            } else {
                currentPlayer = switchPlayer(currentPlayer);
            }
        }

        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        playAgain = (choice == 'y' || choice == 'Y');
    }

    cout << "Thanks for playing!\n";
    return 0;  
}

