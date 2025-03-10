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
	
	public static class Node{
		int r;
		int c;

		Node(int r, int c){
			this.r=r;
			this.c=c;
		}
	}
	
	static char[][] map;
	static int answer;
	static Queue<Node>qu = new LinkedList<>();
	static int dx[] = {0,-1,0,1,1,1,-1,-1}, dy[]= {-1,0,1,0,1,-1,1,-1};
	
	public static boolean checkPos(int r,int c,int n, int m) {
		return r>=0 && r<n && c>=0 && c<m;
	}
	
	public static void recursive(int pos, int seq[]) {
		if(pos == 7) {
			int cntS=0;
			for(int i=0;i<7;i++) {
				if(map[seq[i]/5][seq[i]%5] == 'S')
					cntS++;
			}
			if(cntS<4) 
				return;
			
			int cnt=0;
			qu.add(new Node(seq[0]/5, seq[0]%5));
			boolean visited[][] = new boolean[5][5];
			visited[seq[0]/5][seq[0]%5]=true;
			while(!qu.isEmpty()) {
				Node cur = qu.poll();
				cnt++;
				
				for(int k=0;k<4;k++) {
					int tr = cur.r + dx[k], tc = cur.c+dy[k];
					for(int i=1;i<7;i++) {
						if(checkPos(tr,tc,5,5) && tr*5+tc == seq[i] && !visited[tr][tc]) {
							qu.add(new Node(tr,tc));
							visited[tr][tc] = true;
						}
					}
					
				}
			}
			
			if(cnt==7)
				answer++;
			return ;
		}
		for(int i=(pos==0?0:seq[pos-1]+1);i<25;i++) {
			seq[pos] = i;
			recursive(pos+1,seq);
		}
	}
	
	public static void main(String[] args) throws IOException {
		map = new char[5][5];
		for(int i=0;i<5;i++) {
			String str = br.readLine();
			for(int j=0;j<5;j++) {
				map[i][j] = str.charAt(j);
			}
		}
		
		
		recursive(0,new int[7]);
		
		System.out.println(answer);
	}

}
