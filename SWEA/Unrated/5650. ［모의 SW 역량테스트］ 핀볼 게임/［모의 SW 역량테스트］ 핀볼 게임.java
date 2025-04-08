import java.util.*;
import java.io.*;


public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static Scanner scanner = new Scanner(System.in);
	static class Pair{
		int r;
		int c;
		Pair(int r,int c){
			this.r=r;
			this.c=c;
		}
	}
	
	static int n;
	static int arr[][];
	static int answer;
	static int dr[] = {0,0,1,-1}, dc[] = {-1,1,0,0};
	static Pair[][] hole;
	static int sr,sc;
	static boolean visited;
	static boolean checkPos(int r,int c) {
		return r>=0 && r<n && c>=0 && c<n;
	}
	
	static void simulation(int r,int c, int dir, int cnt) {
		while(checkPos(r,c) && arr[r][c]==0) {
			if(sr==r && sc==c ) {
				if(!visited)visited=true;
				else {
					answer =Math.max(answer, cnt);
					return;
				}
			}
			r+=dr[dir];c+=dc[dir];
		}
		if(!checkPos(r,c)) {//벽에박음
			answer = Math.max(answer, cnt*2+1);
			return;
		}
		else if(arr[r][c]==-1) { //블랙홀빠짐
			answer =Math.max(answer, cnt);
			return;
		}else if(arr[r][c]>=6){//웜홀
			int num = arr[r][c];
			if(hole[num][0].r==r && hole[num][0].c==c) {//0번구멍에빠짐
				simulation(hole[num][1].r+dr[dir], hole[num][1].c+dc[dir],dir,cnt);
			}else {
				simulation(hole[num][0].r+dr[dir], hole[num][0].c+dc[dir],dir,cnt);
			}
		}else { //방향바뀜
			if(dir==0) {//왼쪽
				if(arr[r][c]==1) 
					simulation(r-1,c,3,cnt+1);//위
				else if (arr[r][c]==2) 
					simulation(r+1,c,2,cnt+1);//아래
				else 
					simulation(r,c+1,1,cnt+1);//오른쪽
			}
			if(dir==1) {//오른쪽
				if(arr[r][c]==3)
					simulation(r+1,c,2,cnt+1);//아래
				else if(arr[r][c]==4)
					simulation(r-1,c,3,cnt+1);//위
				else
					simulation(r,c-1,0,cnt+1);//왼쪽
			}
			if(dir==2) {//아래
				if(arr[r][c]==1)
					simulation(r,c+1,1,cnt+1);//오른쪽
				else if(arr[r][c]==4)
					simulation(r,c-1,0,cnt+1);//왼쪽
				else
					simulation(r-1,c,3,cnt+1);//위쪽
			}
			if(dir==3) {//위
				if(arr[r][c]==2)
					simulation(r,c+1,1,cnt+1);
				else if(arr[r][c]==3)
					simulation(r,c-1,0,cnt+1);
				else
					simulation(r+1,c,2,cnt+1);
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		int tc= scanner.nextInt();
		
		for(int t=1;t<=tc;t++) {
			answer=0;
			n=scanner.nextInt();
			hole = new Pair[11][2];
			arr = new int [n][n];
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					arr[i][j] = scanner.nextInt();
					if(arr[i][j] >5) {
						if(hole[arr[i][j]][0]==null) 
							hole[arr[i][j]][0]= new Pair(i,j);
						else 
							hole[arr[i][j]][1] = new Pair(i,j);		
					}
				}
			}
			
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(arr[i][j] != 0) continue;
					for(int k=0;k<4;k++) {
						sr=i; sc=j;
						simulation(i,j,k,0);
						visited=false;
					}
				}
			}
//			sr=0; sc=4;
//			simulation(0,4,1,0);
			bw.write("#"+t+" " + answer+"\n");
			
		}
		bw.flush();
		
	}

	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return Integer.parseInt(st.nextToken());
	}
}
