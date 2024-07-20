#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack {
	vector<int> stack;
public:
	void push(int n) {
		stack.push_back(n);
	}
	int pop(void) {
		if (empty())
			return -1;

		auto it = stack.back();
		stack.pop_back();
		return (it);
	}
	int size(void) {
		return stack.size();
	}
	int empty(void) {
		if (stack.size() == 0)
			return 1;
		return 0;
	}
	int top(void) {
		if (empty())
			return -1;
		return stack.back();
	}
};

int main()
{
	Stack Stack; 
	int N;
	int m;
	string command;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> command;

		if (command == "push") {
			cin >> m;
			Stack.push(m);
		}
		else if (command == "pop") {
			cout << Stack.pop() << endl;
		}
		else if (command == "size") {
			cout << Stack.size() << endl;
		}
		else if (command == "empty") {
			cout << Stack.empty() << endl;
		}
		else if (command == "top") {
			cout << Stack.top() << endl;
		}
	}
}