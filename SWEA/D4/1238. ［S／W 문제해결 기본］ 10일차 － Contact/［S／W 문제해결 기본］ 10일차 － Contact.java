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
	
	static class Pair{
		int num;
		int depth;
		Pair(int num, int depth){
			this.num=num;
			this.depth=depth;
		}
	}
	
	public static List<List<Integer>> edges;
	
	
	public static void main(String[] args) throws Exception{
		for(int t=1;t<=10;t++) {
			edges=new ArrayList<>();
			int n= nextInt(), start = nextInt();
			for(int i=0;i<=100;i++) {
				edges.add(new ArrayList<>());
			}
			for(int i=0;i<n/2;i++) {
				int a = nextInt(), b=nextInt();
				edges.get(a).add(b);
			}
			
			Pair answer = new Pair(start,0);
			Queue<Pair> qu = new LinkedList<>();
			qu.add(new Pair(start,0));
			boolean visited[] = new boolean[101];
			visited[start]=true;
			
			while(!qu.isEmpty()) {
				Pair v = qu.poll();
				int cur = v.num, depth = v.depth;
				if(answer.depth == depth) {
					answer = answer.num>cur?answer:v;
				}else {
					answer = v;
				}
				for(int next : edges.get(cur)) {
					if(!visited[next]) {
						qu.add(new Pair(next, depth+1));
						visited[next]=true;
					}
				}
			}
			bw.write("#"+t+" " + answer.num + "\n");
		}
		bw.flush();
	}

}
