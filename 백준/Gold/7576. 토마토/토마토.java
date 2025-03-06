import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	public static int nextInt() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());
		}
		return Integer.parseInt(st.nextToken());
	}	
	
	public static class node{
		int r;
		int c;
		node(int a, int b){
			this.r=a;
			this.c=b;
		}
	}
	
	static int dx[] = {0,0,1,-1,1,1,-1,-1},dy[] = {1,-1,0,0,1,-1,1,-1};
	static Queue<node> qu = new LinkedList<>();
	static int visited[][];
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int m = nextInt();
		int n = nextInt();
		int cnt0=0;
		int arr[][] = new int[n][m];
		visited = new int[n][m];
	
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				arr[i][j] = nextInt();
				visited[i][j] = 10000001;
				if(arr[i][j] == 0)
					cnt0++;
				else if(arr[i][j] == 1) {
					qu.add(new node(i,j));
					visited[i][j] = 1;
				}
					
			}
		}
		int answer=-1;
		while(!qu.isEmpty()) {
			node cur = qu.poll();
			int r = cur.r, c= cur.c;
			answer = Math.max(answer, visited[r][c]);
			for(int i=0;i<4;i++) {
				int tr = r+dx[i], tc= c+dy[i];
				if(tr>=0 && tr<n && tc>=0 && tc<m && arr[tr][tc]==0 && visited[tr][tc]-1 > visited[r][c]) {
					qu.add(new node(tr,tc));
					visited[tr][tc] = visited[r][c]+1;
					cnt0--;
				}
			}
		}
		
		if(cnt0!=0)
			System.out.println(-1);
		else
			System.out.println(answer-1);
	}

}
