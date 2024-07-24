#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <list>

using namespace std;

int main(void)
{
	list<char> sentence; 
	char ch;

	while (1) {
		ch = getchar();

		if (ch == '\n')
			break;

		sentence.push_back(ch);
	}

	auto it = sentence.end();

	int N;
	cin >> N;
	cin.ignore();

	string command;

	for (int i = 0; i < N; i++) {
		getline(cin, command);

		if (command == "L") {
			if (it == sentence.begin())
				continue;
			else
				advance(it, -1);
		}
		else if (command == "D") {
			if (it == sentence.end())
				continue;
			else
				advance(it, 1);
		}
		else if (command == "B") {
			if (it == sentence.begin())
				continue;
			else {
				advance(it, -1);
				it = sentence.erase(it);
			}
		}
		else {
			char ch = command[2];

			sentence.insert(it, ch);
		}
	}

	string answer = ""; 

	for (const auto& c: sentence) {
		answer += c; 
	} 

	cout << answer; 
}