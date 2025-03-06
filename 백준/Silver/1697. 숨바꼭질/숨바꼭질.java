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
	
	public static class node{
		int cur;
		int cnt;
		node(int a, int b){
			this.cur=a;
			this.cnt=b;
		}
	}
	
	static boolean visited[];
	static int dx[] = {0,0,1,-1,1,1,-1,-1},dy[] = {1,-1,0,0,1,-1,1,-1};
	static Queue<node> qu = new LinkedList<>();
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int n = nextInt();
		int k = nextInt();
		visited = new boolean[200001];
		qu.add(new node(n,0));
		visited[n]=true;
		
		int answer=-1;
		while(!qu.isEmpty()) {
			node cur = qu.poll();
			if(cur.cur == k) {
				answer = cur.cnt;
				break;
			}
			if(cur.cur+1<=200000 && !visited[cur.cur+1] ) {
				qu.add(new node(cur.cur+1,cur.cnt+1));
				visited[cur.cur+1]=true;
			}
			if(cur.cur>0 && !visited[cur.cur-1] )
			{
				qu.add(new node(cur.cur-1,cur.cnt+1));
				visited[cur.cur-1]=true;
			}
			if(cur.cur*2<=200000 && !visited[cur.cur*2]) {

				qu.add(new node(cur.cur*2,cur.cnt+1));
				visited[cur.cur*2]=true;
			}
		}
		System.out.println(answer);
	}

}
