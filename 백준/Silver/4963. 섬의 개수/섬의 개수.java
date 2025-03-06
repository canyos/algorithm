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
	public static class coor{
		int r;
		int c;
		coor(int r,int c){
			this.r =r;
			this.c=c;
		}
	}
	public static boolean checkPos(int r, int c, int n, int m) {
		return r>=0 && r<n && c>=0 && c<m;
	}
	static int arr[][];
	static boolean visited[][];
	static int dx[] = {0,0,1,-1,1,1,-1,-1},dy[] = {1,-1,0,0,1,-1,1,-1};
	static Queue<coor> qu = new LinkedList<>();
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		while(true) {
			
			int m = nextInt();
			int n = nextInt();
			if(n==0 && m==0)return;
			arr = new int [n][m];
			visited = new boolean[n][m];
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					arr[i][j] = nextInt();
				}
			}
			
			int answer=0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(arr[i][j] ==1 && !visited[i][j]) {
					
						answer++;
						qu.add(new coor(i,j));
						while(!qu.isEmpty()) {
							coor v = qu.poll();
							int r = v.r, c= v.c;
							for(int k=0;k<8;k++) {
								int tr = r+dx[k], tc= c+dy[k];
								if(checkPos(tr,tc,n,m) && !visited[tr][tc] && arr[tr][tc]==1) {
									qu.add(new coor(tr,tc));
									visited[tr][tc]=true;
								}
							}
						}
					}
				}
			}
			System.out.println(answer);
		}

		
		
	}

}
