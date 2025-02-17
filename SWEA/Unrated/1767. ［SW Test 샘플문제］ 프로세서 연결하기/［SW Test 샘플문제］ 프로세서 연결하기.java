import java.io.*;

import java.util.*;

public class Solution {
	static int answer=150;
	static List<Pair> list;
	static int arr[][];
	static int conMax;
	static class Pair{
		int first;
		int second;
		Pair(int first, int second){
			this.first = first;
			this.second = second;
		}
	}
	
	static void recursive(int cur, int cnt, int sum, int n, int con) {//몇번째 코어, 코어개수, 현재 합, 보드크기
		if(cur == cnt) {
			int aaa=1;
			aaa++;
			if(con>conMax) {
				answer = sum;
				conMax = con;
			}
				
			else if (con==conMax)
				answer = Math.min(answer, sum);
			return;
		}
		
		Pair core = list.get(cur);
		if(core.first==0 || core.second==0 || core.first==n-1 || core.second==n-1) {
			recursive(cur+1,cnt,sum,n, con+1);
			return;
		}
		
		int temp=0;
		boolean canFill=true;
		for(int r=core.first-1, c=core.second;r>=0;r--) {
			if(arr[r][c]>0) {
				canFill=false;
				break;
			}
		}
		
		if(canFill) {
			for(int r=core.first-1, c=core.second;r>=0;r--) {
				temp++;
				arr[r][c]=1;
			}
			recursive(cur+1, cnt, sum+temp, n, con+1);
			for(int r=core.first-1, c=core.second;r>=0;r--) {
				arr[r][c]=0;
			}
		}
		
		temp=0;
		canFill=true;
		for(int r=core.first+1, c=core.second;r<n;r++) {
			if(arr[r][c]>0) {
				canFill=false;
				break;
			}
		}
		
		if(canFill) {
			for(int r=core.first+1, c=core.second;r<n;r++) {
				temp++;
				arr[r][c]=1;
			}
			recursive(cur+1, cnt, sum+temp, n, con+1 );
			for(int r=core.first+1, c=core.second;r<n;r++) {
				arr[r][c]=0;
			}
		}
		
		temp=0;
		canFill=true;
		for(int r=core.first, c=core.second-1;c>=0;c--) {
			if(arr[r][c]>0) {
				canFill=false;
				break;
			}
		}
		
		if(canFill) {
			for(int r=core.first, c=core.second-1;c>=0;c--) {
				temp++;
				arr[r][c]=1;
			}
			recursive(cur+1, cnt, sum+temp, n, con+1);
			for(int r=core.first, c=core.second-1;c>=0;c--) {
				arr[r][c]=0;
			}
		}
		
		temp=0;
		canFill=true;
		for(int r=core.first, c=core.second+1;c<n;c++) {
			if(arr[r][c]>0) {
				canFill=false;
				break;
			}
		}
		
		if(canFill) {
			for(int r=core.first, c=core.second+1;c<n;c++) {
				temp++;
				arr[r][c]=1;
			}
			recursive(cur+1, cnt, sum+temp, n, con+1);
			for(int r=core.first, c=core.second+1;c<n;c++) {
				arr[r][c]=0;
			}
		}
		
		recursive(cur+1,cnt,sum,n, con);
	}
	
	public static void main(String[] args) throws IOException{
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int tc = Integer.parseInt(st.nextToken());
		for(int t=1;t<=tc;t++) {
			answer=0;
			conMax=0;
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			arr = new int[n][n];
			
			list = new ArrayList<>();
			int cnt=0;
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<n;j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
					if(arr[i][j] == 1) {
						list.add(new Pair(i,j));
						cnt++;
					}
				}
			}
			
			recursive(0, cnt, 0, n, 0);
			bw.write("#"+ t + " " + answer + '\n');
		}
		
		bw.flush();
	}
}
