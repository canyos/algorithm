import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException{
		//--------------솔루션 코드를 작성하세요.--------------------------------
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		
		int r = Integer.parseInt(st.nextToken()), c= Integer.parseInt(st.nextToken()) , n  = Integer.parseInt(st.nextToken());
		if(n >5 ){
			if(n%2==0) {
				n=6;
			}
			else if((n/2)%2==0) {
				n=5;
			}
			else {
				n=7;
			}
		}

		
		int arr[][] = new int [r][c];
		
		for(int i=0;i<r;i++) {
			String str = br.readLine();
			for(int j=0;j<c;j++) {
				if(str.charAt(j)=='.') 
					arr[i][j] = -1;
				else
					arr[i][j] = 0;
			}
		}
		
		for(int i=2;i<=n;i++) {
			for(int rr=0;rr<r;rr++) { // 빈칸에 지뢰 설치
				for(int cc=0;cc<c;cc++) {
					if(arr[rr][cc]==-1) {
						arr[rr][cc]=i;
					}
				}
			}
			
			i++;
			if(i>n)break;
			
			for(int rr=0;rr<r;rr++) { // 3초전 지뢰 폭발
				for(int cc=0;cc<c;cc++) {
					if(arr[rr][cc]==i-3) {
						if(rr>0 )
							arr[rr-1][cc]=-1;
						if(cc>0 )
							arr[rr][cc-1]=-1;
						arr[rr][cc]=-1;
						if(cc+1<c && arr[rr][cc+1] !=i-3)
							arr[rr][cc+1]=-1;
						if(rr+1<r && arr[rr+1][cc] !=i-3)
							arr[rr+1][cc]=-1;
					}
				}
			}

		}
		
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				if(arr[i][j]==-1) {
					bw.write('.');
				}
				else {
					bw.write('O');
				}
			}
			bw.write('\n');
		}
		bw.flush();
	}

}

/*
6 7 3
.......
...O...
....O..
.......
OO.....
OO.....

 */

