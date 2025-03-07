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
	public static class Pair{
		int r;
		int c;
		int dist;
		Pair(int r, int c){
			this.r=r;
			this.c=c;
		}
		Pair(int r, int c, int dist){
			this.r=r;
			this.c=c;
			this.dist = dist;
		}
	}
	static int dx[] = {0,-1,0,1,1,1,-1,-1}, dy[]= {-1,0,1,0,1,-1,1,-1};
	
	public static boolean checkPos(int r,int c,int n, int m) {
		return r>=0 && r<n && c>=0 && c<m;
	}
	public static boolean nextPermutation(int arr[]) {
		int i = arr.length-1;
		while(i>0 && arr[i-1]>=arr[i])i--;
		if(i==0) 
			return false;
		int j = arr.length-1;
		while(arr[i-1] >= arr[j]) j--;
		
		int temp = arr[i-1];
		arr[i-1] = arr[j];
		arr[j] = temp;
		
		int k=arr.length-1;
		while(i<k) {
			temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
			i++;
			k--;
		}
		
		return true;
	}
	static Queue<Pair> qu = new LinkedList<>();
	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int arr[][] = new int[n+1][n+1];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				arr[i][j] = nextInt();
		
		int perm[] = new int [n];
		for(int i=0;i<n;i++)
			perm[i] = i+1;
		
		int answer = 100000001;
		loop:do {
			int sum=0;
			for(int i=0;i<n-1;i++) {
				if(arr[perm[i]][perm[i+1]]==0)continue loop;
				sum+=arr[perm[i]][perm[i+1]];
			}
			if(arr[perm[n-1]][perm[0]]==0)continue loop;
			sum+=arr[perm[n-1]][perm[0]];
			answer = Math.min(answer, sum);
		}while(nextPermutation(perm));
		
		System.out.println(answer);
	}

}
