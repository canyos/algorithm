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
	static List<List<Integer>> edge= new ArrayList<>();
	static boolean visited[];
	static int dx[] = {0,0,1,-1,1,1,-1,-1},dy[] = {1,-1,0,0,1,-1,1,-1};
	static Queue<node> qu = new LinkedList<>();
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int n = nextInt();
		for(int i=0;i<n+1;i++)
			edge.add(new ArrayList<>());
		visited = new boolean[n+1];
		int a = nextInt();
		int b = nextInt();
		
		int m = nextInt();
		int s,e;
		for(int i=0;i<m;i++) {
			s=nextInt();
			e=nextInt();
			edge.get(s).add(e);
			edge.get(e).add(s);
		}
		
		int answer=-1;
		qu.add(new node(a,0));
		visited[a]=true;
		while(!qu.isEmpty()) {
			node cur = qu.poll();
			if(cur.cur == b) {
				answer = cur.cnt;
				break;
			}
			for(int next : edge.get(cur.cur)) {
				if(!visited[next]) {
					qu.add(new node(next,cur.cnt+1));
					visited[next]=true;
				}
			}
		}
		
		System.out.println(answer);
	}

}
