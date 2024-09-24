#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cout.tie(NULL);
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	cin.ignore();

	for (int i = 0; i < T; i++) {
		string cmd, sequence;
		int n;
		deque<string> nums;
		getline(cin, cmd);
		cin >> n;
		cin.ignore();
		getline(cin, sequence);
		sequence.erase(sequence.find("["), 1);
		sequence.erase(sequence.find("]"), 1);
		string token = "";
		for (int k = 0; k < sequence.size(); k++) {
			if (sequence[k] != ',')
				token += sequence[k];
			else {
				nums.push_back(token);
				token = "";
			}
		} 
		if (token != "")
			nums.push_back(token);
		bool direct = true;
		int first = 0, last = nums.size();
		for (auto& it : cmd) {
			if (it == 'D') {
				if (direct)
					first++;
				else
					last--;
			}
			else
				direct = !direct;
		}
		if (first < last) {
			if (direct) {
				cout << '[' << nums[first];
				for (int index = first + 1; index < last; index++)
					cout << ',' << nums[index];
				cout << "]\n";
			}
			else {
				cout << '[';
				for (int index = last - 1; index > first; index--)
					cout << nums[index] << ',';
				cout << nums[first] << "]\n";
			}
		}
		else if (first == last)
			cout << "[]\n";
		else
			cout << "error\n";
	}
}