import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M, D;
    static char[][] board;
    static char[][] temp;
    static int[] dy = {0, -1, 0};
    static int[] dx = {-1, 0, 1};

    static boolean is_in_range(int y, int x) {
        return y >= 0 && y < N && x >= 0 && x < M;
    }

    static class pos {
        int y, x, cnt;

        public pos(int y, int x, int cnt) {
            this.y = y;
            this.x = x;
            this.cnt = cnt;
        }

        @Override
        public boolean equals(Object o) {
            if (o == null || getClass() != o.getClass()) return false;
            pos pos = (pos) o;
            return y == pos.y && x == pos.x;
        }

        @Override
        public int hashCode() {
            return Objects.hash(y, x);
        }

        @Override
        public String toString() {
            return "pos{" +
                    "y=" + y +
                    ", x=" + x +
                    ", cnt=" + cnt +
                    '}';
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        board = new char[N][M];
        temp = new char[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                board[i][j] = st.nextToken().charAt(0);
            }
        }

        int res = 0;
        for (int a = 0; a < M; a++)
            for (int b = a + 1; b < M; b++)
                for (int c = b + 1; c < M; c++) {
                    res = Math.max(res, solve(a, b, c));
                }

        System.out.println(res);
    }

    // (N,a), (N,b), (N,c)에 궁수 배치
    private static int solve(int a, int b, int c) {
        for (int i = 0; i < N; i++) {
            temp[i] = board[i].clone();
        }

        int enemyCnt = getEnemyCount();
        int killCnt = 0;
        while (enemyCnt > 0) {
            killCnt += shoot(a, b, c);
            move();
            enemyCnt = getEnemyCount();
        }
        return killCnt;
    }

    private static int shoot(int a, int b, int c) {
        Set<pos> killset = new HashSet<>();

        pos A = findTarget(a);
        pos B = findTarget(b);
        pos C = findTarget(c);

        if (A != null) killset.add(A);
        if (B != null) killset.add(B);
        if (C != null) killset.add(C);

        for (pos pos : killset) {
            temp[pos.y][pos.x] = '0';
        }

        return killset.size();
    }

    private static pos findTarget(int x) {
        Deque<pos> q = new ArrayDeque<>();
        boolean[][] visited = new boolean[N][M];
        visited[N - 1][x] = true;
        q.add(new pos(N - 1, x, 1));

        while (!q.isEmpty()) {
            pos cur = q.poll();
            if (temp[cur.y][cur.x] == '1')
                return cur;

            if (cur.cnt == D) continue;

            for (int i = 0; i < 3; i++) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if (is_in_range(ny, nx) && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.add(new pos(ny, nx, cur.cnt + 1));
                }
            }
        }
        return null;
    }

    private static void move() {
        for (int j = 0; j < M; j++)
            temp[N - 1][j] = '0';

        for (int i = N - 2; i >= 0; i--)
            for (int j = 0; j < M; j++)
                temp[i + 1][j] = temp[i][j];

        for (int j = 0; j < M; j++)
            temp[0][j] = '0';
    }

    private static int getEnemyCount() {
        int res = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (temp[i][j] == '1') res++;
            }
        return res;
    }


}
