import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static int n,k;
	static int dist[][];
	public static void main(String[] args)throws Exception {
		n = nextInt(); k =nextInt();
		int s,e;
		dist =  new int [n+1][n+1];
		for(int i=0;i<k;i++) {
			s=nextInt();e=nextInt();
			dist[s][e] = -1;
			dist[e][s] = 1;
		}
		
		for(int k=1;k<=n;k++) {
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					if(dist[i][k]  == dist[k][j] && dist[i][k]!=0)
						dist[i][j] = dist[i][k];
				}
			}
		}
		k =nextInt();
		for(int i=0;i<k;i++) {
			s=nextInt();e=nextInt();
			System.out.println(dist[s][e]);
		}
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
