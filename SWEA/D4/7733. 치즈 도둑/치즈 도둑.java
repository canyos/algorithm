import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	public static int nextInt() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());
		}
		return Integer.parseInt(st.nextToken());
	}	
	static int arr[][];
	static class Node{
		int r;
		int c;
		Node(int r,int c){
			this.r=r;
			this.c=c;
		}
	}
	static Queue<Node>qu = new LinkedList<>();
	static boolean checkPos(int r, int c, int n) {
		return r>=0 && r<n && c>=0 && c<n;
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int dx[] = {0,0,1,-1}, dy[]= {-1,1,0,0};
		int tc = nextInt();
		for(int t=1;t<=tc;t++) {
			int n = nextInt();
			arr = new int[n][n];
			
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					arr[i][j] = nextInt();
			
			int answer=1;
			for(int day=1;day<=100;day++) {
				int sum=0;
				boolean visited[][] = new boolean[n][n];
				for(int i=0;i<n;i++) {
					for(int j=0;j<n;j++) {
						if(!visited[i][j] && arr[i][j]>day) {
							qu.add(new Node(i,j));
							visited[i][j]=true;
							sum++;
							while(!qu.isEmpty()) {
								Node cur = qu.poll();
								int r=  cur.r, c=cur.c;
								for(int k=0;k<4;k++) {
									int nr = r+dx[k],nc=c+dy[k];
									if(checkPos(nr,nc,n) && !visited[nr][nc] && arr[nr][nc]>day) {
										qu.add(new Node(nr,nc));
										visited[nr][nc]=true;
									}
								}
							}
						}
					}
				}
				answer = Math.max(answer, sum);
			}
			bw.write("#"+t+" "+ answer+'\n');
		}
		bw.flush();
	}

}
