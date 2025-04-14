import java.io.*;
import java.util.*;

public class Main {

    static StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

    public static void main(String[] args) throws IOException {
        Map<Integer, Integer> mod = new TreeMap<>();

        StringBuilder sb = new StringBuilder();
        int T = nextInt();
        for (int t = 0; t < T; t++) {
            int d = nextInt();
            int n = nextInt();

            mod.clear();

            int sum = 0;
            mod.put(0, 1);
            for (int i = 0; i < n; i++) {
                sum = (sum + nextInt()) % d;
                mod.put(sum, mod.getOrDefault(sum, 0) + 1);
            }

            long res = 0;
            for (int key : mod.keySet()) {
                int cnt = mod.get(key);

                res += 1L * cnt * (cnt - 1) / 2;
            }

            sb.append(res).append('\n');
        }

        System.out.print(sb);
    }

    static int nextInt() throws IOException {
        st.nextToken();
        return (int) st.nval;
    }
}
