import java.util.*;
import java.io.*;


public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static int n,K;
	static int arr[][];
	static int answer;
	static boolean visited[][];
	static int dr[] = {0,0,1,-1}, dc[] = {-1,1,0,0};
	static boolean checkPos(int r, int c) {
		return r>=0 && r<n && c>=0 && c<n;
	}
	static void recursive(int r, int c,int num, int len, boolean dig) {
		visited[r][c]= true;
		answer = Math.max(answer, len);
		for(int k=0;k<4;k++) {
			int tr = r+dr[k],tc=c+dc[k];
			if(checkPos(tr,tc)&& !visited[tr][tc]) {
				if(arr[tr][tc]<num ) {
					recursive(tr,tc,arr[tr][tc],len+1,dig);
				}else if(!dig && arr[tr][tc]-K<num) {//땅파서 이동
					recursive(tr,tc,num-1,len+1,true);
				}
			}
		}
		visited[r][c]=false;
	}
	
	public static void main(String[] args) throws Exception {
		int tc= nextInt();
		
		for(int t=1;t<=tc;t++) {
			answer=1;
			n = nextInt();K=nextInt();
			arr = new int [n][n];
			int maxValue=0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					arr[i][j] = nextInt();
					maxValue=Math.max(maxValue,arr[i][j]);
				}
			}
			
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(arr[i][j] == maxValue) {
						visited = new boolean [n][n];
						recursive(i,j,arr[i][j],1,false);
					}
				}
			}
						
			bw.write("#"+ t + " "+ answer + "\n");
		}
		bw.flush();
		
	}

	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
