#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		
		vector<int> number(n);
		for (int j = 0; j < n; j++) {
			cin >> number[j];
		}

		if (n == 1) {
			cout << number[0] << "\n";
			continue;
		}

		sort(number.begin(), number.end());

		vector<int> visited(n, 0);
		visited[0] = 1;
		visited[1] = 1;

		long long int sum = 0;

		do {
			vector<int> two_num;

			for (int k = 0; k < visited.size(); k++) {
				if (visited[k]) {
					two_num.push_back(number[k]);
				}
			}

			while (two_num[1] % two_num[0] != 0) {
				int temp = two_num[0];

				two_num[0] = two_num[1] % two_num[0];
				two_num[1] = temp;
			}

			sum += two_num[0];
		} while (prev_permutation(visited.begin(), visited.end()));

		cout << sum << "\n";
	}
}