#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

#define INF 1000000

struct edge {
    int node;
    int weight;
};

unordered_map<int, vector<edge>> graph;
int min_weight[51];

void bfs(int start) {
    for (int i = 0; i < 51; i++)
        min_weight[i] = INF;

    min_weight[start] = 0;
    queue<int> q;

    q.push(start);

    while (!q.empty()) {
        int temp = q.front();
        q.pop();

        for (auto& it : graph[temp]) {
            if ((min_weight[it.node] > (min_weight[temp] + it.weight))) {
                q.push(it.node);
                min_weight[it.node] = min_weight[temp] + it.weight;
            }
        }

    }
}


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for (auto & it : road) {
        graph[it[0]].push_back({ it[1], it[2] });
        graph[it[1]].push_back({ it[0], it[2] });
    }

    bfs(1);

    for (int i = 1; i <= N; i++) {
        if (min_weight[i] <= K)
            answer++;
    }

    return answer;
}