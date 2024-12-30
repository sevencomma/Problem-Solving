#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int res = 0, cur = w + 1, i = 0; // cur : 현재 기지국을 설치할 위치

    while (i < stations.size()) {
        if (cur >= stations[i])
            cur = stations[i] + 2 * w + 1;
        else {
            while (cur < stations[i]) {
                res++;
                cur += 2 * w + 1;
            }
            continue;
        }
        i++;
    }
    while (cur <= n + w) {
        res++;
        cur += 2 * w + 1;
    }
    return res;
}