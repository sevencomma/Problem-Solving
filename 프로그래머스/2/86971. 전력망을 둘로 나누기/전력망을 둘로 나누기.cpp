#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool visited[101] = { false };

int bfs(int start, unordered_map<int, vector<int>>& graph)
{
    int count = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        count++;
        for (auto& it : graph[temp]) {
            if (visited[it])
                continue;

            q.push(it);
            visited[it] = true;
        }
    }

    return count;
}

int solution(int n, vector<vector<int>> wires) {
    unordered_map<int, vector<int>> graph;

    for (int i = 0; i < n; i++)
        graph[i + 1] = {};

    for (auto& it : wires) {
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }

    vector<double> result;

    for (auto& it : wires) {
        for (int i = 0; i < 101; i++)
            visited[i] = false;
        visited[it[1]] = true;
        result.push_back(bfs(it[0], graph));

        for (int i = 0; i < 101; i++)
            visited[i] = false;
        visited[it[0]] = true;
        result.push_back(bfs(it[1], graph));
    }

    for (int i = 0; i < result.size(); i++)
        result[i] = abs(result[i] - (double)(n) / 2);

    sort(result.begin(), result.end());

    return result[0] * 2;
}

int main(void)
{
    cout << solution(9, { {1, 3},{2, 3},{3, 4},{4, 5},{4, 6},{4, 7},{7, 8},{7, 9} }) << endl;
    cout << solution(7, { {1, 2},{2, 7},{3, 7},{3, 4},{4, 5},{6, 7} });
}