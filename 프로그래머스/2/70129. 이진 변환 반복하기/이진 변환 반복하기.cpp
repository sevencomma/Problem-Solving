#include <bits/stdc++.h>
using namespace std;

int check_length(string& s) {
    int cnt = 0;
    for (auto& it : s)
        if (it == '1')
            cnt++;
    return cnt;
}

string change_s(int n) {
    string s = "";
    int i = 1;
    while (i <= n)
        i *= 2;
    i /= 2;

    while (i != 0) {
        if (n >= i) {
            s += "1";
            n -= i;
        }
        else {
            s += "0";
        }
        i /= 2;
    }
    return s;
}
int A, B;
vector<int> solution(string s) {
    while (s != "1") {
        int len_0, len_1;
        len_1 = check_length(s);
        len_0 = s.length() - len_1;
        B += len_0;
        A++;
        s = change_s(len_1);
    }
    return { A, B };
}