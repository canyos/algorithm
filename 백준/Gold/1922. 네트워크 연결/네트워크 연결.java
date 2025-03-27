import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	public static int nextInt() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());	
		}
		return Integer.parseInt(st.nextToken());
	}

	public static class Pair{
		int a;
		int b;
		int c;
		Pair(int a,int b,int c){
			this.a=a;
			this.b=b;
			this.c=c;
		}
	}
	public static int n,m;
	public static int answer;
	public static List<Pair> edges = new ArrayList<>();
	public static int par[];
	
	public static int find(int a) {
		if(a==par[a])return a;
		return par[a] = find(par[a]);
	}
	public static boolean union(int a, int b) {
		int x= find(a);
		int y= find(b);
		if(x==y)return false;
		
		par[x] = y;
		return true;
	}
	public static void main(String[] args) throws Exception{
		n = nextInt(); m= nextInt();
		par = new int[n+1];
		for(int i=1;i<=n;i++)
			par[i] =i;
		
		int a,b,c;
		for(int i=0;i<m;i++) {
			a = nextInt();b=nextInt();c=nextInt();
			edges.add(new Pair(a,b,c));
		}
		
		edges.sort((e1,e2) -> e1.c - e2.c);
		
		for(Pair e : edges) {
			if(union(e.a,e.b)) {
				answer+= e.c;
			}
		}
		
		System.out.println(answer);
	}

}
