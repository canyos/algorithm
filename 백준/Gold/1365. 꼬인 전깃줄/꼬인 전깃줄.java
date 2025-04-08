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
		arr = new int[n];
		int sel[] = new int [n];
		int pos=0;
		
		int num;
		for(int i=0;i<n;i++) {
			num = nextInt();
			if(pos==0 || sel[pos-1]<num) {
				sel[pos++]=num;
			}
			else {
				int idx = Math.abs(Arrays.binarySearch(sel, 0, pos, num))-1;
				sel[idx]=num;
			}
		}
		
		System.out.println(n-pos);		
		
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
