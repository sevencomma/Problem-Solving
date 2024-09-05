#include <bits/stdc++.h>
using namespace std;

#define MAX 1100000
bool prime[MAX];

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	for (int i = 2; i < MAX; i++)
		prime[i] = true;

	for (int i = 2; i * i < MAX; i++) {
		if (!prime[i])
			continue;
		for (int j = i * i; j < MAX; j += i)
			prime[j] = 0;
	}
	
	for (int i = N; i < MAX; i++) {
		if (!prime[i])
			continue;

		string sentence = to_string(i);
		int len = sentence.length();
		bool is_palindrome = true;
		for (int i = 0; i < len / 2; i++) {
			if (sentence[i] != sentence[len - 1 - i]) {
				is_palindrome = false;
				break;
			}
		}

		if (is_palindrome) {
			cout << i;
			break;
		}
	}
}