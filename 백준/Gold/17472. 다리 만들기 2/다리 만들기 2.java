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
	
	static class Edge implements Comparable<Edge>{
		int a;
		int b;
		int c;
		Edge(int a,int b,int c){
			this.a=a;
			this.b=b;
			this.c=c;
		}
		@Override
		public int compareTo(Edge o) {
			return this.c - o.c;
		}
	}
	
	static int n,m;
	static int dist[][];
	static int arr[][];
	static int map[][];
	static int cnt=1;//섬의개수
	static PriorityQueue<Edge> edges = new PriorityQueue<>();
	static int par[] = new int [7];
	static int answer;
 	static boolean checkPos(int r, int c) {
 		return r>=0 && r<n && c>=0 && c<m;
 	}
	static int dr[] = {0,0,-1,1},dc[] = {-1,1,0,0};
		
	static void makeMap() {
		
		Queue<Pair> qu = new LinkedList<Main.Pair>();
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(arr[i][j] == 1 && map[i][j]==0) {
					qu.add(new Pair(i,j));
					map[i][j] = cnt;
					while(!qu.isEmpty()) {
						Pair cur = qu.poll();
						for(int k=0;k<4;k++) {
							int tr = cur.r+dr[k],tc=cur.c+dc[k];
							if(checkPos(tr,tc) && arr[tr][tc]==1 && map[tr][tc]==0) {
								qu.add(new Pair(tr,tc));
								map[tr][tc]=cnt;
							}
						}
					}
					cnt++;
				}
			}
		}
		cnt--;//
	}
	static void makeEdge() {
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(map[i][j]>0) {
					for(int k=0;k<4;k++) {
						int tr = i+dr[k], tc=j+dc[k];
						int len = 1;
						while(checkPos(tr,tc) && map[tr][tc]==0) {
							len++;
							tr +=dr[k];
							tc +=dc[k];
						}
						if(checkPos(tr,tc) && map[tr][tc] != map[i][j] && len-1>1) {
							edges.add(new Edge(map[tr][tc], map[i][j], len-1));
						}
					}
				}
			}
		}
	}
	
	static int find(int a) {
		if(par[a] == a)return a;
		return par[a] = find(par[a]);
	}
	
	static void union(int a, int b) {
		int x = find(a);
		int y = find (b);
		
		par[x] = y;
	}
	static int mst() {
		int cnt2=0;
		while(!edges.isEmpty()) {
			Edge cur = edges.poll();
			if(find(cur.a) != find(cur.b)) {
				answer+=cur.c;
				union(cur.a, cur.b);
				cnt2++;
			}
		}
		return cnt2;
	}
	public static void main(String[] args)throws Exception {
		n = nextInt();m=nextInt();
		dist = new int[7][7];
		arr = new int [n][m];
		map = new int [n][m];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				arr[i][j]=nextInt();
		for(int i=1;i<7;i++) 
			par[i] = i;
		
		makeMap();
		makeEdge();
		int cnt2 = mst();
		
		if(cnt-1!=cnt2)answer=-1;
		System.out.println(answer);
	}
	
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
