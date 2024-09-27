import java.util.HashMap;
import java.util.Scanner;

import static java.lang.Math.max;


public class Main {


    static int[][] dp = new int[4000][4000];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        int result = 0;

        //i는 s를 돌고 j는 t를 돌면서 같다면 부분문자열임
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == t.charAt(0)) {
                dp[i][0] = 1;
            }
        }

        for(int i = 0; i < t.length(); i++) {
            if(t.charAt(i) == s.charAt(0)) {
                dp[0][i] = 1;
            }
        }

        for(int i = 1; i < s.length(); i++) {
            for(int j = 1; j < t.length(); j++) {
                if(s.charAt(i) == t.charAt(j)) {
                    dp[i][j] = dp[i-1][j-1] +1;
                    result = max(result, dp[i][j]);
;               }
            }
        }


        System.out.println(result);
    }
}