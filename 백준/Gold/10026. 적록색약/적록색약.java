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
	static boolean visited[][];
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int n = nextInt();
		char arr[][] = new char[n][n];
		visited = new boolean[n][n];
	
		for(int i=0;i<n;i++) {
			String str = br.readLine();
			for(int j=0;j<n;j++) {
				arr[i][j] = str.charAt(j);
			}
		}
		
		
		int answer1=0, answer2=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(!visited[i][j]) {
					qu.add(new node(i,j));
					answer1++;
					while(!qu.isEmpty()) {
						node cur = qu.poll();
						int r = cur.r, c= cur.c;
						for(int k=0;k<4;k++) {
							int tr = r+dx[k], tc= c+dy[k];
							if(tr>=0 && tr<n && tc>=0 && tc<n && !visited[tr][tc] && arr[r][c]== arr[tr][tc]) {
								qu.add(new node(tr,tc));
								visited[tr][tc]=true;
							}
						}
					}
				}
			}
		}
		
		visited = new boolean[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(!visited[i][j]) {
					qu.add(new node(i,j));
					answer2++;
					while(!qu.isEmpty()) {
						node cur = qu.poll();
						int r = cur.r, c= cur.c;
						for(int k=0;k<4;k++) {
							int tr = r+dx[k], tc= c+dy[k];
							if(tr>=0 && tr<n && tc>=0 && tc<n && !visited[tr][tc]) {
								if(arr[r][c] == 'B' && arr[tr][tc]=='B') {
									qu.add(new node(tr,tc));
									visited[tr][tc]=true;
								}
								if((arr[r][c]=='R' || arr[r][c] =='G') && (arr[tr][tc] == 'R'||arr[tr][tc]=='G')) {
									qu.add(new node(tr,tc));
									visited[tr][tc]=true;
								}
							}
						}
					}
				}
			}
		}
		System.out.println(answer1 + " " + answer2);
	}

}
