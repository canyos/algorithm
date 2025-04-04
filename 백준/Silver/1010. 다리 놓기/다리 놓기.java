import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static int ncr[][];
	
	public static void main(String[] args)throws Exception {
		ncr=new int [31][31];
		for(int i=0;i<31;i++) {
			ncr[i][i]=1;
			ncr[i][0]=1;
			ncr[i][1]=i;
		}
		for(int i=3;i<31;i++) {
			for(int j=2;j<i;j++) {
				ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
			}
		}
		
		int tc=nextInt();
		for(int t=0;t<tc;t++) {
			int a = nextInt();
			int b = nextInt();
			System.out.println(ncr[b][a]);
		}
		
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
