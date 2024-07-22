#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Check {
public:
	int index;
	int num;
	bool check;
};

bool compare_num(const Check& a, const Check& b)
{
	return a.num < b.num;
}

bool compare_index(const Check& a, const Check& b)
{
	return a.index < b.index;
}

int main()
{
	int N, M;

	cin >> N;
	vector<int> save_number(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &save_number[i]);
	}

	cin >> M;
	vector<Check> check_number(M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &check_number[i].num);
		check_number[i].check = false; 
		check_number[i].index = i;
	}

	sort(save_number.begin(), save_number.end());
	sort(check_number.begin(), check_number.end(), compare_num);

	for (int i = 0, j = 0; (i + j) < save_number.size() + check_number.size(); ) {
		if (i >= save_number.size() || j >= check_number.size())
			break;

		if (save_number[i] == check_number[j].num) {
			check_number[j].check = true;
			j++;
		}
		else if (save_number[i] < check_number[j].num) {
			i++;
		}
		else {
			j++;
		}
	}

	sort(check_number.begin(), check_number.end(), compare_index);

	for (int i = 0; i < check_number.size(); i++)
		printf("%d\n", check_number[i].check ? 1 : 0);
	
}