#include <bits/stdc++.h>
using namespace std;

int N;
vector<char> arr;
bool visited[10];
string MIN = "999999999", MAX = "";
string temp;

void solve(int idx) {
	if (idx == N) {
		MIN = min(MIN, temp);
		MAX = max(MAX, temp);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (visited[i]) continue;
		if (arr[idx] == '<') {
			if (temp[idx] - '0' >= i) continue;
		}
		else {
			if (temp[idx] - '0' <= i) continue;
		}
		visited[i] = true;
		temp.push_back(i + '0');
		solve(idx + 1);
		visited[i] = false;
		temp.pop_back();
	}
}

int main(void) {
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < 10; i++) {
		temp = to_string(i);
		visited[i] = true;
		solve(0);
		visited[i] = false;
	}
	cout << MAX << '\n' << MIN;
}