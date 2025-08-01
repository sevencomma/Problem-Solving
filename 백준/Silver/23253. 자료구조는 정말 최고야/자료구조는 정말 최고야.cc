#include <bits/stdc++.h>
using namespace std;

int N, M, k;
int tmp[200001];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	bool res = true;

	for (int i = 0; i < M; i++) {
		cin >> k;
		for (int j = 0; j < k; j++)
			cin >> tmp[j];
		for (int j = 1; j < k; j++)
			if (tmp[j - 1] < tmp[j])
				res = false;
	}
	if (res) cout << "Yes";
	else cout << "No";
}