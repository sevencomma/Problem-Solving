#include <bits/stdc++.h>
using namespace std;

bool compare(string& a, string& b) {
    return a + b < b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> A;
    for (auto& it : numbers)
        A.push_back(to_string(it));
    sort(A.rbegin(), A.rend(), compare);
    for (auto& it : A)
        answer += it;
    if (answer[0] == '0')
        return "0";
    return answer;
}