#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parents;
vector<int> rankData;

int find(int x) {
    if (parents[x] == x)
        return x;

    parents[x] = find(parents[x]);

    return parents[x];
}

void unionSet(int x, int y) {
    int root1 = find(x);
    int root2 = find(y);

    if (root1 != root2) {
        if (rankData[root1] < rankData[root2])
            parents[root1] = root2;
        else if (rankData[root2] > rankData[root2])
            parents[root2] = root1;
        else {
            parents[root2] = root1;
            rankData[root1]++;
        }
    }
}

bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    parents.resize(n);
    rankData.resize(n, 0);

    for (int i = 0; i < n; i++) {
        parents[i] = i;
    }
    int answer = 0;

    sort(costs.begin(), costs.end(), compare);
    
    for (int i = 0; i < costs.size(); i++) {
        if ((find(costs[i][0]) == find(costs[i][1])))
            continue;
        unionSet(costs[i][0], costs[i][1]);
        answer += costs[i][2];
    }

    return answer;
}