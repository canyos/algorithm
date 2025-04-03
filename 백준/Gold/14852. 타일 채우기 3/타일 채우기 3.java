import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static int n;
	static long dp[];
	static long sum[];
	
	
	public static void main(String[] args)throws Exception {
		dp= new long[1000001];
		sum= new long[1000001];
		n = nextInt();
		dp[0]=0;
		dp[1] = 2;
		dp[2] = 7;
		sum[0]=1;
		sum[1] = 3;
		sum[2] = 10;
		for(int i=3;i<=n;i++) {
			dp[i] = (dp[i-1]*2 + dp[i-2]*3)%1000000007 ;
			dp[i] = (dp[i] + sum[i-3] * 2)%1000000007;
			sum[i] = sum[i-1] + dp[i];
		}
		System.out.println(dp[n]);
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
