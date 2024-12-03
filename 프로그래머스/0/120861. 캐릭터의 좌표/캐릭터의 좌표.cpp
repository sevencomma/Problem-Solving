#include <bits/stdc++.h>
using namespace std;
int x,y;
vector<int> solution(vector<string> keyinput, vector<int> board) {
    int x_max = board[0] / 2;
    int y_max = board[1] / 2;
    
    for (auto & it : keyinput) {
        if (it == "up")
            y++;
        else if (it == "down")
            y--;
        else if (it == "left")
            x--;
        else
            x++;
        
        if (x > x_max)
            x = x_max;
        else if (x < -x_max)
            x = -x_max;
        if (y > y_max)
            y = y_max;
        else if (y < -y_max)
            y = -y_max;
    }
    return {x, y};
}