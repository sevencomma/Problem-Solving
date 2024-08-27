#include <vector>

using namespace std;

int node[200];

int find_(int x) {
    if (x == node[x])
        return x;

    return find_(node[x]);
}

void union_(int i, int j) {
    int x = find_(i);
    int y = find_(j);

    node[y] = x;
}

int solution(int n, vector<vector<int>> computers) {

    int answer = 0;

    for (int i = 0; i < computers.size(); i++) {
        node[i] = i;
    }

    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[0].size(); j++) {
            if (i == j)
                break;

            if (computers[i][j] == 1) {
                union_(i, j);
            }
        }
    }

    for (int i = 0; i < computers.size(); i++)
        if (node[i] == i)
            answer++;

    return answer;
}