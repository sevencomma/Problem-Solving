#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct point {
    int y, x, count;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, m;

bool is_in_range(int y, int x) {
    return (x >= 0 && x < m && y >= 0 && y < n);
}

point find_first_position(vector<string>& maps, char ch) {
    int col;
    for (int i = 0; i < maps.size(); i++) {
        if ((col = maps[i].find(ch)) != string::npos) {
            return { i, col, 0 };
        }
    }

    return { -1, -1, -1 };
}

int bfs(vector<string>& maps, char start, char end) {
    point st = find_first_position(maps, start);

    queue<point> pos;
    bool visited[101][101] = { false };
    visited[st.y][st.x] = true;

    pos.push(st);

    while (!pos.empty()) {
        point cur = pos.front();
        pos.pop();

        if (maps[cur.y][cur.x] == end)
            return cur.count;

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (is_in_range(ny, nx) && !visited[ny][nx] && maps[ny][nx] != 'X') {
                pos.push({ ny, nx, cur.count + 1 });
                visited[ny][nx] = true;
            }
        }
    }
    return -1;
}



int solution(vector<string> maps) {
    n = maps.size();
    m = maps[0].length();

    int distanceToL = bfs(maps, 'S', 'L');
    if (distanceToL == -1)
        return -1;

    int distanceToE = bfs(maps, 'L', 'E');

    return distanceToE == -1 ? -1 : distanceToL + distanceToE;
}