import java.util.*;
import java.io.*;


public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static Scanner scanner = new Scanner(System.in);

	
	static int n, x;
	static int arr[][];
	
	public static void main(String[] args) throws Exception {
		int tc= nextInt();
		
		for(int t=1;t<=tc;t++) {
			n= nextInt(); x= nextInt();
			arr = new int [n][n];
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					arr[i][j] = nextInt();
			
			int answer=0;
			for(int i=0;i<n;i++) {
				int h = arr[i][0];
				boolean can = true;
				boolean visited[] = new boolean[n];
				for(int j=1;j<n;j++) {
					if(h == arr[i][j]) continue;
					
					if(h+1 == arr[i][j]) {//한칸 높아짐
						boolean same=true;
						if(j-x<0) {
							can=false;	break;//맵밖으로 나감
						}
						for(int k=1;k<=x;k++) {
							if(arr[i][j-k] !=h || visited[j-k]) 
								same=false;
							visited[j-k]=true;
						}
							
						
						if(same) {
							h=h+1; 	continue;
						}
						else {
							can = false; break;
						}
					}
					else if( h-1 == arr[i][j]) {//한칸 낮아짐
						boolean same=true;
						if(j+x>n) {
							can=false;	break;//맵밖으로 나감
						}
						for(int k=1;k<x;k++) {
							if(arr[i][j+k] != h-1 ||visited[j+k]) 
								same=false;
							visited[j+k]=true;
						}
							
						
						if(same) {
							h=h-1;	j=j+x-1;	continue;
						}
						else {
							can=false;	break;
						}
					}
					else {
						can=false;	break;//불가능
					}
					
				}
				if(can) {
					//System.out.println(i);
					answer++;
				}
			}
			
			for(int i=0;i<n;i++) {
				int h = arr[0][i];
				boolean can = true;
				boolean visited[] = new boolean[n];
				for(int j=1;j<n;j++) {
					if(h == arr[j][i]) continue;
					
					if(h+1 == arr[j][i]) {//한칸 높아짐
						boolean same=true;
						if(j-x<0) {
							can=false;	break;//맵밖으로 나감
						}
						for(int k=1;k<=x;k++) {
							if(arr[j-k][i] !=h || visited[j-k]) 
								same=false; 
							visited[j-k]=true;
						}
						if(same) {
							h=h+1; 	continue;
						}
						else {
							can = false; break;
						}
					}
					else if( h-1 == arr[j][i]) {//한칸 낮아짐
						boolean same=true;
						if(j+x>n) {
							can=false;	break;//맵밖으로 나감
						}
						for(int k=1;k<x;k++) {
							if(arr[j+k][i] != h-1 || visited[j+k]) 
								same=false;
							visited[j+k]=true;
						}
							
						
						if(same) {
							h=h-1;	j=j+x-1;	continue;
						}
						else {
							can=false;	break;
						}
					}
					else {
						can=false;	break;//불가능
					}
					
				}
				if(can) {
					//System.out.println(i);
					answer++;
				}
			}
			
			bw.write("#"+t+ " " + answer+"\n"); 
		}
		bw.flush();
		
	}

	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return Integer.parseInt(st.nextToken());
	}
}
