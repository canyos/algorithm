import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static int n,m;
	static int dist[][];
	
	public static void main(String[] args)throws Exception {
		n = nextInt(); 
		m = nextInt();
		dist = new int [n+1][n+1];
		int s,e;
		for(int i=0;i<m;i++) {
			s=nextInt();e=nextInt();
			dist[s][e] = dist[e][s]=1;
		}
		
		for(int k=1;k<=n;k++) {
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					dist[i][j] = dist[i][j] | (dist[i][k] & dist[k][j]);
				}
			}
		}
		
		int answer=0;
		for(int i=2;i<=n;i++) {
			answer += dist[1][i];
		}
		System.out.println(answer);
		
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
