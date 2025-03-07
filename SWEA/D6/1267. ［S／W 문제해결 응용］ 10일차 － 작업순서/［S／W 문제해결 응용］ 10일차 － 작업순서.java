import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	public static int nextInt() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());
		}
		return Integer.parseInt(st.nextToken());
	}	
	static List<Integer> edges[] ;
	static int cnt[];
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		//int tc = nextInt();
		for(int t=1;t<=10;t++) {
			int v = nextInt();
			int e = nextInt();
			edges= new ArrayList[v+1];
			cnt  = new int[v+1];
			for(int i=1;i<v+1;i++)
				edges[i] = new ArrayList<>();
			
			int a,b;
			for(int i=0;i<e;i++) {
				a=nextInt();b=nextInt();
				edges[a].add(b);
				cnt[b]++;
			}
			
			Queue<Integer> qu = new LinkedList<>();
			for(int i=1;i<v+1;i++) {
				if(cnt[i]==0)
					qu.add(i);
			}
			bw.write("#"+t+" ");
			while(!qu.isEmpty()) {
				int cur = qu.poll();
				bw.write(cur + " ");
				for(int next : edges[cur]) {
					cnt[next]--;
					if(cnt[next]==0) {
						qu.add(next);
					}
				}
			}
			bw.write("\n");			
		}
		bw.flush();
	}

}
