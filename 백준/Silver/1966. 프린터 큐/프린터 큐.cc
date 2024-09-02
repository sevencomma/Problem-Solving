#include <bits/stdc++.h>
using namespace std;

struct num {
	int index, value;
};

int main(void)
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, m, cnt = 0;
		cin >> n >> m;
		vector<num> sequence(n);
		map<int, int> index;

		for (int j = 0; j < n; j++) {
			cin >> sequence[j].value;
			sequence[j].index = j;
			index[j] = sequence[j].value;
		}

		while (1) {
			int max = 0;
			int t_index;
			for (int t = 0; t < sequence.size(); t++) {
				if (max < sequence[t].value) {
					max = sequence[t].value;
					t_index = t;
				}
			}
			if (sequence[t_index].value == index[m])
				break;

			for (int j = 0; j < t_index; j++) {
				num temp = sequence[0];
				sequence.erase(sequence.begin());
				sequence.push_back(temp);
			}

			sequence.erase(sequence.begin());
			cnt++;
		}

		for (int k = 0; k < sequence.size(); k++) {
			if (sequence[k].value != index[m])
				continue;
			cnt++;
			if (sequence[k].index == m)
				break;
		}
		cout << cnt << "\n";
	}
}