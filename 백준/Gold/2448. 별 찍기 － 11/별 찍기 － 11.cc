#include <bits/stdc++.h>
using namespace std;

int N;
char board[6146][6146]; // 충분히 크게 선언

void draw(int y, int x, int size) {
    if (size == 3) {
        board[y][x] = '*';
        board[y+1][x-1] = '*';
        board[y+1][x+1] = '*';
        for (int i = -2; i <= 2; ++i) board[y+2][x+i] = '*';
        return;
    }
    int half = size / 2;
    draw(y, x, half);
    draw(y+half, x-half, half);
    draw(y+half, x+half, half);
}

int main(void) {
    cin >> N;
    memset(board, ' ', sizeof(board));
    draw(0, N-1, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2*N-1; ++j)
            cout << board[i][j];
        cout << '\n';
    }
}