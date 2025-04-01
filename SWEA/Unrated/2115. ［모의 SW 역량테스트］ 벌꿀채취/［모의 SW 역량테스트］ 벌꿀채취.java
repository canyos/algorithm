
import java.io.*;
import java.util.*;

public class Solution {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	
	static int N,M,C;
	static int arr[][];
	static int sel[][];
	public static int recursive(int r, int c, int pos, int sum, int squareSum) {
		if(pos == c-M) {
			if(sum<=C) 
				return squareSum;
			else
				return 0;
		}
		if(sum>C)return 0;
		
		int result = 0;
		
		result = recursive(r,c,pos-1,sum,squareSum);
		sum+=arr[r][pos];
		squareSum+=arr[r][pos]*arr[r][pos];
		result = Math.max(result, recursive(r,c,pos-1,sum,squareSum));
		
		return result;
		
	}
	
	public static void main(String[] args) throws Exception {
		int tc = nextInt();
		for(int t=1;t<=tc;t++) {
			int answer=-1;
			N = nextInt(); M=nextInt(); C=nextInt();
			arr = new int[N][N];
			sel = new int [N][N];
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++) 
					arr[i][j] = nextInt() ;
			
			for(int i=0;i<N;i++) {
				for(int j=M-1;j<N;j++) {
					sel[i][j] = recursive(i,j,j,0,0);
				}
			}
			
			List<Integer>list = new ArrayList<>();
			for(int i=0;i<N;i++) {
				int maxNum=0;
				for(int j=M-1;j<N;j++) {
					maxNum = Math.max(maxNum,sel[i][j]);
				}
				list.add(maxNum);
			}
			
			list.sort(Comparator.reverseOrder());
			
			answer = list.get(0)+list.get(1);
			
			bw.write("#"+t+ " " + answer+"\n");
		}
		bw.flush();
	}
	
	public static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());
		}
		return Integer.parseInt(st.nextToken());
	}
}
