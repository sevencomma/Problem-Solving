#include <bits/stdc++.h>
using namespace std;

string sen;
map<char, int> cnt;
int m;
char res;

int main(void) {
	getline(cin, sen);
	for (auto& it : sen)
		cnt[toupper(it)]++;
	for (auto& it : cnt) {
		if (it.second > m) {
			m = it.second;
			res = it.first;
		}
		else if (it.second == m)
			res = '?';
	} cout << res;
}