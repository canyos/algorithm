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
		int dist;
		Pair(int r, int c){
			this.r=r;
			this.c=c;
		}
		Pair(int r, int c, int dist){
			this.r=r;
			this.c=c;
			this.dist = dist;
		}
	}
	static int dx[] = {0,-1,0,1,1,1,-1,-1}, dy[]= {-1,0,1,0,1,-1,1,-1};
	
	public static boolean checkPos(int r,int c,int n, int m) {
		return r>=0 && r<n && c>=0 && c<m;
	}
	public static boolean nextPermutation(int arr[]) {
		int i = arr.length-1;
		while(i>0 && arr[i-1]>=arr[i])i--;
		if(i==0) 
			return false;
		int j = arr.length-1;
		while(arr[i-1] >= arr[j]) j--;
		
		int temp = arr[i-1];
		arr[i-1] = arr[j];
		arr[j] = temp;
		
		int k=arr.length-1;
		while(i<k) {
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
			i++;
			k--;
		}
		
		return true;
	}
	static Queue<Pair> qu = new LinkedList<>();
	public static void main(String[] args) throws IOException {
		int n,m,d;
		n=nextInt();
		m=nextInt();
		d=nextInt();
		int arr[][] = new int[n][m];
		int map[][] = new int[n][m];
		int cnt=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++) {
				map[i][j] = nextInt();
				cnt++;
			}
				
		
		int archer[] = new int[m];
		for(int i=m-3;i<m;i++) 
			archer[i]=1;
		
		int answer=0;
		do {
			for(int i=0;i<n;i++) 
				for(int j=0;j<m;j++) 
					arr[i][j] = map[i][j];

			int sum=0;
			for(int i=0;i<n;i++) {//턴수
				List<Pair> removeList = new ArrayList<>();
				for(int a = 0;a<m;a++) {//궁수 마다 적찾기
					if(archer[a]==0)continue;
					boolean visited[][] = new boolean[n][m];
					qu.add(new Pair(n,a,0));
					loop: while(!qu.isEmpty()) {
						Pair cur = qu.poll();
						int r = cur.r, c= cur.c, dist =cur.dist;
						
						if(dist==d)continue;
						
						for(int k=0;k<3;k++) {
							int nr = r+dx[k], nc = c + dy[k];
							if(checkPos(nr,nc,n,m) && !visited[nr][nc] && arr[nr][nc]==0) {
								qu.add(new Pair(nr,nc,dist+1));
								visited[nr][nc]=true;
							}
							else if(checkPos(nr,nc,n,m) &&  arr[nr][nc]==1 && dist < d) {
								removeList.add(new Pair(nr,nc));
								qu= new LinkedList<>();
								break loop;
							}
						}
					}
				}
				for(Pair p : removeList) {//활 맞는 적 체크
					if(arr[p.r][p.c]==1) {
						arr[p.r][p.c]=0;
						sum++;
					}
				}
				
				for(int r=n-1;r>0;r--) {//적 한칸씩 내려옴
					for(int c=0;c<m;c++) {
						arr[r][c] = arr[r-1][c];
					}
				}
				for(int c=0;c<m;c++) {
					arr[0][c] = 0;
				}
			}

			answer=Math.max(answer, sum);
			if(answer==cnt)break;
		}while(nextPermutation(archer));
		
		System.out.println(answer);
	}

}
