#include <bits/stdc++.h>
using namespace std;

string name;
vector<string> team;
int N, l, o, v, e;
int ansP = -1, ansIdx = -1;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> name >> N;
	team.resize(N);
	for (int i = 0; i < N; i++)
		cin >> team[i];

	for (auto& it : name)
		if (it == 'L')
			l++;
		else if (it == 'O')
			o++;
		else if (it == 'V')
			v++;
		else if (it == 'E')
			e++;

	sort(team.begin(), team.end());

	for (int i = 0; i < N; i++) {
		int tl = l, to = o, tv = v, te = e;
		for (auto& it : team[i])
			if (it == 'L')
				tl++;
			else if (it == 'O')
				to++;
			else if (it == 'V')
				tv++;
			else if (it == 'E')
				te++;

		int p = (((tl + to) * (tl + tv) * (tl + te) % 100) * (to + tv) * (to + te) * (tv + te)) % 100;
		if (p > ansP) {
			ansP = p;
			ansIdx = i;
		}
	}

	cout << team[ansIdx];
}