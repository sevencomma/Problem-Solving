#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct card {
	int index;
	int number;
	int has;
};

bool compare_index(const card a, const card b) {
	return a.index < b.index;
}

bool compare_number(const card a, const card b) {
	return a.number < b.number;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;

	vector<int> own_card(N);
	for (int i = 0; i < N; i++)
		cin >> own_card[i];

	cin >> M;
	vector<card> check_has_card(M);
	for (int i = 0; i < M; i++) {
		cin >> check_has_card[i].number;
		check_has_card[i].index = i;
		check_has_card[i].has = 0;
	}

	sort(own_card.begin(), own_card.end());
	sort(check_has_card.begin(), check_has_card.end(), compare_number);

	int i = 0, j = 0;
	while (i < N && j < M) {
		if (own_card[i] > check_has_card[j].number) {
			j++;
		}
		else if (own_card[i] == check_has_card[j].number) {
			check_has_card[j].has = 1;
			j++;
		}
		else {
			i++;
		}
	}

	sort(check_has_card.begin(), check_has_card.end(), compare_index);
	for (auto& it : check_has_card)
		cout << it.has << " ";
}