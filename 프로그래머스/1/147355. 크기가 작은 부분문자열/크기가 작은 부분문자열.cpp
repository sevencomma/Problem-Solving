#include <bits/stdc++.h>
using namespace std;

int solution(string t, string p) {
    int cnt = 0;
    
    int N = t.size(), M = p.size();

    for (int i = 0; i <= N - M; i++) {
        string cur = t.substr(i, M);

        if (cur <= p)
            cnt++;
    }
    return cnt;
}