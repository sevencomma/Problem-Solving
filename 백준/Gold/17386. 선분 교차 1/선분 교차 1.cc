#include <bits/stdc++.h>
using namespace std;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    long long op = 1L * (b.first - a.first) * (c.second - a.second) -
        1L * (b.second - a.second) * (c.first - a.first);
    if (op > 0) return 1;    // 반시계
    if (op < 0) return -1;   // 시계
    return 0;                // 일직선
}

int main(void) {
    pair<int, int> A, B, C, D;
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> C.first >> C.second;
    cin >> D.first >> D.second;

    if (ccw(A, B, C) * ccw(A, B, D) <= 0 && ccw(C, D, A) * ccw(C, D, B) <= 0)
        cout << 1;
    else
        cout << 0;
}