import java.util.*;

class Solution {
    public int solution(int[][] routes) {
        Arrays.sort(routes, (a, b) -> Integer.compare(a[1], b[1]));
        
        int res = 1;
        int lastCheck = routes[0][1];
        
        for (int i = 1; i < routes.length; i++) {
            int start = routes[i][0];
            
            if (start > lastCheck) {
                lastCheck = routes[i][1];
                res++;
            }
        }
        return res;
    }
}