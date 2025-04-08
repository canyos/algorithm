import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static class Node{
		int r;
		int c;
		int key;
		int num;
		Node(int r, int c, int key, int num){
			this.r=r;
			this.c=c;
			this.key=key;
			this.num=num;
		}
	}
	
	static int n,m;
	static char arr[][];
	static boolean visited[][][];
	static int answer=-1;
	
	static Queue<Node> qu = new LinkedList<>();
	static int dr[] = {0,0,1,-1}, dc[] = {-1,1,0,0};
	static boolean checkPos(int r,int c) {
		return r>=0 && r<n && c>=0 && c<m;
	}

	public static void main(String[] args)throws Exception {
		n = nextInt(); m = nextInt(); 
		arr = new char[n][m];
		visited = new boolean [n][m][1<<8];
		
		for(int i=0;i<n;i++) {
			String str = br.readLine();
			for(int j=0;j<m;j++) {
				arr[i][j] = str.charAt(j);
				if(arr[i][j]=='0') {
					arr[i][j]='.';
					qu.add(new Node(i,j,0,0));
					visited[i][j][0]=true;
				}
			}
		}
		
		loop:while(!qu.isEmpty()) {
			Node cur = qu.poll();

			for(int k=0;k<4;k++) {
				int tr = cur.r+dr[k],tc=cur.c+dc[k];
				if(!checkPos(tr,tc) || arr[tr][tc]=='#')continue;
				if(arr[tr][tc]>='a' && arr[tr][tc]<='f' && !visited[tr][tc][cur.key|(1<<(arr[tr][tc]-'a'))]) {
					qu.add(new Node(tr,tc,cur.key|(1<<(arr[tr][tc]-'a')), cur.num+1));
					visited[tr][tc][cur.key|(1<<(arr[tr][tc]-'a'))]=true;
				}
				if(arr[tr][tc]>='A' && arr[tr][tc]<='F') {
					if((cur.key & (1 << (arr[tr][tc]-'A')))>0 && !visited[tr][tc][cur.key]){
						qu.add(new Node(tr,tc,cur.key,cur.num+1));
						visited[tr][tc][cur.key]=true;
					}
				}
				if(arr[tr][tc]=='.' && !visited[tr][tc][cur.key]) {
					qu.add(new Node(tr,tc,cur.key,cur.num+1));
					visited[tr][tc][cur.key]=true;
				}
				if(arr[tr][tc]=='1') {
					answer = cur.num+1;
					break loop;
				}
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
