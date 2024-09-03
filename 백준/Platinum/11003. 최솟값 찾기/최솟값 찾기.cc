#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, L;
	cin >> N >> L;
	vector<int> numbers(N + 1);
	for (int i = 0; i < N; i++)
		cin >> numbers[i + 1];

	typedef pair<int, int> data;
	priority_queue<data, vector<data>, greater<data>> Q;

	for (int i = 1; i <= L; i++) {
		Q.push({ numbers[i], i });

		cout << Q.top().first << " ";
	}

	for (int i = L + 1; i <= N; i++) {
		if (numbers[i-L] == Q.top().first)
			Q.pop();

		Q.push({ numbers[i], i });

		while (Q.top().second < i - L) {
			Q.pop();
		}
		cout << Q.top().first << " ";
	}
}