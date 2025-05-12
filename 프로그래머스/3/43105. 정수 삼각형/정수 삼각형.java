class Solution {
    public int solution(int[][] triangle) {
        int N = triangle.length;
        int[][] cache = new int[N][N];
        cache[0][0] = triangle[0][0];
        
        for (int i = 0; i < N - 1; i++)
            for (int j = 0; j <= i; j++) {
                cache[i + 1][j] = max(cache[i + 1][j], 
                                      cache[i][j] + triangle[i + 1][j]);
                cache[i + 1][j + 1] = max(cache[i + 1][j + 1], 
                                          cache[i][j] + triangle[i + 1][j + 1]);
            }
        
        int res = 0;
        for (int j = 0; j < N; j++)
            res = max(res, cache[N - 1][j]);
        return res;
    }
    
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
}