#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<int, int> kind;
vector<int> cnt;

int solution(int k, vector<int> tangerine) {
    int res = 0;
    for (auto& it : tangerine)
        kind[it]++;
    for (auto& it : kind)
        cnt.push_back(it.second);
    sort(cnt.rbegin(), cnt.rend());
    for (auto& it : cnt) {
        res++;
        k -= it;
        if (k <= 0)
            break;
    }
    return res;
}