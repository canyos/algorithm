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
	public static Double nextDouble() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());	
		}
		return Double.parseDouble(st.nextToken());
	}
	
	static class Edge{
		int start;
		int end;
		double cost;
		Edge(int start, int end, double cost){
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
			int n = nextInt();
			par = new int[n];
			long x[] = new long[n], y[] = new long[n];
			for(int i=1;i<n;i++)
				par[i] = i;
			for(int i=0;i<n;i++)
				x[i] = nextInt();
			for(int i=0;i<n;i++)
				y[i] = nextInt();
			
			double E = nextDouble();
			for(int i=0;i<n;i++) {
				for(int j=i+1;j<n;j++) {
					edges.add(new Edge(i,j,((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])) * E));
				}
			}
						
			edges.sort((e1,e2)-> e1.cost - e2.cost >=0? 1:-1);
			
			double answer=0.0;
			for(Edge e : edges) {
				if(union(e.start,e.end)) {
					answer+=e.cost;
				}
			}
				
			
			bw.write("#"+t+" " + (long) Math.round(answer) + "\n");
		}
		bw.flush();
	}

}
