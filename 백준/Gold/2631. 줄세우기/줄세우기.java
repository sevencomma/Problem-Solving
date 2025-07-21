import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        ArrayList<Integer> lis = new ArrayList<Integer>();
        lis.add(0);

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        for (int n : arr) {
            if (lis.get(lis.size() - 1) < n)
                lis.add(n);
            else {
                int idx = getInsertPosition(lis, n);
                lis.set(idx, n);
            }
        }
        System.out.println(N - lis.size() + 1);
    }

    private static int getInsertPosition(ArrayList<Integer> lis, int n) {
        int res = 0;
        while (lis.get(res) < n)
            res++;
        return res;
    }
}
