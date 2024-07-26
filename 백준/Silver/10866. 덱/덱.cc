#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
	deque<int> deque;
	int N;
	cin >> N;
	cin.ignore();

	string command;

	for (int i = 0; i < N; i++) {
		getline(cin, command);
		int val; 

		if (command == "pop_front") {
			if (deque.empty()) {
				val = -1;
				cout << val << "\n";
				continue;
			}
			cout << deque.front() << "\n";
			deque.pop_front();
		}
		else if (command == "pop_back") {
			if (deque.empty()) {
				val = -1;
				cout << val << "\n";
				continue;
			}
			cout << deque.back() << "\n";
			deque.pop_back();
		}
		else if (command == "size") {
			cout << deque.size() << "\n";
		}
		else if (command == "empty") {
			val = deque.empty() ? 1 : 0;
			cout << val << "\n";
		}
		else if (command == "front") {
			if (deque.empty()) { 
				val = -1; 
				cout << val << "\n";  
				continue; 
			}
			cout << deque.front() << "\n"; 
		}
		else if (command == "back") {
			if (deque.empty()) {  
				val = -1;  
				cout << val << "\n"; 
				continue; 
			}
			cout << deque.back() << "\n"; 
		}
		else if (command[5] == 'f') {	// push_front
			int x = stoi(command.substr(11));

			deque.push_front(x); 
		}
		else {	// push_back
			int x = stoi(command.substr(10));

			deque.push_back(x);
		}
	}

}