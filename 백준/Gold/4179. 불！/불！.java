import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static class Node{
		int r;
		int c;
		int cnt;

		Node(int a,int b,int c){
			this.r=a;
			this.c=b;
			this.cnt=c;
		}
	}
	
	static int n,m;
	static char map[][];
	static int fire[][];
	static boolean visited[][];
	
	static int dr[]= {0,0,-1,1}, dc[] = {1,-1,0,0};
	static Queue<Node> fq = new LinkedList<>();
	static Queue<Node> jq = new LinkedList<>();
	
	static boolean checkPos(int r,int c) {
		return r>=0 && r<n && c>=0 && c<m;
	}
	
	public static void main(String[] args)throws Exception {
		n = nextInt();
		m = nextInt();
		map = new char[n][m];
		String str;
		fire = new int[n][m];
		visited = new boolean[n][m];
		
		for(int i=0;i<n;i++) {
			str=br.readLine();
			for(int j=0;j<m;j++) {
				map[i][j]=str.charAt(j);
				if(map[i][j]=='J') {
					map[i][j] = '.';
					jq.add(new Node(i,j,1));
					visited[i][j]=true;
				}
				if(map[i][j]=='F') {
					fq.add(new Node(i,j,1));
				}
			}
		}
		
		while(!fq.isEmpty()) {
			Node cur = fq.poll();
			for(int k=0;k<4;k++) {
				int tr = cur.r+dr[k],tc=cur.c+dc[k];
				if(checkPos(tr,tc) && map[tr][tc]=='.' && fire[tr][tc]==0) {
					fire[tr][tc] = cur.cnt+1;
					fq.add(new Node(tr,tc,cur.cnt+1));
				}
			}
		}
		
		int answer=-1;
		
		loop:while(!jq.isEmpty()) {
			Node cur = jq.poll();
			for(int k=0;k<4;k++) {
				int tr = cur.r+dr[k],tc=cur.c+dc[k];
				if(!checkPos(tr,tc)) {
					answer = cur.cnt;
					break loop;
				}
				else if(!visited[tr][tc] && map[tr][tc]=='.' && (fire[tr][tc] > cur.cnt+1||fire[tr][tc]==0)) {
					visited[tr][tc]=true;
					jq.add(new Node(tr,tc,cur.cnt+1));
				}
			}
		}
		
		if(answer==-1) 
			System.out.println("IMPOSSIBLE");
		else
			System.out.println(answer);
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
