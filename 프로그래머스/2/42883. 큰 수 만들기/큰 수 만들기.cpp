#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    string res = number;
    auto it = res.begin();
    
    while (k > 0) {
        if (it + 1 != res.end() && *it >= *(it + 1)) {
            it++;
        }
        else {
            res.erase(it);
            k--;
            it = res.begin();
        }
    }
    return res;
}