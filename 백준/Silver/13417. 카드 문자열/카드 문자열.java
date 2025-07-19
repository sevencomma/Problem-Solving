import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            char[] seq = new char[st.countTokens()];
            for (int j = 0; j < N; j++) {
                seq[j] = (st.nextToken().charAt(0));
            }

            StringBuilder sb = new StringBuilder();
            sb.append(seq[0]);

            for (int j = 1; j < N; j++) {
                sb = attachSb(sb, seq[j]);
            }
            System.out.println(sb.toString());
        }

    }

    private static StringBuilder attachSb(StringBuilder sb, char c) {
        StringBuilder sb2 = new StringBuilder(sb);
        sb.insert(0, c);
        sb2.append(c);

        if (sb.compareTo(sb2) <= 0) return sb;
        else return sb2;
    }
}
