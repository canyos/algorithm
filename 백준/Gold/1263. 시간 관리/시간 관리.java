import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static class Pair implements Comparable<Pair>{
		int time;
		int limit;
		Pair(int a, int b){
			this.time=a;
			this.limit = b;
		}
		@Override
		public int compareTo(Pair o) {
			return this.limit - o.limit;
		}
	}
	
	static int n;
	static Pair arr[];
	static int answer=1000001;
	static PriorityQueue<Pair> pq = new PriorityQueue<>();
	
	public static void main(String[] args)throws Exception {
		n = nextInt();
		arr = new Pair[n];
		int a,b;
		for(int i=0;i<n;i++) {
			a=nextInt();b=nextInt();
			arr[i] = new Pair(a,b);
			pq.add(arr[i]);
		}
		
		int curTime=0;
		while(!pq.isEmpty()) {
			Pair cur = pq.poll();
			curTime+=cur.time;
			if(curTime>cur.limit) {
				answer=-1;
				break;
			}
			answer = Math.min(cur.limit-curTime,answer);
		}
		
		System.out.println(answer);
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
