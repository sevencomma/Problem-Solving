#include <bits/stdc++.h>
using namespace std;
/*
1. 각 좌표들에 bfs돌리면서 연결요소로 분할한 다음
2. 각 연결요소를 노드로 하는 새로운 그래프생성
3. 그 그래프에서 최소신장 트리 생성비용--> 답
*/

int N, H;

// 1. 
struct point {
    int y, x;
};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

bool visited[301][301];
int LAND[301][301];
int land_kind;

bool is_in_range(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < N;
}

void bfs(int y, int x, vector<vector<int>> & land) {
    if (visited[y][x])
        return;
    queue<point> q;
    q.push({y, x});
    visited[y][x] = true;
    ++land_kind;
    
    while (!q.empty()) {
        point cur = q.front();
        q.pop();
        
        LAND[cur.y][cur.x] = land_kind;
        
        for (int i = 0; i < 4; i++) {
            int cy = cur.y + dy[i];
            int cx = cur.x + dx[i];
            
            if (is_in_range(cy, cx) && !visited[cy][cx] && 
                abs(land[cur.y][cur.x] - land[cy][cx]) <= H) {
                q.push({cy, cx});
                visited[cy][cx] = true;
            }
        }
    }
}

// 2.
struct edge {
    int node1, node2, weight;
};

struct cmp {
    bool operator() (const edge& a, const edge& b) const {
        return a.weight > b.weight;
    }
};

// 3.
priority_queue<edge, vector<edge>, cmp> pq;
int Parent[90002];
int Rank[90002];

void Link(int x, int y) {
    if (Rank[x] > Rank[y])
        Parent[y] = x;
    else {
        Parent[x] = y;
        if (Rank[x] == Rank[y])
            Rank[y] = Rank[x] + 1;
    }
}

int Find(int x) {
    if (Parent[x] != x)
        Parent[x] = Find(Parent[x]);
    return Parent[x];
}

void Union(int x, int y) {
    Link(Find(x), Find(y));
}

int kruskal() {
    int res = 0;
    
    while (!pq.empty()) {
        edge cur = pq.top();
        pq.pop();
        
        if (Find(cur.node1) == Find(cur.node2))
            continue;
        
        Union(cur.node1, cur.node2);
        res += cur.weight;
    }
    
    return res;
}

int solution(vector<vector<int>> land, int height) {
    N = land.size();
    H = height;
    // 1. 각 좌표 연결요소로 분할
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            bfs(i, j, land);
    
    // 2. 로운 그래프의 간선 정보
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < 2; k++) {
                int cy = i + dy[k];
                int cx = j + dx[k];
                
                if (!is_in_range(cy, cx))
                    continue;
                int cur = LAND[i][j];
                int next = LAND[cy][cx];
                if (cur == next)
                    continue;
                
                int weight = abs(land[i][j] - land[cy][cx]);
                pq.push({cur, next, weight});
            }
    
    // 3. 최소신장트리
    for (int i = 1; i <= land_kind; i++)
        Parent[i] = i;
    
    return kruskal();
}
