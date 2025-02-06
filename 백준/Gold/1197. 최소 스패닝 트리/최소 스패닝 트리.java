import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.*;


public class Main {
	public static class Pair implements Comparable<Pair>{
		int first;
		int second;
		Pair(int first, int second){
			this.first = first;
			this.second = second;
		}
		
		
		public int compareTo(Pair o) {
			// TODO Auto-generated method stub
			return (this.first - o.first);
		}
	}
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		int v = Integer.parseInt(st.nextToken()), e = Integer.parseInt(st.nextToken());
		
		int answer=0;
		
		List<List<Pair>> edges = new ArrayList<>();
		for(int i=0;i<v+1;i++) 
			edges.add(new ArrayList<Pair>());
		
		for(int i=0;i<e;i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			edges.get(a).add(new Pair(b,c));
			edges.get(b).add(new Pair(a,c));
		}
		
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		boolean visited[] = new boolean[v+1];
		for(var p : edges.get(1)) {
			pq.add(new Pair(p.second, p.first));//코스트가 먼저 들어감
		}
		visited[1] = true;
		
		while(!pq.isEmpty()) {
			var edge = pq.poll();
			int cur = edge.second, cost = -edge.first;
			
			if(visited[cur])continue;
			visited[cur]=true;
			answer-=cost;
			
			for(var n : edges.get(cur)) {
				if(visited[n.first])continue;
				pq.add(new Pair(n.second, n.first));//코스트가 먼저 들어감
			}
		}
		System.out.println(answer);
	}
}
