#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> alphabet;

    for (int i = 0; i < s.length(); i++) {
        if (!alphabet.empty() && alphabet.top() == s[i]) {
            alphabet.pop();
        }
        else {
            alphabet.push(s[i]);
        }
    }
    
    if (alphabet.empty())
        answer = 1;
    else
        answer = 0;

    return answer;
}