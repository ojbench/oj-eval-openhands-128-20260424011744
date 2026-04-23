
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkWin(const vector<string>& board, char c) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
        if (board[0][i] == c && board[1][i] == c && board[2][i] == c) return true;
    }
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
    if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
    return false;
}

int main() {
    vector<string> board(3);
    int nx = 0, no = 0;
    for (int i = 0; i < 3; ++i) {
        if (!(cin >> board[i])) break;
        for (char c : board[i]) {
            if (c == 'x') nx++;
            else if (c == 'o') no++;
        }
    }

    bool xWin = checkWin(board, 'x');
    bool oWin = checkWin(board, 'o');

    if (nx < no || nx > no + 1) {
        cout << "invalid" << endl;
        return 0;
    }

    if (xWin && oWin) {
        cout << "invalid" << endl;
        return 0;
    }

    if (xWin) {
        if (nx != no + 1) {
            cout << "invalid" << endl;
        } else {
            bool possible = false;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (board[i][j] == 'x') {
                        board[i][j] = '-';
                        if (!checkWin(board, 'x')) possible = true;
                        board[i][j] = 'x';
                    }
                }
            }
            if (possible) cout << "win" << endl;
            else cout << "invalid" << endl;
        }
        return 0;
    }

    if (oWin) {
        if (nx != no) {
            cout << "invalid" << endl;
        } else {
            bool possible = false;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (board[i][j] == 'o') {
                        board[i][j] = '-';
                        if (!checkWin(board, 'o')) possible = true;
                        board[i][j] = 'o';
                    }
                }
            }
            if (possible) cout << "lose" << endl;
            else cout << "invalid" << endl;
        }
        return 0;
    }

    if (nx + no == 9) {
        cout << "tie" << endl;
    } else {
        cout << "ongoing" << endl;
    }

    return 0;
}
