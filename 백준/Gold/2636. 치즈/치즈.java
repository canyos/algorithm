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
	public static class Pair{
		int r;
		int c;
		Pair(int r, int c){
			this.r=r;
			this.c=c;
		}
	}
	
	public static boolean checkPos(int r,int c,int n, int m) {
		return r>=0 && r<n && c>=0 && c<m;
	}
	static int hour, cnt;
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int n = nextInt();
		int m = nextInt();
		int arr[][] = new int[n][m];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				arr[i][j] = nextInt();
		Queue<Pair> qu = new LinkedList<>();
		int dx[] = {0,0,-1,1},dy[] = {1,-1,0,0};
		while(true) {
			int sum=0;
			boolean visited[][] = new boolean[n][m];
			boolean melt[][] = new boolean[n][m];
			qu.add(new Pair(0,0));
			visited[0][0]=true;
			while(!qu.isEmpty()) {
				Pair p = qu.poll();
				int r= p.r, c= p.c;
				for(int k=0;k<4;k++) {
					int nr = r+dx[k], nc = c+dy[k];
					if(checkPos(nr,nc,n,m)) {
						if(!visited[nr][nc] && arr[nr][nc]==0) {
							qu.add(new Pair(nr,nc));
							visited[nr][nc]=true;
						}
						else if(arr[nr][nc]==1 && !melt[nr][nc]) {
							sum++;
							melt[nr][nc]=true;
						}
					}
				}
			}

			
			if(sum==0)break;
			
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(melt[i][j])
						arr[i][j]=0;
				}
			}
			
			cnt=sum;
			hour++;
		}
		
		
		bw.write(hour+"\n"+cnt);
		bw.flush();
	}

}
