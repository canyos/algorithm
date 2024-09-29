import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

import static java.lang.Math.max;


public class Main {
    static int[][] dp = new int[501][501];//i번째 쓸지 안쓸지

    public static boolean combine(char a, char b) {
        if(a=='a' && b=='t') return true;
        if(a=='g' && b=='c') return true;
        return false;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        int result=0;

        for(int i=1;i<str.length();i++){ // 길이
            for(int j=0;j<str.length()-i;j++) {//시작
                int k=i+j; //끝
                if(combine(str.charAt(j),str.charAt(k))){
                    dp[j][k]= max(dp[j][k], dp[j+1][k-1]+2);
                }
                for(int l=j;l<k;l++){//중간
                    dp[j][k] = max(dp[j][k], dp[j][l] + dp[l+1][k]);
                }
                result = max(result ,dp[j][k]);
            }
        }

        System.out.println(result);
    }
}