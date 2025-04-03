import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static int n;
	static int arr[];

	static int recursive(int num) {
		if(arr[num]>0) {
			return arr[num];
		}
		if(num==1) {
			return 0;
		}
		int res = n-1;
		if(num%3==0) {
			res = Math.min(res, recursive(num/3)+1);
		}
		if(num%2==0) {
			res = Math.min(res,  recursive(num/2)+1);
		}
		res = Math.min(res, recursive(num-1)+1);
		arr[num] = res;
		return res;
	}
	
	public static void main(String[] args)throws Exception {
		arr= new int[1000001];
		n = nextInt();
		int res = recursive(n);
		System.out.println(res);
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
