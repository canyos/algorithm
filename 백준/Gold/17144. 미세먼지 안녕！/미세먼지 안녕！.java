import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static class Pair{
		int r;
		int c;
		Pair(int r, int c){
			this.r=r;
			this.c=c;
		}
	}
	static class Dust{
		int r;
		int c;
		int num;
		Dust(int r, int c, int n){
			this.r=r;
			this.c=c;
			this.num = n;
		}
	}
	
	static int n,m,t;
	static int arr[][];
	static int answer;
	static int x,y;
	static Queue<Pair> qu = new LinkedList<Main.Pair>();
	static Queue<Dust> dq = new LinkedList<>();
	static int dr[] = {0,0,1,-1}, dc[] = {-1,1,0,0};
	static boolean checkPos(int r,int c) {
		return r>=0 && r<n && c>=0 && c<m;
	}

	public static void main(String[] args)throws Exception {
		n = nextInt(); m = nextInt(); t=nextInt();
		arr = new int[n][m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				arr[i][j] = nextInt();
				if(arr[i][j]>0) {
					qu.add(new Pair(i,j));
				}
				if(arr[i][j]==-1) {
					x=i;y=j;
				}
			}
		}
		
		
		while(t>0) {
			int sz = qu.size();
			while(sz>0) {
				sz--;
				Pair cur = qu.poll();
				int sum=0;
				for(int k=0;k<4;k++) {
					int tr = cur.r+dr[k],tc=cur.c+dc[k];
					if(checkPos(tr,tc) && arr[tr][tc]!=-1) {
						int a = arr[cur.r][cur.c]/5;
						if(a>0) {
							dq.add(new Dust(tr,tc,arr[cur.r][cur.c]/5));
							sum+=arr[cur.r][cur.c]/5;
						}
					}
				}
				dq.add(new Dust(cur.r,cur.c,arr[cur.r][cur.c]-sum));
			}
			
			arr = new int [n][m];
			arr[x][y] = arr[x-1][y] = -1;
			while(!dq.isEmpty()) {
				Dust cur = dq.poll();
				arr[cur.r][cur.c]+=cur.num;
			}
			
			for(int i=y-1;i>=0;i--) {//오른쪽으로 한칸씩 이동
				if(arr[x-1][i+1]==-1)continue;
				arr[x-1][i+1] = arr[x-1][i];
			}
			for(int i=x-2;i>=0;i--) {//아래로 한칸씩 이동
				if(arr[i+1][y]==-1)continue;
				arr[i+1][y] = arr[i][y];
			}
			for(int i=1;i<m;i++) {//왼쪽으로 한칸씩 이동
				if(arr[0][i-1]==-1)continue;
				arr[0][i-1] = arr[0][i]; 
			}
			for(int i=1;i<=x-1;i++) {//위쪽으로 이동
				if(arr[i-1][m-1]==-1)continue;
				arr[i-1][m-1] = arr[i][m-1];
			}
			for(int i=m-2;i>y;i--) {//오른쪽으로 이동
				if(arr[x-1][i+1]==-1)continue;
				arr[x-1][i+1] = arr[x-1][i];
			}
			if(y==m-1)
				arr[x-2][y]=0;
			else
				arr[x-1][y+1]=0;
			
			
			for(int j=y-1;j>=0;j--) {
				if(arr[x][j+1]==-1)continue;
				arr[x][j+1] = arr[x][j];
			}
			for(int i=x+1;i<n;i++) {
				if(arr[i-1][0]==-1)continue;
				arr[i-1][0] = arr[i][0];
			}
			for(int j=1;j<m;j++) {
				if(arr[n-1][j-1]==-1)continue;
				arr[n-1][j-1] = arr[n-1][j];
			}
			for(int i=n-2;i>=x;i--) {
				if(arr[i+1][m-1]==-1)continue;
				arr[i+1][m-1] = arr[i][m-1];
			}
			for(int j=m-2;j>y;j--) {
				if(arr[x][j+1]==-1)continue;
				arr[x][j+1] = arr[x][j];
			}
			if(y==m-1)
				arr[x+1][y]=0;
			else
				arr[x][y+1]=0;
			
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(arr[i][j]>0) {
						qu.add(new Pair(i,j));
					}
				}
			}
			
			t--;
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(arr[i][j]>0)
					answer+=arr[i][j];
			}
		}
		System.out.println(answer);
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
