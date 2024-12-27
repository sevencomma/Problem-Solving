#include <bits/stdc++.h>
using namespace std;
int res, temp;
int solution(vector<vector<int>> board)
{
    int row = board.size();
    int col = board[0].size();
    
    for (int i = 1; i < row; i++)
        for (int j = 1; j < col; j++) {
            if (!board[i-1][j-1] || !board[i][j])
                continue;
            temp = min(board[i-1][j-1], min(board[i-1][j], board[i][j-1]));
            if (board[i-1][j-1] >= temp && board[i-1][j] >= temp && board[i][j-1] >= temp)
                board[i][j] = temp + 1;
        }
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            res = max(res, board[i][j]);
    return pow(res, 2);
}