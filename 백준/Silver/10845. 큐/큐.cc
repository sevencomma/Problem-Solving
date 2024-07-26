#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(void)
{
	queue<int> queue;
	int N;
	cin >> N;
	cin.ignore();

	string command; 

	for (int i = 0; i < N; i++) {
		getline(cin, command);
		int val;

		if (command == "pop") { 
			if (queue.empty()) { 
				val = -1;
				cout << val << "\n";
				continue;
			}
			cout << queue.front() << "\n";
			queue.pop();
		}
		else if (command == "size") {
			cout << queue.size() << "\n";
		}
		else if (command == "empty") {
			val = queue.empty() ? 1 : 0;
			cout << val << "\n";
		}
		else if (command == "front") {
			if (queue.empty()) {
				val = -1;
				cout << val << "\n";
				continue;
			}
			cout << queue.front() << "\n";
		}
		else if (command == "back") {
			if (queue.empty()) {
				val = -1;
				cout << val << "\n";
				continue;
			}
			cout << queue.back() << "\n";
		}
		else { // push
			int x = stoi(command.substr(5));

			queue.push(x);
		}
	}

}