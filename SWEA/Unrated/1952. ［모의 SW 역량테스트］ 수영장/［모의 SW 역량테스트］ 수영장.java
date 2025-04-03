import java.util.*;
import java.io.*;


public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	
	static int n;
	static int arr[];
	
	public static void main(String[] args) throws Exception {
		int tc= nextInt();
		
		for(int t=1;t<=tc;t++) {
			int answer=0;
			int day = nextInt(),month=nextInt(),month3 = nextInt(),month12 = nextInt();
			arr = new int[13];
			int dp[] = new int [13];
			for(int i=1;i<=12;i++)
				arr[i] = nextInt();
			
			for(int i=1;i<13;i++) {
				dp[i] = dp[i-1]+arr[i]*day;
				dp[i] = Math.min(dp[i], dp[i-1]+month);
				if(i>=3) {
					dp[i] = Math.min(dp[i], dp[i-3]+month3);
				}
				if(i>=12) {
					dp[i] = Math.min(dp[i], dp[i-12]+month12);
				}
			}
			
			
			bw.write("#"+ t + " "+ dp[12] + "\n");
		}
		bw.flush();
		
	}

	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
