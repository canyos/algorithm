import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static class Node implements Comparable<Node>{
		int a;
		int b;
		int d;
		Node(int a, int b,int d){
			this.a=a;
			this.b=b;
			this.d=d;
		}
		@Override
		public int compareTo(Node o) {
			return this.d - o.d;
		}
	}
	
	static int n, m, R,C,L;
	static int arr[][];
	static boolean visited[][];
	static int dr[] = {0,0,-1,1}, dc[] = {-1,1,0,0};
	static Queue<Node> qu ;
	
	static boolean checkPos(int r,int c) {
		return r>=0 && r<n && c>=0 && c<n;
	}
	
	public static void main(String[] args)throws Exception {
		int t=1;
		while(true) {
			
			n = nextInt();
			if(n==0)break;
			arr = new int[n][n];
			int[][] dist = new int[n][n];
			
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					arr[i][j]=nextInt();
					dist[i][j] = 125*125*10;
				}
			}
			
			PriorityQueue<Node> pq = new PriorityQueue<>();
			pq.add(new Node(0,0,arr[0][0]));
			dist[0][0] = arr[0][0];
			int answer=0;
			while(!pq.isEmpty()) {
				Node cur = pq.poll();
				if(cur.a==n-1 && cur.b ==n-1) {
					answer = cur.d;
					break;
				}
				for(int k=0;k<4;k++) {
					int nr = cur.a+dr[k], nc = cur.b+dc[k];
					int cost = dist[cur.a][cur.b];
					if(checkPos(nr,nc) && dist[nr][nc]> cost+arr[nr][nc]) {
						pq.add(new Node(nr,nc,cost+arr[nr][nc]));
						dist[nr][nc] = cost+arr[nr][nc];
					} 
					
				}
			}
			bw.write("Problem "+ t + ": "+answer + "\n");
			t++;
		}
			
		bw.flush();
		
	}
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
