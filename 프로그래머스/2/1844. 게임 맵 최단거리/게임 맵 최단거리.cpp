#include <vector>
#include <queue>

using namespace std;

struct point {
    int y, x;
    int count;
};

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int ny;
int nx;

bool within_bound(int y, int x) {
    return (y >= 0 && y < ny && x >= 0 && x < nx);
}

int bfs(vector<vector<int>> &maps, int row, int col) {
    queue<point> q;
    bool visited[101][101] = { false, };

    q.push({ row, col, 1 });
    visited[row][col] = true;

    while (!q.empty()) {
        point block = q.front();
        q.pop();

        if (block.y == (ny - 1) && block.x == (nx - 1))
            return block.count;

        for (int i = 0; i < 4; i++) {
            int cy = block.y + dy[i];
            int cx = block.x + dx[i];

            if (within_bound(cy, cx) && !visited[cy][cx] && (maps[cy][cx] == 1)) {
                q.push({ cy, cx, block.count + 1 });
                visited[cy][cx] = true;
            }
        }
    }
    return -1;
}


int solution(vector<vector<int>> maps)
{
    ny = maps.size();
    nx = maps[0].size();

    return bfs(maps, 0, 0);
}
