#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> pick_doll;

    int row = board.size();
    int answer = 0; 
    
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < row; j++) {
            if (board[j][moves[i] - 1] == 0)
                continue;

            if (!pick_doll.empty() && pick_doll.top() == board[j][moves[i] - 1]) {
                pick_doll.pop();
                answer += 2;
            }
            else
                pick_doll.push(board[j][moves[i] - 1]);

            board[j][moves[i] - 1] = 0;
            break;
        }
    }
    
    return answer;
}