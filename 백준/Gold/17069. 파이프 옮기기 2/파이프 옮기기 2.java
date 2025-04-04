import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static long dp[][][];
	static int map[][];
	static int n;
	
	public static void main(String[] args)throws Exception {
		n = nextInt();
		map = new int [n+1][n+1];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				map[i][j] = nextInt();
		
		dp = new long [n+1][n+1][3];
		dp[0][1][0] = 1; 
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				for(int k=0;k<3;k++) {
					if(k==0) {
						if(map[i][j+1]==0) {
							dp[i][j+1][0] +=dp[i][j][0];
						}
						if(map[i+1][j+1]==0 && map[i+1][j] ==0 && map[i][j+1]==0) {
							dp[i+1][j+1][2] +=dp[i][j][0];
						}
					}
					if(k==1) {
						if(map[i+1][j]==0) {
							dp[i+1][j][1] +=dp[i][j][1];
						}
						if(map[i+1][j+1]==0 && map[i+1][j] ==0 && map[i][j+1]==0) {
							dp[i+1][j+1][2] +=dp[i][j][1];
						}
					}
					if(k==2) {
						if(map[i][j+1]==0) {
							dp[i][j+1][0] +=dp[i][j][2];
						}
						if(map[i+1][j]==0) {
							dp[i+1][j][1] +=dp[i][j][2];
						}
						if(map[i+1][j+1]==0 && map[i+1][j] ==0 && map[i][j+1]==0) {
							dp[i+1][j+1][2] +=dp[i][j][2];
						}
					}
				}
			}
		}
		
		System.out.println(dp[n-1][n-1][0] + dp[n-1][n-1][1]+ dp[n-1][n-1][2]);
		
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
