#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct tree {
	int index;
	int orange;
};

int gcd(int a, int b) {
	while (b % a != 0) {
		int temp = a;
		a = b % a;
		b = temp;
	}
	return a;
}

unordered_map<int, vector<int>> graph;
vector<int> result;

void bfs(int start, vector<tree> & num) {
	queue<int> q;

	q.push(start);
	result.push_back(start);
	num[start].orange--;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int target = -1;
		int max_orange = 0;

		for (auto& it : graph[cur]) {
			if (max_orange <= num[it].orange && num[it].orange > 0) {
				target = it;
				max_orange = num[it].orange;
			}
		}
		if (target == -1)
			break;

		q.push(target);
		num[target].orange--;
		result.push_back(target);
	}
}

int main(void)
{
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
 
	int N;
	cin >> N;

	if (N == 1) {
		cout << 1;
		return 0;
	}

	vector<tree> num(N+1);
	vector<int> check(N, 0);

	for (int i = 1; i <= N; i++)
		num[i] = { i, 0 };
	check[0] = check[1] = 1;

	do {
		vector<int> two_n;
		for (int i = 0; i < N; i++) {
			if (check[i])
				two_n.push_back(i + 1);
		}
		if (gcd(two_n[0], two_n[1]) == 1) {
			num[two_n[1]].orange++;
			graph[two_n[0]].push_back(two_n[1]);
			graph[two_n[1]].push_back(two_n[0]);
		}
	} while (prev_permutation(check.begin(), check.end()));
	num[1].orange++;

	bfs(N, num);

	for (int i = 1; i <= N; i++)
		if (num[i].orange != 0) {
			cout << -1;
			return 0;
		}

	for (auto & it : result)
		cout << it << " ";
}
