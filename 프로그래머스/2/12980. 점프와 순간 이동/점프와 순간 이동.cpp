#include <bits/stdc++.h>
using namespace std;
int cnt;
int solution(int n)
{
    while (n) {
        if (n % 2) {
            n--;
            cnt++;
        }
        else
            n /= 2;
    }
    return cnt;
}