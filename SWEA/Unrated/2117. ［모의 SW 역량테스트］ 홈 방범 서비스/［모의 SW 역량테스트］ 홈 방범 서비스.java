import java.util.*;
import java.io.*;


public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static class Node {
		int a;
		int b;
		int d;
		Node(int a, int b,int d){
			this.a=a;
			this.b=b;
			this.d=d;
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
	
	public static void main(String[] args) throws Exception {
		int tc= nextInt();
		int cost[] = new int[44];

		for(int i=1;i<=43;i++) {
			cost[i] = i*i + (i-1)*(i-1);
		}
		
		for(int t=1;t<=tc;t++) {
			n = nextInt();
			m = nextInt();
			
			arr = new int[n][n];
			qu = new LinkedList<>();
			
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					arr[i][j] = nextInt();
				}
			}
			
			int answer=0;
			
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {

					visited = new boolean[n][n];
					int lastDepth=0;
					qu.add(new Node(i,j,0));
					int cnt=0;
					
					while(!qu.isEmpty()) {
						Node cur = qu.poll();
						int r = cur.a, c=cur.b, depth=cur.d;
						if(lastDepth!=depth) {
							lastDepth = depth;
							if(cnt*m - cost[depth]>=0) {
								answer = Math.max(cnt, answer);
							}
						}
						
						if(visited[r][c])continue;
						visited[r][c]=true;
						cnt += arr[r][c];
						
						for(int k=0;k<4;k++) {
							int nr = r+dr[k], nc=c+dc[k];
							if(checkPos(nr,nc) && !visited[nr][nc]) {
								qu.add(new Node(nr,nc,depth+1));
							}
						}
					}
					if(cnt*m - cost[lastDepth]>=0) {
						answer = Math.max(cnt, answer);
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
