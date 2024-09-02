#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(void) {
	cin.tie(NULL);
    cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	
	unordered_map<int, int> hand;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		hand[num]++;
	}

	int m;
	cin >> m;
	int k;
	for (int i = 0; i < m; i++) {
		cin >> k;
		cout << hand[k] << " ";
	}
}