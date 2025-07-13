import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static final int MOD = 1_000_000;
    static int N;
    static int[][] cache;
    static String s;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        s = scanner.nextLine();
        N = s.length();
        cache = new int[2][N];

        for (int i = 0; i < 2; i++) {
            Arrays.fill(cache[i], -1);
        }

        int res = (dp(0, 0) + dp(1, 0)) % MOD;
        System.out.println(res);
    }

    private static int dp(int i, int n) {
        if (n == N) return 1;
        int ret = cache[i][n];
        if (ret != -1) return ret;
        ret = 0;

        if (i == 0) {
            if (s.charAt(n) == '0')
                ret = 0;
            else if (n + 1 == N)
                ret = 1;
            else
                ret = (dp(0, n + 1) + dp(1, n + 1)) % MOD;
        } else if (n + 1 < N) { // i == 1
            if (s.charAt(n) == '1') {
                if (n + 2 == N) ret = 1;
                else ret = (dp(0, n + 2) + dp(1, n + 2)) % MOD;
            } else if (s.charAt(n) == '2') {
                if (s.charAt(n + 1) <= '6') {
                    if (n + 2 == N) ret = 1;
                    else ret = (dp(0, n + 2) + dp(1, n + 2)) % MOD;
                }
            }
        }
        cache[i][n] = ret;
        return ret;
    }
}
