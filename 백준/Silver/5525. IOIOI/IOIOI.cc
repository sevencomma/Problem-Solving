#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;
	cin.ignore();

	string sentence;
	getline(cin, sentence);


	int answer = 0;
	for (int i = 0; i < M; i++) {
		if (sentence[i] == 'O')
			continue;

		int count = 0;
		while (i + 2 < M && sentence[i] == 'I' && sentence[i+1] == 'O' && sentence[i+2] == 'I') {
			count++;
			i += 2;
		}
		if (count >= N) {
			answer += count - N + 1;
			if (sentence[i] != 'I')
				answer--;
		}
	}
	cout << answer;
}