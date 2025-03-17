import java.util.*;
import java.io.*;
public class Main {
	
	public static class Node{
		int num;
		int depth;
		Node(int n, int d){
			this.num = n;
			this.depth = d;
		}
	}
	
	public static void main(String[] args) throws IOException{
		//--------------솔루션 코드를 작성하세요.--------------------------------
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int answer=0;
		
		int n = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int m = Integer.parseInt(st.nextToken());
		
		boolean visited[] = new boolean[n+1];
		List<List<Integer>> edges = new ArrayList<>();
		for(int i=0;i<n+1;i++) {
			edges.add(new ArrayList<>());
		}
		
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			edges.get(a).add(b);
			edges.get(b).add(a);
		}
		
		Queue<Node> qu = new LinkedList<>();
		qu.add(new Node(1,0));
		visited[1] = true;
		while(!qu.isEmpty()) {
			Node cur = qu.poll();
			if(cur.depth==2)continue;
			for(int next : edges.get(cur.num)) {
				if(!visited[next]) {
					qu.add(new Node(next,cur.depth+1));
					visited[next] = true;
				}
			}
		}
		
		for(int i=1;i<=n;i++) {
			if(visited[i])
				answer++;
		}
		
		bw.write(String.valueOf(answer-1));
		bw.flush();
	
	}

}
