#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> sequence(N);
	for (int i = 0; i < N; i++)
		sequence[i] = i + 1;

	string prev = "";
	do {
		string temp = "";
		for (int i = 0; i < M; i++)
			temp += (to_string(sequence[i]) + " ");

		if (prev != temp) {
			cout << temp << "\n";
			prev = temp;
		}
	} while (next_permutation(sequence.begin(), sequence.end()));
}