#include <string>
#include <vector>
using namespace std;

bool is_same_row(int placed_row, int cur_row) {
    return placed_row == cur_row;
}

bool is_diagonal(int placed_col, int placed_row, int cur_col, int cur_row) {
    return abs(placed_col - cur_col) == abs(placed_row - cur_row);
}

bool is_safe(const vector<int>& queen, int col, int row) {
    for (int i = 0; i < col; i++)
        if (is_same_row(queen[i], row) || is_diagonal(i, queen[i], col, row))
            return false;
    return true;
}

long long place_queens(vector<int>& queen, int col) {
    int n = queen.size();
    if (col == n)
        return 1;

    long long count = 0;
    for (int row = 0; row < n; row++) {
        if (is_safe(queen, col, row)) {
            queen[col] = row;
            count += place_queens(queen, col + 1);
            queen[col] = -1;
        }
    }
    return count;
}

int solution(int n) {
    vector<int> queen(n, -1);
    return place_queens(queen, 0);
}