import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Math.*;

public class Main {

    static class pos {

        int y, x;

        public pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        ArrayList<pos> shark = new ArrayList<>();
        ArrayList<pos> blank = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                int tmp = Integer.parseInt(st.nextToken());
                if (tmp == 1) shark.add(new pos(i, j));
                else blank.add(new pos(i, j));
            }
        }

        int res = 0;
        for (pos b : blank) {
            int temp = Integer.MAX_VALUE;
            for (pos s : shark) {
                int distance = getDistance(b, s);
                temp = min(temp, distance);
            }
            res = max(res, temp);
        }
        System.out.println(res);
    }

    static int getDistance(pos a, pos b) {
        return min(abs(a.y - b.y), abs(a.x - b.x)) + abs((abs(a.y - b.y) - abs(a.x - b.x)));
    }
}
