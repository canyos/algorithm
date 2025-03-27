import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;
import java.util.StringTokenizer;

public class Solution {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;

	public static int nextInt() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());	
		}
		return Integer.parseInt(st.nextToken());
	}
	
	static class Edge{
		int start;
		int end;
		int cost;
		Edge(int start, int end, int cost){
			this.start=start;
			this.end=end;
			this.cost = cost;
		}
	}
	
	public static List<Edge> edges;
	public static int par[];
	
	public static int find(int a) {
		if(par[a] == a)
			return a;
		return par[a] = find(par[a]);
	}
	
	public static boolean union(int a, int b) {
		int x= find(a), y= find(b);
		if(x==y)
			return false;
		
		par[x] = y;
		return true;
	}
	
	public static void main(String[] args) throws Exception{
		int tc = nextInt();
		for(int t=1;t<=tc;t++) {
			edges=new ArrayList<>();

			int n= nextInt(), m = nextInt();
			par = new int[n+1];
			for(int i=1;i<=n;i++) {
				par[i] = i;
			}
			int a,b,c;
			for(int i=0;i<m;i++) {
				a = nextInt(); b=nextInt();c=nextInt();
				edges.add(new Edge(a,b,c));
			}
			
			edges.sort((e1,e2)-> e1.cost - e2.cost);
			
			long answer=0L;
			for(Edge e : edges) {
				if(union(e.start,e.end)) {
					answer+=e.cost;
				}
			}
				
			
			bw.write("#"+t+" " + answer + "\n");
		}
		bw.flush();
	}

}
