import java.util.*;
import java.io.*;


public class Main {
	public static class Train{
		int r;
		int c;
		int dir;//1가로 0세로
		int cnt;
		Train(int r, int c, int d){
			this.r=r;
			this.c=c;
			this.dir=d;
			this.cnt = 0;
		}
		Train(int r, int c, int d,int cnt){
			this.r=r;
			this.c=c;
			this.dir=d;
			this.cnt = cnt;
		}
	}
	public static void main(String[] args) throws IOException{
		//--------------솔루션 코드를 작성하세요.--------------------------------
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n  = Integer.parseInt(st.nextToken());
		
		char arr[][] = new char[n][n];
		for(int i=0;i<n;i++) {
			String str = br.readLine();
			for(int j=0;j<n;j++) {
				arr[i][j] = str.charAt(j);
			}
		}
		
		boolean visited[][][] = new boolean[n][n][2];
		Train begin = new Train(-1,-1,0);
		Train end = new Train(-1,-1,0);
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(arr[i][j]=='B') {
					if((i>0 && arr[i-1][j]=='B') && (i<n-1 && arr[i+1][j]=='B')){
						begin = new Train(i,j,0);
					}
					if((j>0 && arr[i][j-1]=='B') && (j<n-1 && arr[i][j+1]=='B')){
						begin = new Train(i,j,1);
					}
					
				}
				if(arr[i][j]=='E') {
					if((i>0 && arr[i-1][j]=='E') && (i<n-1 && arr[i+1][j]=='E')){
						end = new Train(i,j,0);
					}
					if((j>0 && arr[i][j-1]=='E') && (j<n-1 && arr[i][j+1]=='E')){
						end = new Train(i,j,1);
					}
				}
			}
		}
		int answer=0;
		
		Queue<Train> qu = new LinkedList<>();
		qu.add(begin);
		visited[begin.r][begin.c][begin.dir]=true;
		while(!qu.isEmpty()) {
			Train cur = qu.poll();
			if(cur.r == end.r && cur.c == end.c && cur.dir == end.dir) {
				answer = cur.cnt;
				break;
			}
			
			//세로
			if(cur.dir==0) {
				//왼쪽
				if(cur.c>0&& !visited[cur.r][cur.c-1][0] && arr[cur.r-1][cur.c-1]!='1' && arr[cur.r][cur.c-1] !='1' && arr[cur.r+1][cur.c-1]!='1') {
					qu.add(new Train(cur.r,cur.c-1,0,cur.cnt+1));
					visited[cur.r][cur.c-1][0] = true;
				}
				//오른쪽
				if(cur.c<n-1&& !visited[cur.r][cur.c+1][0] && arr[cur.r-1][cur.c+1]!='1' && arr[cur.r][cur.c+1] !='1' && arr[cur.r+1][cur.c+1]!='1') {
					qu.add(new Train(cur.r,cur.c+1,0,cur.cnt+1));
					visited[cur.r][cur.c+1][0] = true;
				}
				//위
				if(cur.r>1&& !visited[cur.r-1][cur.c][0] && arr[cur.r-2][cur.c]!='1') {
					qu.add(new Train(cur.r-1,cur.c,0,cur.cnt+1));
					visited[cur.r-1][cur.c][0] = true;
				}
				//아래
				if(cur.r<n-2&& !visited[cur.r+1][cur.c][0] && arr[cur.r+2][cur.c]!='1') {
					qu.add(new Train(cur.r+1,cur.c,0,cur.cnt+1));
					visited[cur.r+1][cur.c][0] = true;
				}
				//회전
				if(cur.r>0 && cur.r<n-1 && cur.c>0 &&  cur.c<n-1 && !visited[cur.r][cur.c][1] &&
					arr[cur.r-1][cur.c-1]!='1' && arr[cur.r][cur.c-1] !='1' && arr[cur.r+1][cur.c-1]!='1' &&
					arr[cur.r-1][cur.c+1]!='1' && arr[cur.r][cur.c+1] !='1' && arr[cur.r+1][cur.c+1]!='1') {
					qu.add(new Train(cur.r,cur.c,1,cur.cnt+1));
					visited[cur.r][cur.c][1] = true;
				}
			}
			else {//가로
				//왼쪽
				if(cur.c>1&& !visited[cur.r][cur.c-1][1] && arr[cur.r][cur.c-2]!='1') {
					qu.add(new Train(cur.r,cur.c-1,1,cur.cnt+1));
					visited[cur.r][cur.c-1][1] = true;
				}
				//오른쪽
				if(cur.c<n-2 && !visited[cur.r][cur.c+1][1] && arr[cur.r][cur.c+2]!='1') {
					qu.add(new Train(cur.r,cur.c+1,1,cur.cnt+1));
					visited[cur.r][cur.c+1][1] = true;
				}
				//위
				if(cur.r>0&& !visited[cur.r-1][cur.c][1] && arr[cur.r-1][cur.c-1]!='1' && arr[cur.r-1][cur.c] !='1' && arr[cur.r-1][cur.c+1]!='1') {
					qu.add(new Train(cur.r-1,cur.c,1,cur.cnt+1));
					visited[cur.r-1][cur.c][1] = true;
				}
				//아래
				if(cur.r<n-1 && !visited[cur.r+1][cur.c][1] && arr[cur.r+1][cur.c-1]!='1' && arr[cur.r+1][cur.c] !='1' && arr[cur.r+1][cur.c+1]!='1') {
					qu.add(new Train(cur.r+1,cur.c,1,cur.cnt+1));
					visited[cur.r+1][cur.c][1] = true;
				}
				//회전
				if(cur.r>0 && cur.r<n-1 && cur.c>0 && cur.c<n-1 && !visited[cur.r][cur.c][0] &&
						arr[cur.r-1][cur.c-1]!='1' && arr[cur.r-1][cur.c] !='1' && arr[cur.r-1][cur.c+1]!='1' &&
						arr[cur.r+1][cur.c-1]!='1' && arr[cur.r+1][cur.c] !='1' && arr[cur.r+1][cur.c+1]!='1') {
					qu.add(new Train(cur.r,cur.c,0,cur.cnt+1));
					visited[cur.r][cur.c][0] = true;
				}
			}
			
		}
		
		
		bw.write(String.valueOf(answer));
		bw.flush();
		
		
	}

}
