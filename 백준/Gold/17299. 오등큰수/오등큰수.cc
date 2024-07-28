#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	unordered_map<int, int> num_count;
	vector<int> sequence(N);
	stack<int> index;
	vector<int> answer(N);

	int num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		sequence[i] = num;
		num_count[num]++;
	}

	for (int i = 0; i < N; i++) {
		while (!index.empty() && num_count[sequence[index.top()]] < num_count[sequence[i]]) {
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