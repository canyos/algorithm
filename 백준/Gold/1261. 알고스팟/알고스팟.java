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
	
	static int n, m;
	static int arr[][];
	static int dist[][];
	static int dr[] = {0,0,-1,1}, dc[] = {-1,1,0,0};
	static PriorityQueue<Node> pq ;
	
	static boolean checkPos(int r,int c) {
		return r>=0 && r<n && c>=0 && c<m;
	}
	
	public static void main(String[] args)throws Exception {
		m=nextInt();n=nextInt();
		arr=new int[n][m];
		dist = new int [n][m];
		for(int i=0;i<n;i++) {
			String str = br.readLine();
			for(int j=0;j<m;j++) {
				arr[i][j] = str.charAt(j)-'0';
				dist[i][j] = n*m+1;
			}
		}
		
		pq=new PriorityQueue<>();
		pq.add(new Node(0,0,0));
		dist[0][0] = 0;
		int answer=0;
		
		while(!pq.isEmpty()) {
			Node cur = pq.poll();
			int r = cur.a, c= cur.b, cost = cur.d;
			if(r==n-1 && c==m-1) {
				answer = cost;
				break;
			}
			
			for(int k=0;k<4;k++) {
				int tr = r+dr[k],tc=c+dc[k];
				if(checkPos(tr,tc)&& dist[tr][tc]>dist[r][c]+arr[tr][tc]) {
					pq.add(new Node(tr,tc, dist[r][c]+arr[tr][tc]));
					dist[tr][tc] = dist[r][c]+arr[tr][tc];
				}
			}
		}
		System.out.println(answer);
			
		bw.flush();
		
	}
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
