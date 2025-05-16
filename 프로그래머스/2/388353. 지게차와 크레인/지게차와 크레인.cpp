#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
int N, M;
vector<string> board;
set<pair<int, int>> sharp;

bool is_in_range(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M;
}

// alphabet : 컨테이너, '0' : 외부와 연결된 빈공간, '#' : 외부와 연결되지 않은 빈공간

void sharpBFS(int y, int x) {
    if (board[y][x] != '#') return;
    queue<pair<int, int>> q;
    q.push({y, x});
    
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        board[cur.first][cur.second] = '0';
        
        for (int i = 0; i < 4; i++) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (board[ny][nx] == '#')
                q.push({ny, nx});
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    N = storage.size();
    M = storage[0].size();
    board = storage;
    
    for (auto& q : requests) {
        // all
        if (q.size() == 2) {
            char target = q[0];
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++) {
                    if (board[i][j] != target || 
                        board[i][j] == '0' || board[i][j] == '#') continue;
                    board[i][j] = '#';
                    
                    for (int k = 0; k < 4; k++) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (!is_in_range(ny, nx) || board[ny][nx] == '0') {
                            board[i][j] = '0';
                            break;
                        }
                    }
                    if (board[i][j] == '#') {
                        sharp.insert({i, j});
                    }
                }
        }
        // edge
        else {
            char target = q[0];
            vector<pair<int, int>> Rlist;
            
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++) {
                    if (board[i][j] != target || 
                        board[i][j] == '0' || board[i][j] == '#') continue;
                    
                    for (int k = 0; k < 4; k++) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        
                        if (!is_in_range(ny, nx) || board[ny][nx] == '0') {
                            Rlist.push_back({i, j});
                            break;
                        }
                    }
                }
            
            for (auto& it: Rlist)
                board[it.first][it.second] = '0';
        }
        
        for (auto& it : sharp) {
            if (board[it.first][it.second] == '0') continue;
            for (int i = 0; i < 4; i++) {
                int ny = it.first + dy[i];
                int nx = it.second + dx[i];
                
                if (board[ny][nx] == '0') {
                    sharpBFS(it.first, it.second);
                }
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j] >= 'A' && board[i][j] <= 'Z')
                res++;
    
    return res;
}