import java.util.HashMap;
import java.util.Scanner;

public class Main {

    static HashMap<Long, Long> cache;
    static long N, P, Q;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextLong();
        P = scanner.nextLong();
        Q = scanner.nextLong();
        cache = new HashMap<Long, Long>();
        cache.put(0l, 1l);
        System.out.println(dp(N));
    }

    private static long dp(long n) {
        if (cache.containsKey(n))
            return cache.get(n);
        long ret = 0;
        ret = dp(n / P) + dp(n / Q);
        cache.put(n, ret);
        return ret;
    }
}
