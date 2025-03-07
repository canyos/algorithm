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
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		int tc = nextInt();
		int answer;
		for(int t=1;t<=tc;t++) {
			answer=0;
			int n = nextInt(), d = nextInt();
			int arr[] = new int[n];
			for(int i=0;i<n;i++)
				arr[i] = nextInt();
			
			int dist=0;
			for(int i=0;i<n;i++) {
				if(arr[i]==1)
					dist=0;
				else
					dist++;
				if(dist==d) {
					dist=0;
					answer++;
				}
			}
			
			bw.write("#"+t + " " + answer+"\n");
			
		}
		bw.flush();
	}

}
