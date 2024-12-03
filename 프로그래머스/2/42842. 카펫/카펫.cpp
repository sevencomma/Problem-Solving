#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int n = brown / 2;
    int w, h;
    for (int i = 1; i < n; i++) {
        h = i + 1, w = n - i + 1;
        if ((w - 2) * (h - 2) == yellow)
            return {w, h};
    }
    return {-1, -1};
}