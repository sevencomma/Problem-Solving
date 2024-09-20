#include <bits/stdc++.h>
using namespace std;

int L, C;
vector<char> sequence;
vector<char> ans;
bool isused[16];

void back_tracking(int index, int cnt) {
	if (cnt == L) {
		int vowel = 0;
		for (int i = 0; i < L; i++) {
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
				vowel++;
		}
		if (vowel >= 1 && L - vowel >= 2) {
			for (int i = 0; i < L; i++)
				cout << ans[i];
			cout << "\n";
		}
		return;
	}

	for (int i = index; i < C; i++) {
		if (!isused[i]) {
			ans[cnt] = sequence[i];
			isused[i] = true;
			back_tracking(i + 1, cnt + 1);
			isused[i] = false;
		}
	}
}

int main(void) {
	cin >> L >> C;
	ans.resize(L);
	sequence.resize(C);
	for (int i = 0; i < C; i++)
		cin >> sequence[i];
	sort(sequence.begin(), sequence.end());
	back_tracking(0, 0);
}