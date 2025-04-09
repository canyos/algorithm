import java.util.*;
import java.io.*;


public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static Scanner scanner = new Scanner(System.in);

	
	static int n;
	static int dist[][];
	
	public static void main(String[] args) throws Exception {
		int tc= nextInt();
		
		for(int t=1;t<=tc;t++) {
			n= nextInt();
			dist = new int [n+1][n+1];
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					dist[i][j] = nextInt();
					if(dist[i][j]==0) 
						dist[i][j] = (int)1e9;
				}
			}
			
			for(int k=1;k<=n;k++) {
				for(int i=1;i<=n;i++) {
					for(int j=1;j<=n;j++) {
						dist[i][j] = Math.min(dist[i][j], dist[i][k] +dist[k][j]);
					}
				}
			}
			
			int answer=(int)1e9;
			for(int i=1;i<=n;i++) {
				int sum= 0;
				for(int j=1;j<=n;j++) {
					if(i!=j)
						sum+=dist[i][j];
				}
				answer = Math.min(sum, answer);
			}
			
			bw.write("#"+t+ " " + answer+"\n"); 
		}
		bw.flush();
		
	}

	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return Integer.parseInt(st.nextToken());
	}
}
