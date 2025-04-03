import java.util.*;
import java.io.*;


public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static class Node implements Comparable<Node>{
		int a;
		int b;
		int cost;
		Node(int a, int b, int c){
			this.a=a;
			this.b=b;
			this.cost=c;
		}
		@Override
		public int compareTo(Node o) {
			return this.cost - o.cost;
		}
	}
	
	static int n;
	static int arr[][];
	static int dist[][];
	static int dr[] = {0,0,-1,1}, dc[] = {-1,1,0,0};
	static boolean checkPos(int r,int c) {
		return r>=0 && r<n && c>=0 && c<n;
	}
	
	public static void main(String[] args) throws Exception {
		int tc= nextInt();
		for(int t=1;t<=tc;t++) {
			n=nextInt();
			arr = new int[n][n];
			dist = new int[n][n];
			int answer=-1;
			for(int i=0;i<n;i++) {
				String str = br.readLine();
				for(int j=0;j<n;j++) {
					arr[i][j] = str.charAt(j)-'0';
					dist[i][j] = 100*100*10;
				}
			}
					
			PriorityQueue<Node> pq = new PriorityQueue<>();
			pq.add(new Node(0,0,0));
			dist[0][0] = 0;
			
			while(!pq.isEmpty()) {
				Node cur = pq.poll();
				if(cur.a== n-1 && cur.b == n-1) {
					answer = cur.cost;
					break;
				}
				for(int k=0;k<4;k++) {
					int nr = cur.a + dr[k], nc=cur.b+dc[k];
					if(checkPos(nr,nc) && dist[nr][nc]>dist[cur.a][cur.b]+ arr[nr][nc] ) {
						pq.add(new Node(nr,nc,dist[cur.a][cur.b]+ arr[nr][nc]));
						dist[nr][nc] = dist[cur.a][cur.b]+ arr[nr][nc];
					}
				}
			}
			bw.write("#"+ t + " "+ answer + "\n");
		}
		bw.flush();
		
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
