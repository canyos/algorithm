import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	public static int nextInt() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());	
		}
		return Integer.parseInt(st.nextToken());
	}

	public static int n,m;
	public static List<List<Integer>> edges = new ArrayList<>();
	public static boolean answer = false;
	public static boolean visited[];
	
	public static void dfs(int cur, int depth) {
		if(depth==4) {
			answer=true;
			return;
		}
		for(int next: edges.get(cur)) {
			if(!visited[next]) {
				visited[next]=true;
				dfs(next, depth+1);
				if(answer)return;
				visited[next]=false;
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		n = nextInt(); m= nextInt();
		for(int i=0;i<n;i++) {
			edges.add(new ArrayList<>());
		}
		
		int a,b;
		for(int i=0;i<m;i++) {
			a = nextInt();b=nextInt();
			edges.get(a).add(b);
			edges.get(b).add(a);
		}
		
		visited = new boolean[n];
		
		for(int i=0;i<n && !answer;i++) {
			visited[i] = true;
			dfs(i,0);
			visited[i]=false;
		}
		
		System.out.println(answer?1:0);
	}

}
