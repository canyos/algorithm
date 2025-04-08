import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static int n;
	static int arr[];
	static int answer;
	
	static int lowerbound(int a[], int pos, int k) {
		int left=0, right=pos-1;
		
		while(left<right) {
			int mid = (left+right)/2;
			if(arr[mid]<k) {
				left = mid+1;
			}else {
				right = mid;
			}
		}
		return right;
	}

	
	public static void main(String[] args)throws Exception {
		n = nextInt();
		arr = new int[n];
		int pos=0;
		for(int i=0;i<n;i++) {
			int num = nextInt();
			if(pos==0 || arr[pos-1]<num)
				arr[pos++]=num;
			else {
				int idx = lowerbound(arr, pos, num);
				if(arr[idx]==num)continue;
				else arr[idx]=num;
			}
		}
		
		System.out.println(pos);		
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
