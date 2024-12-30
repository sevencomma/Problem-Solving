#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> d, int budget) {
    int res = 0;
    sort(d.begin(), d.end());
    for (auto& it : d) {
        if (budget < it)
            break;
        budget -= it;
        res++;
    }
    return res;
}