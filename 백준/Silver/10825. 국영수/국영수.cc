#include <bits/stdc++.h>
using namespace std;

struct dat {
	string name;
	int guk, young, su;
};

bool compare(dat& a, dat& b) {
	if (a.guk != b.guk)
		return a.guk > b.guk;
	if (a.young != b.young)
		return a.young < b.young;
	if (a.su != b.su)
		return a.su > b.su;
	return a.name < b.name;
}

int N;
vector<dat> arr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i].name >> arr[i].guk >> arr[i].young >> arr[i].su;
	}

	sort(arr.begin(), arr.end(), compare);
	for (auto& it : arr)
		cout << it.name << '\n';
}