#include <bits/stdc++.h>
using namespace std;

int N;
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++)
			cout << ' ';
		for (int j = 0; j < 2 * (N - i) - 1; j++)
			cout << '*';
		cout << '\n';
	}
	for (int i = 1; i < N; i++) {
		for (int j = i; j < N - 1; j++)
			cout << ' ';
		for (int j = 0; j < 2 * (1 + i) - 1; j++)
			cout << '*';
		cout << '\n';
	}
}