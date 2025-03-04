import java.io.*;
import java.util.*;

public class Main {
	static int arr[][];
	static int answer[];
	
	public static void recursive(int r1,int c1, int r2,int c2) {
		
		if(r1==r2 && c1 == c2) {
			answer[arr[r1][c1]]++;
			return;
		}
		int midr = (r1+r2)/2, midc = (c1+c2)/2;
		int sum=0;
		int a = arr[r1][c1];
		boolean is1 = true;
		loop:for(int i=r1;i<r2;i++) {
			for(int j=c1;j<c2;j++) {
				if(arr[i][j]!=a) {
					recursive(r1,c1,midr,midc);//왼쪽위
					recursive(r1,midc,midr,c2);//오른쪽위
					recursive(midr,c1,r2,midc);//왼쪽아래
					recursive(midr,midc,r2,c2);//오른쪽아래
					is1 = false;
					break loop;
				}
			}
		}
		if(is1) {
			//System.out.println(r1 + " " + c1 + " " +r2 + " " + c2  + " " + a);
			answer[a]++;
		}
	}
	
	public static void main(String[] args) throws IOException{
		//--------------솔루션 코드를 작성하세요.--------------------------------
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		//StringTokenizer st = new StringTokenizer(br.readLine());
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		arr = new int[n][n];
		answer = new int[2];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				arr[i][j] = sc.nextInt();
		
		recursive(0,0,n,n);
		System.out.println(answer[0]);
		System.out.println(answer[1]);
	}

}
