import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	public static int nextInt() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());
		}
		return Integer.parseInt(st.nextToken());
	}	
	

	static int arr[][];
	public static boolean nextPermutation(int[] list) {
		int i = list.length-1;
		while(i>0 && list[i-1]>=list[i])i--;
		if(i==0) return false;
		
		int j=list.length-1;
		while(list[i-1]>=list[j])j--;
		
		int temp = list[i-1];
		list[i-1] = list[j];
		list[j] = temp;
		
		int k=list.length-1;
		while(i<k) {
			temp=list[i];
			list[i] = list[k];
			list[k] = temp;
			i++;
			k--;
		}
		
		return true;
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int n = nextInt();
		arr = new int[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				arr[i][j] = nextInt();
			}
		}
		
		int[] list = new int[n];
		for(int i=n/2;i<n;i++) 
			list[i] =1;
		
		int answer=9999999;
		do {
			int sum1=0, sum2=0;
			if(list[0] == 1)break;
			for(int i=0;i<n;i++) {
				for(int j=i+1;j<n;j++) {
					if(list[i]==list[j]) {
						if(list[i]==1) 
							sum1+=arr[i][j]+arr[j][i];
						else
							sum2+=arr[i][j] +arr[j][i];
					}
				}
			}
			answer = Math.min(answer,Math.abs(sum1-sum2));
		}while(nextPermutation(list));
		
		System.out.println(answer);
	}

}
