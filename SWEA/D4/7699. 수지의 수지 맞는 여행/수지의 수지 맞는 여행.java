import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;
import java.util.StringTokenizer;

public class Solution {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;

	public static int nextInt() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());	
		}
		return Integer.parseInt(st.nextToken());
	}
	public static Double nextDouble() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());	
		}
		return Double.parseDouble(st.nextToken());
	}
	
	
	static class Node{
		int r;
		int c;
		int depth;
		Node(int r, int c, int depth){
			this.r=r;
			this.c=c;
			this.depth = depth;
		}
	}
	static int dr[] = {0,0,-1,1}, dc[] = {1,-1,0,0};
	static boolean visited[];
	static int answer;
	static int n,m;
	static int map[][];
	
	static void recursive(Node cur) {
		answer = Math.max(answer, cur.depth);
		
		visited[map[cur.r][cur.c]]=true;
		for(int k=0;k<4;k++) {
			int nr = cur.r+dr[k], nc= cur.c+dc[k];
			if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[map[nr][nc]]) {
				recursive(new Node(nr,nc,cur.depth+1));
			}
		}
		visited[map[cur.r][cur.c]]=false;
	}
	
	public static void main(String[] args) throws Exception{
		int tc = nextInt();
		for(int t=1;t<=tc;t++) {
			answer=0;
			visited = new boolean[26];
			n = nextInt(); m=nextInt();
			map = new int[n][m];
			for(int i=0;i<n;i++) {
				String str = br.readLine();
				for(int j=0;j<m;j++) {
					map[i][j] = str.charAt(j)-'A';
				}
			}
			
			
			recursive(new Node(0,0,1));

			bw.write("#"+t+" " + answer + "\n");
		}
		bw.flush();
	}

}
