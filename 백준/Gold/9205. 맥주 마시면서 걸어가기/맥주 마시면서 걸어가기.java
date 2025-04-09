import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static class Pair{
		int r;
		int c;
		Pair(int r, int c){
			this.r=r;
			this.c=c;
		}
	}
	
	static int func(Pair a, Pair b) {
		return Math.abs(a.r - b.r) + Math.abs(a.c - b.c) <= 1000 ? 1 : 0;
	}
	
	static int n,m;
	static int dist[][];
	static Pair arr[];
	public static void main(String[] args)throws Exception {
		int tc = nextInt();
		for(int t=1;t<=tc;t++) {
			n = nextInt(); 
			arr = new Pair[n+2];
			dist = new int [n+2][n+2];
			
			int x,y;
			for(int i=0;i<n+2;i++) {
				x=nextInt();y=nextInt();
				arr[i] = new Pair(x,y);
			}
			
			for(int i=0;i<n+2;i++) {
				for(int j=i+1;j<n+2;j++) {
					dist[i][j] = dist[j][i] = func(arr[i],arr[j]);
				}
			}
			
			for(int k=0;k<n+2;k++) {
				for(int i=0;i<n+2;i++) {
					for(int j=0;j<n+2;j++) {
						dist[i][j] = dist[i][j] | (dist[i][k] & dist[k][j]);
					}
				}
			}
			
			if(dist[0][n+1]==1)System.out.println("happy");
			else System.out.println("sad");
		}
		
		
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
