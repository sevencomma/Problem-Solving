#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> sequence(N);
	vector<int> answer(N, -1);
	stack<int> index;

	for (int i = 0; i < N; i++) {
		cin >> sequence[i];
	}

	for (int i = 0; i < N; i++) {
		while (!index.empty() && sequence[index.top()] < sequence[i]) {
			answer[index.top()] = sequence[i];
			index.pop();
		}
		index.push(i);
	}

	while (!index.empty()) {
		answer[index.top()] = -1;
		index.pop();
	}

	for (int i = 0; i < N; i++) {
		cout << answer[i] << " ";
	}
}