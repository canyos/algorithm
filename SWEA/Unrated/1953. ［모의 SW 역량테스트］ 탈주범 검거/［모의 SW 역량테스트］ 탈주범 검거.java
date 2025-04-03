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
		return r>=0 && r<n && c>=0 && c<m;
	}
	
	static void moveDown(int r, int c, int d) {
		if(checkPos(r+1,c)&& !visited[r+1][c]) {
			int next = arr[r+1][c];
			if(next==1 ||next==2 ||next==4||next==7) {
				qu.add(new Node(r+1,c,d+1));
				visited[r+1][c]=true;
			}
		}
	}
	
	static void moveLeft(int r, int c, int d) {
		if(checkPos(r,c-1)&& !visited[r][c-1]) {
			int next = arr[r][c-1];
			if(next==1 ||next==3 ||next==4||next==5) {
				qu.add(new Node(r,c-1,d+1));
				visited[r][c-1]=true;
			}
		}
	}
	
	static void moveUp(int r, int c, int d) {
		if(checkPos(r-1,c) && !visited[r-1][c]) {
			int next = arr[r-1][c];
			if(next==1 ||next==2 ||next==5||next==6) {
				qu.add(new Node(r-1,c,d+1));
				visited[r-1][c]=true;
			}
		}
	}
	
	static void moveRight(int r, int c, int d) {
		if(checkPos(r,c+1)&& !visited[r][c+1]) {
			int next = arr[r][c+1];
			if(next==1 ||next==3 ||next==6||next==7) {
				qu.add(new Node(r,c+1,d+1));
				visited[r][c+1]=true;
			}
		}
	}
	
	
	public static void main(String[] args) throws Exception {
		int tc= nextInt();
		for(int t=1;t<=tc;t++) {
			n = nextInt();
			m = nextInt();
			R=nextInt();
			C=nextInt();
			L=nextInt();
			
			arr = new int[n][m];
			visited = new boolean[n][m];
			qu = new LinkedList<>();
			int answer=0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					arr[i][j] = nextInt();
				}
			}
					
			qu.add(new Node(R,C,1));
			visited[R][C]=true;
			
			while(!qu.isEmpty()) {
				Node cur = qu.poll();
				int r=cur.a, c= cur.b, d=cur.d;
				answer++;
				if(d==L)
					continue;
				switch(arr[r][c]) {
				case 1:
					moveDown(r,c,d);
					moveUp(r,c,d);
					moveLeft(r,c,d);
					moveRight(r,c,d);
					break;
				case 2:
					moveUp(r,c,d);
					moveDown(r,c,d);
					break;
				case 3:
					moveLeft(r,c,d);
					moveRight(r,c,d);
					break;
				case 4:
					moveUp(r,c,d);
					moveRight(r,c,d);
					break;
				case 5:
					moveDown(r,c,d);
					moveRight(r,c,d);
					break;
				case 6:
					moveLeft(r,c,d);
					moveDown(r,c,d);
					break;
				case 7:
					moveUp(r,c,d);
					moveLeft(r,c,d);
					break;
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
