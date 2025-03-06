import java.util.*;
import java.io.*;
public class Main {
	static class coor{
		int r;
		int c;
		int cnt;
		coor(int r ,int c,int cnt){
			this.r= r;
			this.c=c;
			this.cnt=cnt;
		}
	}
	static int arr[][];
	static int dx[] = {0,0,1,-1},dy[] = {1,-1,0,0};
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		arr = new int[n][m];
		
		for(int i=0;i<n;i++) {
			String str = sc.next();
			for(int j=0;j<m;j++)
				arr[i][j] = str.charAt(j)-'0';
		}
			
		
		boolean visited[][] = new boolean[n][m];
		
		Queue<coor> qu = new LinkedList<>();
		qu.add(new coor(0,0,1));
		visited[0][0] = true;
		int answer=10001;
		while(!qu.isEmpty()) {
			coor v = qu.poll();
			int r = v.r, c= v.c;
			int cnt = v.cnt;
			//System.out.println(r + " " + c + " " + cnt);
			
			if(r==n-1 && c==m-1) {
				answer = Math.min(answer, cnt);
				break;
			}
			
			for(int i=0;i<4;i++) {
				int tr = r+dx[i];
				int tc = c+dy[i];
				if(tr>=0 && tr<n && tc>=0 && tc<m && !visited[tr][tc] && arr[tr][tc]==1) {
					qu.add(new coor(tr,tc,cnt+1));
					visited[tr][tc]=true;
				}
			}
			
		}
		
		System.out.println(answer);
	}

}
