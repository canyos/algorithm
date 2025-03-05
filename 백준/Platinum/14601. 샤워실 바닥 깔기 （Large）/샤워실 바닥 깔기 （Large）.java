import java.util.Scanner;
import java.io.*;
public class Main {
	static int arr[][];
	static int id=0;
	static void recursive(int r1,int c1, int r2, int c2, int x,int y, int hole) {
		if(r2-r1 == 2) {
			arr[x][y] = hole;
			if(x==r1 && y==c1) {
				arr[x][y+1] = arr[x+1][y] = arr[x+1][y+1] = ++id;
			}
			else if(x==r1 && y==c1+1) {
				arr[r1][c1] = arr[r1+1][c1] = arr[r1+1][c1+1] = ++id;
			}
			else if(r1+1 == x && c1 == y) {
				arr[r1][c1] = arr[r1][c1+1] = arr[r1+1][c1+1] = ++id;
			}
			else {
				arr[r1][c1] = arr[r1][c1+1] = arr[r1+1][c1] = ++id;
			}
			return;
		}
		int mr = (r1+r2)/2, mc = (c1+c2)/2;
		int temp= (id++) + 1;
		if(x<mr && y<mc) {//왼위
			
			recursive(r1,c1,mr,mc,x,y,hole);
			recursive(r1,mc,mr,c2,mr-1,mc,temp);
			recursive(mr,c1,r2,mc,mr,mc-1,temp);
			recursive(mr,mc,r2,c2,mr,mc,temp);
		}else if (x<mr && y>=mc) {//오위
			recursive(r1,c1,mr,mc,mr-1,mc-1,temp);
			recursive(r1,mc,mr,c2,x,y,hole);
			recursive(mr,c1,r2,mc,mr,mc-1,temp);
			recursive(mr,mc,r2,c2,mr,mc,temp);
		}else if ( x>=mr && y<mc) {//왼아
			recursive(r1,c1,mr,mc,mr-1,mc-1,temp);
			recursive(r1,mc,mr,c2,mr-1,mc,temp);
			recursive(mr,c1,r2,mc,x,y,hole);
			recursive(mr,mc,r2,c2,mr,mc,temp);
		}else {//오아
			recursive(r1,c1,mr,mc,mr-1,mc-1,temp);
			recursive(r1,mc,mr,c2,mr-1,mc,temp);
			recursive(mr,c1,r2,mc,mr,mc-1,temp);
			recursive(mr,mc,r2,c2,x,y,hole);
		}
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = sc.nextInt();
		int n2 = (int)Math.pow(2,n);
		
		int x = sc.nextInt();
		int y = sc.nextInt();
		
		int holer = n2-y;
		int holec = x-1;
		arr = new int[n2][n2];
		
		recursive(0,0,n2,n2,holer,holec,-1);
		
		for(int i=0;i<n2;i++) {
			for(int j=0;j<n2;j++) {
				bw.write(arr[i][j] + " ");
			}
			bw.write("\n");
		}
		bw.flush();
	}

}
