import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static int n;
	static int arr[];
	static List<Integer>edge[];
	static int dp[][];
	static boolean visited[];
	static Queue<Integer> qu = new LinkedList<Integer>();
	
	static void recursive(int cur) {
		visited[cur]=true;
		dp[cur][0] = arr[cur];
		for(int next : edge[cur]) {
			if(!visited[next]) {
				recursive(next);
				dp[cur][0] += dp[next][1];
				dp[cur][1] += Math.max(dp[next][0], dp[next][1]); 
			}
		}
	}
	
	public static void main(String[] args)throws Exception {
		n = nextInt();
		arr = new int[n+1];
		dp= new int [n+1][2];
		visited = new boolean [n+1];
		edge = new LinkedList[n+1];
		for(int i=1;i<=n;i++) {
			edge[i] = new LinkedList<>();
			arr[i] = nextInt();
		}
		for(int i=0;i<n-1;i++) {
			int a=nextInt(),b=nextInt();
			edge[a].add(b);
			edge[b].add(a);
		}
		
		recursive(1);
		System.out.println(Math.max(dp[01][0], dp[01][1]));
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
