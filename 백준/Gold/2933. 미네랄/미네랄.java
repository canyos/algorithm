import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;

	public static int nextInt() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());	
		}
		return Integer.parseInt(st.nextToken());
	}
	
	public static class Pair{
		int r;
		int c;
		Pair(int r, int c){
			this.r=r;
			this.c=c;
		}
	}
	
	public static class Result{
		boolean ground;
		int height;
		Result(boolean r, int c){
			this.ground=r;
			this.height=c;
		}
	}
	
	static int n,m;
	static char map[][];
	static Queue<Pair> qu = new LinkedList<>();
	static int dr[] = {0,0,1,-1}, dc[] = {1,-1,0,0};
	static int visited[][];
	static int cnt;
	
	public static boolean checkPos(int r, int c) {
		return r>=0 && r<n && c>=0 && c<m;
	}
	
	static Result bfs() {
		boolean ground = false;
		int height = 100;
		Queue<Pair> down = new LinkedList<>();
		
		while(!qu.isEmpty()) {
			Pair cur = qu.poll();
			if(visited[cur.r][cur.c]!=0)
				continue;
			
			visited[cur.r][cur.c]= cnt;
			if(cur.r == n-1) 
				ground=true;
						
			if(!ground && map[cur.r+1][cur.c]=='.'){
				down.add(cur);
			}
			for(int k=0;k<4;k++) {
				int tr = cur.r+dr[k],tc=cur.c+dc[k];
				if(checkPos(tr,tc) && visited[tr][tc]==0 && map[tr][tc]=='x') {
					qu.add(new Pair(tr,tc));
				}
			}
		}
		
		while(!down.isEmpty()) {
			Pair cur = down.poll();
			int i=1;
			
			for(i=1;cur.r+i<n && map[cur.r+i][cur.c]=='.'  ;i++) 
			{}
			
			if(cur.r+i==n || visited[cur.r+i][cur.c]!=cnt)
				height = Math.min(i-1, height);
		}
		
				
		return new Result(ground,height);
	}
	
	public static void main(String[] args) throws Exception{
		n = nextInt(); m = nextInt();
		map = new char[n][m];
		for(int i=0;i<n;i++) {
			String str = br.readLine();
			for(int j=0;j<m;j++) {
				map[i][j] = str.charAt(j);
			}
		}
		
		int num = nextInt();
		
		for(int i=0;i<num;i++) {
			int r=-1,c=-1;
			int height = nextInt();
			
			//부서지는 곳 찾기
			if(i%2==0) {
				for(int j=0;j<m;j++) {
					if(map[n-height][j] == 'x') {
						r = n-height;
						c=j;
						break;
					}
				}
			}
			else {
				for(int j=m-1;j>=0;j--) {
					if(map[n-height][j] == 'x') {
						r = n-height;
						c=j;
						break;
					}
				}
			}
			
			if(r==-1 && c==-1)continue;
			map[r][c] = '.';
			visited = new int[n][m];
			cnt=1;
			
			if(r>0 && map[r-1][c]=='x')
				qu.add(new Pair(r-1,c));
			Result res = bfs();
			if(!res.ground) {
				for(int ii = n-1;ii>=0;ii--) {
					for(int jj=0;jj<m;jj++) {
						if(visited[ii][jj]==cnt) {
							map[ii+res.height][jj] = 'x';
							map[ii][jj] = '.';
						}
					}
				}
			}
			cnt++;
			
			if(r<n-1 && map[r+1][c]=='x')
				qu.add(new Pair(r+1,c));
			res = bfs();
			if(!res.ground) {
				for(int ii = n-1;ii>=0;ii--) {
					for(int jj=0;jj<m;jj++) {
						if(visited[ii][jj]==cnt) {
							map[ii+res.height][jj] = 'x';
							map[ii][jj] = '.';
						}
					}
				}
			}
			cnt++;
			
			boolean side = false;
			if(i%2==0) {
				if(c<m-1 && map[r][c+1]=='x') {
					qu.add(new Pair(r,c+1));
					side = true;
				}
					
			}else {
				if(c>0 && map[r][c-1]=='x') {
					qu.add(new Pair(r,c-1));
					side = true;
				}
					
			}
			res = bfs();
			
			if(!res.ground && side) {
				for(int ii = n-1;ii>=0;ii--) {
					for(int jj=0;jj<m;jj++) {
						if(visited[ii][jj] == cnt) {
							map[ii+res.height][jj] = 'x';
							map[ii][jj] = '.';
						}
					}
				}
			}
			
		}
		
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				bw.write(map[i][j]);
			}
			bw.write("\n");
		}
		bw.flush();
	}

}
