#include <bits/stdc++.h>
using namespace std;

#define INF 1000000

struct point {
    int y, x, money, direction;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int n;

bool is_in_range(int y, int x) {
    return (y >= 0 && y < n && x >= 0 && x < n);
}

int money[25][25];

int dfs(int y, int x, vector<vector<int>> &board) {
   stack<point> q;
    // 방향 --> 1 : 가로, -1 : 세로

    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 25; j++)
            money[i][j] = INF;
    money[0][0] = 0;

    q.push({ y, x, 0, 0});

    while (!q.empty()) {
        point cur = q.top();
        q.pop();
        int temp_direction;

        for (int i = 0; i < 4; i++) {
            int cy = cur.y + dy[i];
            int cx = cur.x + dx[i];

            if (i % 2 == 0)
                temp_direction = -1; 
            else
                temp_direction = 1;

            if (!is_in_range(cy, cx) || board[cy][cx] == 1)
                continue;

            int go_money = cur.money + 100;
            if (temp_direction != cur.direction)
                go_money += 500;
            if (money[cy][cx] < go_money)
                continue;

            q.push({ cy, cx, go_money, temp_direction });
            money[cy][cx] = go_money;
        }
    }

    return money[n - 1][n - 1];
}

int solution(vector<vector<int>> board) {
    n = board.size();

    return dfs(0, 0, board) - 500;
}