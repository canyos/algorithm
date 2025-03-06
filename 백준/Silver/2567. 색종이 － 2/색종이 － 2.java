import java.util.Scanner;
import java.io.*;
public class Main {
	static int arr[][];
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		arr = new int [105][105];
		int n = sc.nextInt();
		int c,r;
		for(int i=0;i<n;i++) {
			c = sc.nextInt();
			r = sc.nextInt();
			arr[r+1][c+1] += 1;
			arr[r+11][c+1] += -1;
			arr[r+1][c+11] += -1;
			arr[r+11][c+11] += 1;
		}
		
		for(int i=0;i<104;i++) {
			for(int j=0;j<104;j++) {
				arr[i+1][j] += arr[i][j];
			}
		}
		for(int i=0;i<104;i++) {
			for(int j=0;j<104;j++) {
				arr[i][j+1] += arr[i][j];
			}
		}
		
		int answer=0;
		for(int i=1;i<101;i++) {
			for(int j=1;j<101;j++) {
				if(arr[i][j]>0) {					
					
					if(arr[i-1][j]==0)answer++;
					if(i==100 || arr[i+1][j]==0)answer++;
					if(j==100 ||arr[i][j+1]==0)answer++;
					if(arr[i][j-1]==0)answer++;
				}
			}
		}
		
//		for(int i=0;i<100;i++) {
//			for(int j=0;j<100;j++) {
//				System.out.print(arr[i][j] + " ");
//			}
//			System.out.println();
//		}
		System.out.println(answer);
	}

}
