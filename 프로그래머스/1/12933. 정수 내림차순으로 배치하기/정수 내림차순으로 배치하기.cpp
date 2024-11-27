#include <bits/stdc++.h>
using namespace std;

vector<char> A;

long long solution(long long n) {
    long long answer = 0;
    string s = to_string(n);
    for (auto& it : s)
        A.push_back(it);
    sort(A.rbegin(), A.rend());
    s = "";
    for (auto & it : A)
        s += it;
    return answer = stoll(s);
}