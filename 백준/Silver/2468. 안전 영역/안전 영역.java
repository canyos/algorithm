import java.util.*;
public class Main {
	static int arr[][];
	static int n;
	static int dr[] = {0,0,-1,1}, dc[] = {-1,1,0,0};
	public static class Pair{
		int r;
		int c;
		Pair(int r, int c){
			this.r=r;
			this.c=c;
		}
	}
	
	public static boolean checkPos(int r, int c, int limit) {
		return r>=0 && r<n && c>=0 && c<n && arr[r][c]>limit;
	}

	public static void main(String[] args){
		//--------------솔루션 코드를 작성하세요.--------------------------------
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		arr = new int[n][n];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				arr[i][j] = sc.nextInt();
		
		int answer=0;
		for(int i=0;i<100;i++) {//알레르기 농도
			boolean visited[][] = new boolean[n][n];
			int cnt=0;
			Queue<Pair> qu = new LinkedList<>();
			for(int r=0;r<n;r++) {
				for(int c=0;c<n;c++) {
					if(!visited[r][c] && arr[r][c] > i) {
						cnt++;
						qu.add(new Pair(r,c));
						visited[r][c] = true;
						while(!qu.isEmpty()) {
							Pair cur = qu.poll();
							
							for(int k=0;k<4;k++) {
								int tr = cur.r + dr[k];
								int tc = cur.c + dc[k];
								if(checkPos(tr,tc,i) && !visited[tr][tc]) {
									qu.add(new Pair(tr,tc));
									visited[tr][tc]=true;
								}
							}
						}
					}
				}
			}
			
			answer = Math.max(cnt, answer);
		}
		System.out.println(answer);
	}

}
