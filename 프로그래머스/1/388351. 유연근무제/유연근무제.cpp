#include <bits/stdc++.h>
using namespace std;

bool isOk(int staff, int target) {
    int a = staff / 100;
    int b = staff % 100;
    
    int c = target / 100;
    int d = target % 100;
    
    if (a * 60 + b <= c * 60 + d + 10)
        return true;
    return false;
}


int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    // [idx + (7 - startday)] % 7 + 1 ==> 6 or 7 ==> pass
    
    int res = 0;
    int N = schedules.size();
    
    for (int i = 0; i < N; i++) {
        bool can = true;
        for (int j = 0; j < 7; j++) {
            int day = (j + startday - 1) % 7;
            if (day == 5 || day == 6) continue;
            
            if (!isOk(timelogs[i][j], schedules[i]))
                can = false;
        }
        if (can) res++;
    }
    return res;
}