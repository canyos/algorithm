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
	static class Pair{
		int r;
		int c;
		Pair(int r, int c){
			this.r=r;
			this.c=c;
		}
	}
	
	static boolean checkPos(int r, int c, int n) {
		return r>=0 && r<n && c>=0 && c<n;
	}
	static List<Pair>[] list;
	static int cnt[];
	static int[] dr = {0,0,1,-1};
	static int[] dc = {1,-1,0,0};
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int n = nextInt();
		int arr[][] = new int[n][n];
		for(int i=0;i<n;i++) {
			String str = br.readLine();
			for(int j=0;j<n;j++)
				arr[i][j] = str.charAt(j)-'0';
		}
			
		
		boolean visited[][] = new boolean[n][n];
		Queue<Pair> qu = new LinkedList<>();
		int answer=0;
		List<Integer> cntList=new ArrayList<>();
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(!visited[i][j] && arr[i][j]==1) {
					qu.add(new Pair(i,j));
					visited[i][j]=true;
					answer++;
					int cnt=0;
					while(!qu.isEmpty()) {
						Pair cur = qu.poll();
						cnt++;
						for(int k=0;k<4;k++) {
							int nr = cur.r+dr[k], nc = cur.c+dc[k];
							if(checkPos(nr,nc,n) && !visited[nr][nc] && arr[nr][nc]==1) {
								qu.add(new Pair(nr,nc));
								visited[nr][nc]=true;
							}
						}
					}
					cntList.add(cnt);
				}
			}
		}
		System.out.println(answer);
		cntList.sort(Comparator.naturalOrder());
		for(int a : cntList)
			System.out.println(a);
	}

}
