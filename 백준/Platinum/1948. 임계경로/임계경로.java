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

	static class Edge{
		int dest;
		int cost;
		Edge(int d, int c){
			this.dest = d;
			this.cost = c;
		}
	}
	
	static class Node{
		int num;
		int cost;
		int cnt;
		Node(int num, int cost,int cnt){
			this.num=num;
			this.cost=cost;
			this.cnt = cnt;
		}
	}
	
	static List<List<Edge>> edges = new ArrayList<>();
	static List<List<Edge>> redges = new ArrayList<>();
	static Queue<Integer>qu = new LinkedList<>();
	static int cnt[];
	static int maxCost[];
	static int edgeCnt[];
	public static void main(String[] args) throws IOException {	
		int n = nextInt(), m = nextInt();
		cnt = new int[n+1];
		maxCost = new int[n+1];
		edgeCnt = new int [n+1];
		for(int i=0;i<n+1;i++) {
			edges.add(new ArrayList<>());
			redges.add(new ArrayList<>());
		}
		
		for(int i=0;i<m;i++) {
			int a=nextInt(),b=nextInt(),c=nextInt();
			edges.get(a).add(new Edge(b,c));
			redges.get(b).add(new Edge(a,c));
			cnt[b]++;
		}
		
		int start = nextInt(), dest = nextInt();
		
		qu.add(start);
		
		while(!qu.isEmpty()) {
			int cur = qu.poll();
			for(Edge e : edges.get(cur)) {
				cnt[e.dest]--;
				maxCost[e.dest] = Math.max(maxCost[e.dest], maxCost[cur]+e.cost);
				
				if(cnt[e.dest]==0) {
					qu.add(e.dest);
				}
			}
		}
		
		
		int answer=0;
		qu.add(dest);
		boolean visited[] = new boolean[n+1];
		while(!qu.isEmpty()) {
			int cur = qu.poll();
			if(visited[cur])continue;
			visited[cur]=true;
			for(Edge e: redges.get(cur)) {
				if(maxCost[cur] - e.cost == maxCost[e.dest]){
					answer++;
					qu.add(e.dest);
				}
			}
		}
		
		
		
		System.out.println(maxCost[dest]);
		System.out.println(answer);
	}

}
