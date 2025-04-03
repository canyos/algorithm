import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static class Node implements Comparable<Node>{
		int a;
		int b;
		int c;
		int cost;
		Node(int a, int b,int c, int cost){
			this.a=a;
			this.b=b;
			this.c=c;
			this.cost=cost;
		}
		@Override
		public int compareTo(Node o) {
			return this.cost - o.cost;
		}
	}
	
	static int n, m, k;
	static int arr[][];
	static int dist[][][];
	static int dr[] = {0,0,-1,1}, dc[] = {-1,1,0,0};
	static int dr2[] = {-2,-2,-1,-1,1,1,2,2}, dc2[] = {-1,1,-2,2,-2,2,-1,1};
	
	static PriorityQueue<Node> pq ;
	
	static boolean checkPos(int r,int c) {
		return r>=0 && r<n && c>=0 && c<m;
	}
	
	public static void main(String[] args)throws Exception {
		int k = nextInt();
		m=nextInt();n=nextInt();
		
		arr = new int[n][m];
		dist = new int[n][m][k+1];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				arr[i][j] = nextInt();
				for(int l=0;l<k+1;l++) {
					dist[i][j][l] = 40000;
				}
			}
		}
		
		pq=new PriorityQueue<>();
		pq.add(new Node(0,0,0,0));
		dist[0][0][0] = 0;
		int answer=40000;
		
		while(!pq.isEmpty()) {
			Node cur = pq.poll();
			int r = cur.a, c= cur.b, cnt = cur.c, cost = cur.cost;
			if(r==n-1 && c==m-1) {
				answer = Math.min(answer,cost);
				break;
			}
			
			if(cnt<k) {
				for(int a=0;a<8;a++) {
					int tr = r+dr2[a],tc=c+dc2[a];
					if(checkPos(tr,tc) && arr[tr][tc]!=1 && dist[tr][tc][cnt+1]>dist[r][c][cnt]+1) {
						pq.add(new Node(tr,tc,cnt+1,cost+1));
						dist[tr][tc][cnt+1]=cost+1;
					}
				}
			}
			for(int a=0;a<4;a++) {
				int tr = r+dr[a],tc=c+dc[a];
				if(checkPos(tr,tc) && arr[tr][tc]!=1 && dist[tr][tc][cnt]>dist[r][c][cnt]+1) {
					pq.add(new Node(tr,tc,cnt,cost+1));
					dist[tr][tc][cnt]=cost+1;
				}
			}
		}
		if(answer==40000)answer=-1;
		System.out.println(answer);
			
		bw.flush();
		
	}
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
