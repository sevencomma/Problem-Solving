// 22311963 이현철

class Solution {
    int[] ans = new int[2];
    public int[] solution(int[][] arr) {
        solve(arr, 0, 0, arr.length);
        return ans;
    }
    
    void solve(int[][] arr, int y, int x, int n) {
        boolean one = true;
        for (int i = y; i < y + n; i++) {
            for (int j = x; j < x + n; j++)
                if (arr[y][x] != arr[i][j]) {
                    one = false;
                    break;
                }
            if (!one) break;
        }
        if (one) {
            ans[arr[y][x]]++;
            return;
        }
        int m = n / 2;
        solve(arr, y, x, m);
        solve(arr, y, x + m, m);
        solve(arr, y + m, x, m);
        solve(arr, y + m, x + m, m);
    }
}