import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static class Node implements Comparable<Node>{
		int num;
		int cost;
		Node(int num, int cost){
			this.num=num;
			this.cost=cost;
		}
		@Override
		public int compareTo(Node o) {
			return this.cost-o.cost;
		}
	}
	
	static class Node2 implements Comparable<Node2>{
		int num;
		int cost;
		int speed;
		Node2(int num, int cost, int s){
			this.num=num;
			this.cost=cost;
			this.speed=s;
		}
		@Override
		public int compareTo(Node2 o) {
			return this.cost-o.cost;
		}
	}
	
	static class Edge{
		int num;
		int cost;
		Edge(int num, int cost){
			this.num=num;
			this.cost=cost;
		}
	}
	static int n, m, k;
	static int dist[];
	static int dist2[][];
	static List<Edge> edges[];
	
	static PriorityQueue<Node> pq = new PriorityQueue<>();
	static PriorityQueue<Node2> pq2 = new PriorityQueue<>();

	public static void main(String[] args)throws Exception {
		n = nextInt(); m=nextInt();
		dist = new int[n+1];
		dist2 = new int[n+1][2];
		for(int i=1;i<=n;i++) {
			dist[i] = (int) 2e9;
			dist2[i][0] = (int) 2e9;
			dist2[i][1] = (int) 2e9;
		}
		edges = new ArrayList[n+1];
		for(int i=1;i<=n;i++) {
			edges[i] = new ArrayList<>();
		}
		
		for(int i=0;i<m;i++) {
			int a=nextInt(),b=nextInt(),c=nextInt();
			edges[a].add(new Edge(b,c*2));
			edges[b].add(new Edge(a,c*2));
		}
		
		pq.add(new Node(1,0));
		dist[1] = 0;
		while(!pq.isEmpty()) {
			Node cur = pq.poll();
			if(cur.cost > dist[cur.num])continue;
			for(Edge e : edges[cur.num]) {
				if(dist[e.num]>cur.cost + e.cost) {
					pq.add(new Node(e.num, cur.cost+e.cost));
					dist[e.num] = cur.cost+e.cost;
				}
			}
		}
		
		pq2.add(new Node2(1,0,1));
		dist2[1][0] = 0;//1에 느리게 도착
		while(!pq2.isEmpty()) {
			Node2 cur = pq2.poll();
			if(cur.cost > dist2[cur.num][(cur.speed+1)%2])continue;
			
			if(cur.speed==1) {//빠르게 갈수잇음
				for(Edge e : edges[cur.num]) {
					int nextCost = cur.cost + e.cost/2;
					if(dist2[e.num][1]>nextCost) {
						pq2.add(new Node2(e.num, nextCost,0));
						dist2[e.num][1]= nextCost;
					}
				}
			}else {//느리게가야함
				for(Edge e : edges[cur.num]) {
					int nextCost = cur.cost + e.cost*2;
					if(dist2[e.num][0]>nextCost) {
						pq2.add(new Node2(e.num, nextCost,1));
						dist2[e.num][0] = nextCost;
					}
				}
			}
		}
			
		int answer=0;
		for(int i=2;i<=n;i++) {
			if(dist[i]< dist2[i][0] && dist[i] <dist2[i][1]) {
				answer++;
			}
		}
		
//		for(int i=2;i<=n;i++) {
//			System.out.print(dist[i] + " ");
//		}
//		System.out.println();
//		for(int i=2;i<=n;i++) {
//			System.out.print(dist2[i][0] + " ");
//		}
//		System.out.println();
//		for(int i=2;i<=n;i++) {
//			System.out.print(dist2[i][1] + " ");
//		}
//		System.out.println();
		System.out.println(answer);
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
