#include <bits/stdc++.h>
using namespace std;

struct point {
    int y, x;
};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int N, M, ans = INT_MAX;
point rs, rt, bs, bt;
int board[4][4];
bool rVisited[4][4];
bool bVisited[4][4];

bool is_in_range(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M;
}

void dfs(point r, point b, int turn) {
    if (r.y == rt.y && r.x == rt.x &&
        b.y == bt.y && b.x == bt.x) {
        ans = min(ans, turn);
        return;
    }
    if (turn > ans) return;
    
    // r도착
    if (r.y == rt.y && r.x == rt.x) {
        for (int i = 0; i < 4; i++) {
            int nyB = b.y + dy[i];
            int nxB = b.x + dx[i];
            
            if (!is_in_range(nyB, nxB) ||
                bVisited[nyB][nxB] ||
                board[nyB][nxB] == 5 ||
                (nyB == r.y && nxB == r.x)
               ) continue;
            
            bVisited[nyB][nxB] = true;
            dfs(r, {nyB, nxB}, turn + 1);
            bVisited[nyB][nxB] = false;
        }
        return;
    }
     
    // b도착
    if (b.y == bt.y && b.x == bt.x) {
        for (int i = 0; i < 4; i++) {
            int nyR = r.y + dy[i];
            int nxR = r.x + dx[i];
            
            if (!is_in_range(nyR, nxR) ||
                rVisited[nyR][nxR] ||
                board[nyR][nxR] == 5 ||
                (nyR == b.y && nxR == b.x)
               ) continue;
            
            rVisited[nyR][nxR] = true;
            dfs({nyR, nxR}, b, turn + 1);
            rVisited[nyR][nxR] = false;
        }
        return;
    }
    
    // 둘다 움직여
    for (int i = 0; i < 4; i++) {
        int nyR = r.y + dy[i];
        int nxR = r.x + dx[i];
        
        if (!is_in_range(nyR, nxR) ||
            rVisited[nyR][nxR] ||
            board[nyR][nxR] == 5 ||
            (nyR == b.y && nxR == b.x)
           ) continue;
        
        for (int j = 0; j < 4; j++) {
            int nyB = b.y + dy[j];
            int nxB = b.x + dx[j];
            
            if (!is_in_range(nyB, nxB) ||
                bVisited[nyB][nxB] ||
                board[nyB][nxB] == 5 ||
                (nyB == nyR && nxB == nxR)
               ) continue;
            
            rVisited[nyR][nxR] = true;
            bVisited[nyB][nxB] = true;
            dfs({nyR, nxR}, {nyB, nxB}, turn + 1);
            rVisited[nyR][nxR] = false;
            bVisited[nyB][nxB] = false;
        }
    }
    
    // 둘다 움직여
    for (int i = 0; i < 4; i++) {
        int nyB = b.y + dy[i];
        int nxB = b.x + dx[i];
        
        if (!is_in_range(nyB, nxB) ||
            bVisited[nyB][nxB] ||
            board[nyB][nxB] == 5 ||
            (nyB == r.y && nxB == r.x)
           ) continue;
        
        for (int j = 0; j < 4; j++) {
            int nyR = r.y + dy[j];
            int nxR = r.x + dx[j];
            
            if (!is_in_range(nyR, nxR) ||
                rVisited[nyR][nxR] ||
                board[nyR][nxR] == 5 ||
                (nyR == nyB && nxR == nxB)
               ) continue;
            
            rVisited[nyR][nxR] = true;
            bVisited[nyB][nxB] = true;
            dfs({nyR, nxR}, {nyB, nxB}, turn + 1);
            rVisited[nyR][nxR] = false;
            bVisited[nyB][nxB] = false;
        }
    }
}

int solution(vector<vector<int>> maze) {
    N = maze.size();
    M = maze[0].size();
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            board[i][j] = maze[i][j];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (maze[i][j] == 1)
                rs = {i, j};
            else if (maze[i][j] == 2)
                bs = {i, j};
            else if (maze[i][j] == 3)
                rt = {i, j};
            else if (maze[i][j] == 4)
                bt = {i, j};
        }
    
    board[rs.y][rs.x] = 0;
    board[bs.y][bs.x] = 0;
    rVisited[rs.y][rs.x] = true;
    bVisited[bs.y][bs.x] = true;
    
    dfs(rs, bs, 0);
    if (ans == INT_MAX)
        return 0;
    return ans;
}