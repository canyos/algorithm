import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Solution {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	public static int arr[];
	public static int nextInt() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());	
		}
		return Integer.parseInt(st.nextToken());
	}
	
	public static int find(int a) {
		if(arr[a] == a)
			return a;
		return arr[a] = find(arr[a]);
	}
	
	public static void union(int a, int b) {
		arr[find(b)] = find(a);
	}
	
	
	public static void main(String[] args) throws Exception{
		
		int tc = nextInt();
		for(int t=1;t<=tc;t++) {
			
			int n = nextInt(), m= nextInt();
			arr = new int[n+1];
			for(int i=1;i<=n;i++)
				arr[i] = i;
			
			int a,b;
			for(int i=0;i<m;i++) {
				a=nextInt();b=nextInt();
				union(a,b);
			}
			
			int cnt=0;
			boolean visited[] = new boolean[n+1];
			for(int i=1;i<=n;i++) {
				int par = find(i);
				if(!visited[par]) {
					visited[par]=true;
					cnt++;
				}
			}
			
			bw.write("#"+t + " ");
			bw.write(String.valueOf(cnt) + "\n");
		}
		bw.flush();
	}

}
