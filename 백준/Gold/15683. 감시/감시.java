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
		public int r;
		public int c;
		Pair(int r, int c){
			this.r=r;
			this.c=c;
		}
	}
	public static int n,m;
	public static int map[][];
	public static List<Pair> camera = new ArrayList<>();
	public static int cameraLen;
	public static boolean visited[][];
	public static int answer;
	
	public static void recursive(int pos, boolean visit[][]) {
		if(pos == cameraLen) {
			int cnt=0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(visit[i][j] == false) {
						cnt++;
					}
				}
			}
			answer = Math.min(answer, cnt);
			return;
		}
		
		
		Pair cam = camera.get(pos);
		int r = cam.r, c= cam.c, num = map[r][c];
		Stack<Pair> st = new Stack<>();
		if(num==1) {
			for(int i=1;r-i>=0 && map[r-i][c]!=6;i++) {
				if(visit[r-i][c]==false) {
					visit[r-i][c]=true;
					st.push(new Pair(r-i,c));
				}
			}
			recursive(pos+1,visit);
			while(!st.isEmpty()) {
				Pair cur = st.pop();
				visit[cur.r][cur.c]=false;
			}
			
			
			for(int i=1;c-i>=0 && map[r][c-i]!=6;i++) {
				if(visit[r][c-i]==false) {
					visit[r][c-i]=true;
					st.push(new Pair(r,c-i));
				}
			}
			recursive(pos+1,visit);
			while(!st.isEmpty()) {
				Pair cur = st.pop();
				visit[cur.r][cur.c]=false;
			}
			
			for(int i=1;r+i<n && map[r+i][c]!=6;i++) {
				if(visit[r+i][c]==false) {
					visit[r+i][c]=true;
					st.push(new Pair(r+i,c));
				}
			}
			recursive(pos+1,visit);
			while(!st.isEmpty()) {
				Pair cur = st.pop();
				visit[cur.r][cur.c]=false;
			}
			
			for(int i=1;c+i<m && map[r][c+i]!=6;i++) {
				if(visit[r][c+i]==false) {
					visit[r][c+i]=true;
					st.push(new Pair(r,c+i));
				}
			}
			recursive(pos+1,visit);
			while(!st.isEmpty()) {
				Pair cur = st.pop();
				visit[cur.r][cur.c]=false;
			}
		}
		if(num==2) {
			for(int i=1;r-i>=0 && map[r-i][c]!=6;i++) {
				if(visit[r-i][c]==false) {
					visit[r-i][c]=true;
					st.push(new Pair(r-i,c));
				}
			}			
			for(int i=1;r+i<n && map[r+i][c]!=6;i++) {
				if(visit[r+i][c]==false) {
					visit[r+i][c]=true;
					st.push(new Pair(r+i,c));
				}
			}

			recursive(pos+1,visit);
			while(!st.isEmpty()) {
				Pair cur = st.pop();
				visit[cur.r][cur.c]=false;
			}
						
			for(int i=1;c-i>=0 && map[r][c-i]!=6;i++) {
				if(visit[r][c-i]==false) {
					visit[r][c-i]=true;
					st.push(new Pair(r,c-i));
				}
			}
			for(int i=1;c+i<m && map[r][c+i]!=6;i++) {
				if(visit[r][c+i]==false) {
					visit[r][c+i]=true;
					st.push(new Pair(r,c+i));
				}
			}
			recursive(pos+1,visit);
			while(!st.isEmpty()) {
				Pair cur = st.pop();
				visit[cur.r][cur.c]=false;
			}
		}
		if(num==3) {
			for(int i=1;r-i>=0 && map[r-i][c]!=6;i++) {
				if(visit[r-i][c]==false) {
					visit[r-i][c]=true;
					st.push(new Pair(r-i,c));
				}
			}			
			for(int i=1;c-i>=0 && map[r][c-i]!=6;i++) {
				if(visit[r][c-i]==false) {
					visit[r][c-i]=true;
					st.push(new Pair(r,c-i));
				}
			}
			recursive(pos+1,visit);
			while(!st.isEmpty()) {
				Pair cur = st.pop();
				visit[cur.r][cur.c]=false;
			}
						
			for(int i=1;r-i>=0 && map[r-i][c]!=6;i++) {
				if(visit[r-i][c]==false) {
					visit[r-i][c]=true;
					st.push(new Pair(r-i,c));
				}
			}	
			for(int i=1;c+i<m && map[r][c+i]!=6;i++) {
				if(visit[r][c+i]==false) {
					visit[r][c+i]=true;
					st.push(new Pair(r,c+i));
				}
			}
			recursive(pos+1,visit);
			while(!st.isEmpty()) {
				Pair cur = st.pop();
				visit[cur.r][cur.c]=false;
			}
			
			for(int i=1;c-i>=0 && map[r][c-i]!=6;i++) {
				if(visit[r][c-i]==false) {
					visit[r][c-i]=true;
					st.push(new Pair(r,c-i));
				}
			}
			for(int i=1;r+i<n && map[r+i][c]!=6;i++) {
				if(visit[r+i][c]==false) {
					visit[r+i][c]=true;
					st.push(new Pair(r+i,c));
				}
			}

			recursive(pos+1,visit);
			while(!st.isEmpty()) {
				Pair cur = st.pop();
				visit[cur.r][cur.c]=false;
			}
						
			for(int i=1;r+i<n && map[r+i][c]!=6;i++) {
				if(visit[r+i][c]==false) {
					visit[r+i][c]=true;
					st.push(new Pair(r+i,c));
				}
			}
			for(int i=1;c+i<m && map[r][c+i]!=6;i++) {
				if(visit[r][c+i]==false) {
					visit[r][c+i]=true;
					st.push(new Pair(r,c+i));
				}
			}
			recursive(pos+1,visit);
			while(!st.isEmpty()) {
				Pair cur = st.pop();
				visit[cur.r][cur.c]=false;
			}
			
			
		}
		if(num==4) {
			for(int i=1;c-i>=0 && map[r][c-i]!=6;i++) {
				if(visit[r][c-i]==false) {
					visit[r][c-i]=true;
					st.push(new Pair(r,c-i));
				}
			}
			for(int i=1;r+i<n && map[r+i][c]!=6;i++) {
				if(visit[r+i][c]==false) {
					visit[r+i][c]=true;
					st.push(new Pair(r+i,c));
				}
			}
			for(int i=1;c+i<m && map[r][c+i]!=6;i++) {
				if(visit[r][c+i]==false) {
					visit[r][c+i]=true;
					st.push(new Pair(r,c+i));
				}
			}
			recursive(pos+1,visit);
			while(!st.isEmpty()) {
				Pair cur = st.pop();
				visit[cur.r][cur.c]=false;
			}
			
			for(int i=1;r-i>=0 && map[r-i][c]!=6;i++) {
				if(visit[r-i][c]==false) {
					visit[r-i][c]=true;
					st.push(new Pair(r-i,c));
				}
			}			
			for(int i=1;r+i<n && map[r+i][c]!=6;i++) {
				if(visit[r+i][c]==false) {
					visit[r+i][c]=true;
					st.push(new Pair(r+i,c));
				}
			}
			for(int i=1;c+i<m && map[r][c+i]!=6;i++) {
				if(visit[r][c+i]==false) {
					visit[r][c+i]=true;
					st.push(new Pair(r,c+i));
				}
			}
			recursive(pos+1,visit);
			while(!st.isEmpty()) {
				Pair cur = st.pop();
				visit[cur.r][cur.c]=false;
			}
			
			for(int i=1;r-i>=0 && map[r-i][c]!=6;i++) {
				if(visit[r-i][c]==false) {
					visit[r-i][c]=true;
					st.push(new Pair(r-i,c));
				}
			}			
			for(int i=1;c-i>=0 && map[r][c-i]!=6;i++) {
				if(visit[r][c-i]==false) {
					visit[r][c-i]=true;
					st.push(new Pair(r,c-i));
				}
			}
			for(int i=1;c+i<m && map[r][c+i]!=6;i++) {
				if(visit[r][c+i]==false) {
					visit[r][c+i]=true;
					st.push(new Pair(r,c+i));
				}
			}
			recursive(pos+1,visit);
			while(!st.isEmpty()) {
				Pair cur = st.pop();
				visit[cur.r][cur.c]=false;
			}
			
			
			for(int i=1;r-i>=0 && map[r-i][c]!=6;i++) {
				if(visit[r-i][c]==false) {
					visit[r-i][c]=true;
					st.push(new Pair(r-i,c));
				}
			}			
			for(int i=1;c-i>=0 && map[r][c-i]!=6;i++) {
				if(visit[r][c-i]==false) {
					visit[r][c-i]=true;
					st.push(new Pair(r,c-i));
				}
			}
			for(int i=1;r+i<n && map[r+i][c]!=6;i++) {
				if(visit[r+i][c]==false) {
					visit[r+i][c]=true;
					st.push(new Pair(r+i,c));
				}
			}
			recursive(pos+1,visit);
			while(!st.isEmpty()) {
				Pair cur = st.pop();
				visit[cur.r][cur.c]=false;
			}
		}
		if(num==5) {
			for(int i=1;r-i>=0 && map[r-i][c]!=6;i++) {
				if(visit[r-i][c]==false) {
					visit[r-i][c]=true;
					st.push(new Pair(r-i,c));
				}
			}			
			for(int i=1;c-i>=0 && map[r][c-i]!=6;i++) {
				if(visit[r][c-i]==false) {
					visit[r][c-i]=true;
					st.push(new Pair(r,c-i));
				}
			}
			for(int i=1;r+i<n && map[r+i][c]!=6;i++) {
				if(visit[r+i][c]==false) {
					visit[r+i][c]=true;
					st.push(new Pair(r+i,c));
				}
			}
			for(int i=1;c+i<m && map[r][c+i]!=6;i++) {
				if(visit[r][c+i]==false) {
					visit[r][c+i]=true;
					st.push(new Pair(r,c+i));
				}
			}
			recursive(pos+1,visit);
			while(!st.isEmpty()) {
				Pair cur = st.pop();
				visit[cur.r][cur.c]=false;
			}
		}
	}
	
	
	public static void main(String[] args) throws Exception{
		n = nextInt(); m= nextInt();
		answer = n*m;
		map= new int[n][m];
		visited = new boolean[n][m];
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				map[i][j] = nextInt();
				if(map[i][j]>0 ) {
					if(map[i][j]<6)
						camera.add(new Pair(i,j));
					visited[i][j] = true;
				}
			}
		}
		cameraLen = camera.size();
		
		recursive(0,visited);
		
		System.out.println(answer);
	}

}
