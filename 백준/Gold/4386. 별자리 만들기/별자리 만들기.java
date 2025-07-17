import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static double[][] distance;

    static class edge {
        int a, b;
        double cost;

        public edge(int a, int b) {
            this.a = a;
            this.b = b;
            this.cost = distance[a][b];
        }
    }

    static class pos {
        double x, y;

        public pos(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    static class UnionFind {
        int n;
        int[] Parent;
        int[] Rank;

        public UnionFind(int n) {
            this.n = n;
            Parent = new int[n];
            Rank = new int[n];
            for (int i = 0; i < n; i++)
                Parent[i] = i;
        }

        public int find(int p) {
            if (Parent[p] != p)
                Parent[p] = find(Parent[p]);
            return Parent[p];
        }

        public void union(int p, int q) {
            link(find(p), find(q));
        }

        private void link(int p, int q) {
            if (Rank[p] > Rank[q])
                Parent[q] = p;
            else {
                Parent[p] = q;
                if (Rank[p] == Rank[q])
                    Rank[q]++;
            }
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        pos[] stars = new pos[N];
        distance = new double[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            double x = Double.parseDouble(st.nextToken());
            double y = Double.parseDouble(st.nextToken());

            stars[i] = new pos(x, y);
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < i; j++) {
                distance[i][j] = distance[j][i] = getDistance(stars[i], stars[j]);
            }

        System.out.printf("%.2f", kruskal());
    }

    static double getDistance(pos a, pos b) {
        return Math.sqrt(Math.pow((a.x - b.x), 2) + Math.pow((a.y - b.y), 2));
    }

    static double kruskal() {
        UnionFind uf = new UnionFind(N);
        PriorityQueue<edge> pq = new PriorityQueue<>(
                (a, b) -> Double.compare(a.cost, b.cost)
        );
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++) {
                pq.offer(new edge(i, j));
            }

        double res = 0;
        while (!pq.isEmpty()) {
            edge e = pq.poll();
            if (uf.find(e.a) == uf.find(e.b))
                continue;

            uf.union(e.a, e.b);
            res += e.cost;
        }

        return res;
    }
}
