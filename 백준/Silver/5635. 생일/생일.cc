#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Name_Age {
	string name;
	int day;
	int month;
	int year;
};

int compare(const Name_Age &p, const Name_Age &q) {
	if (p.year < q.year)
		return true;
	else if (p.year > q.year)
		return false;
	else {
		if (p.month < q.month)
			return true;
		else if (p.month > q.month)
			return false;
		else {
			if (p.day < q.day)
				return true;
			else if (p.day > q.day)
				return false;
			else
				return -1;
		}
	}
}

int main()
{
	int N;

	cin >> N;
	vector<Name_Age> data(N); 
	
	for (int i = 0; i < N; i++) {
		cin >> data[i].name >> data[i].day >> data[i].month >> data[i].year;
	}

	sort(data.begin(), data.end(), compare);

	
	cout << data.back().name << endl;
	cout << data.front().name << endl;
}