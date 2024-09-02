#include <bits/stdc++.h>
using namespace std;

struct item {
	int weight, value;
};

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<item> backpack(n);
	vector<int> best(k+1, 0);

	for (int i = 0; i < n; i++)
		cin >> backpack[i].weight >> backpack[i].value;

	for (int i = 0; i < backpack.size(); i++) {
		int index = backpack[i].weight;
		int value = backpack[i].value;

		for (int j = k; j > index - 1; j--)
			best[j] = max(best[j], best[j - index] + value);
	}

	cout << best[k];
}