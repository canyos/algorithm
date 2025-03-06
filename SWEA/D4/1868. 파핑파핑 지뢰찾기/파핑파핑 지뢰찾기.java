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
	static char arr[][];
	static int cnt[][];
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
		int dx[] = {0,0,1,-1,1,1,-1,-1}, dy[]= {-1,1,0,0,1,-1,1,-1};
		int tc = nextInt();
		for(int t=1;t<=tc;t++) {
			int n = nextInt();
			arr = new char[n][n];
			cnt = new int[n][n];
			boolean[][] visited = new boolean[n][n];
			
			int cntBomb=0;
			for(int i=0;i<n;i++) {
				String str = br.readLine();
				for(int j=0;j<n;j++) {
					arr[i][j] = str.charAt(j);
					if(arr[i][j]=='*') {
						cntBomb++;
						for(int r=Math.max(0, i-1);r<=Math.min(n-1, i+1);r++) {
							for(int c=Math.max(0, j-1);c<=Math.min(n-1, j+1);c++) {
								cnt[r][c]++;
							}
						}
					}
				}
			}
			
			int answer=0;//몇번 클릭할거임?
			boolean click0=true;//주위에 폭탄 pos인것만 눌러볼거임
			int visitCnt=0;//밝힌 칸 개수
			while(visitCnt < n*n - cntBomb) {//전부 다 밝힐때까지
				for(int i=0;i<n;i++) {
					for(int j=0;j<n;j++) {
						if(arr[i][j] == '*')continue;//폭탄칸은 스킵
						if((!click0 || cnt[i][j]==0) && !visited[i][j]) {//처음에는 0일때만 확인
							answer++;
							//bw.write(i+ " " + j+'\n');
							visited[i][j]=true;
							visitCnt++;
							if(cnt[i][j]==0) {//0일때만 연쇄반응 일어남
								qu.add(new Node(i,j));
								while(!qu.isEmpty()) {
									Node cur = qu.poll();
									int r=cur.r, c=cur.c;
									if(cnt[r][c] == 0) {
										for(int k=0;k<8;k++) {
											int nr= r+dx[k], nc = c+dy[k];
											if(checkPos(nr,nc,n) && !visited[nr][nc] && arr[nr][nc]!='*') {
												qu.add(new Node(nr,nc));
												visited[nr][nc]=true;
												visitCnt++;
											}
										}
									}
								}
							}
						}
					}
				}
				click0=false;
			}
			
			bw.write("#"+t+" "+ answer+'\n');
		}
		bw.flush();
	}

}
