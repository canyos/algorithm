import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static int n;
	static int arr[];

	public static void main(String[] args)throws Exception {
		n = nextInt();
		if(n==1) {
			System.out.println(1);
			return;
		}
		arr= new int[n+1];
		arr[1] = 1;
		arr[2] = 2;
		
		
		
		for(int i=3;i<=n;i++) {
			arr[i] = (arr[i-1]+arr[i-2])%10007;
		}
		
		System.out.println(arr[n]);
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
