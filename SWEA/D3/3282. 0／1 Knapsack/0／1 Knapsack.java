import java.util.*;
import java.io.*;


public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static class Pair{
		int value;
		int weight;
		Pair(int v, int w){
			this.value = v;
			this.weight = w;
		}
	}
	
	static int n,k;
	static int answer;
	static int dp[][];
	static Pair arr[];
	
	public static void main(String[] args) throws Exception {
		int tc= nextInt();
		
		for(int t=1;t<=tc;t++) {
			answer=0;
			n=nextInt();
			k=nextInt();
			dp = new int[n][k+1];
			arr = new Pair[n];
			
			int v,w;
			for(int i=0;i<n;i++) {
				w = nextInt(); v=nextInt();
				arr[i] = new Pair(v,w);
			}
			
			for(int j=arr[0].weight;j<k+1;j++) {
				dp[0][j] = arr[0].value;
			}
			
			for(int i=1;i<n;i++) {
				for(int j=0;j<k+1;j++) {
					dp[i][j] = dp[i-1][j];
					if(j-arr[i].weight>=0) {
						dp[i][j] = Math.max(dp[i][j], dp[i-1][j-arr[i].weight]+arr[i].value);
					}
				}
			}
			
			
			bw.write("#"+ t + " "+ dp[n-1][k] + "\n");
		}
		bw.flush();
		
	}

	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
