import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	public static int nextInt() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());
		}
		return Integer.parseInt(st.nextToken());
	}	
	
	public static class BC{
		int r;
		int c;
		int range;
		int power;
		public BC(int r, int c,int range, int power){
			this.r=r;
			this.c=c;
			this.range=range;
			this.power=power;
		}
	}
	
	static int answer;
	static int m,a;
	static int command[][]; 
	static BC bclist[];
	static int r1,c1, r2,c2;
	
	public static void move(int i) {
		switch(command[0][i]) {
		case 1:
			r1-=1;
			break;
		case 2:
			c1+=1;break;
		case 3: 
			r1+=1;break;
		case 4 : 
			c1-=1;break;
		}
		switch(command[1][i]) {
		case 1:
			r2-=1;
			break;
		case 2:
			c2+=1;break;
		case 3: 
			r2+=1;break;
		case 4 : 
			c2-=1;break;
		}
	}
	
	public static boolean isChargable(int r, int c, int idx) {
		BC b = bclist[idx];
		int dist = Math.abs(b.r - r) + Math.abs(b.c -c);
		if(dist<=b.range)
			return true;
		return false;
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int tc = nextInt();
		for(int t=1;t<=tc;t++) {
			answer = 0;
			r1=c1=1; r2=c2=10;
			
			m = nextInt();
			a = nextInt();
			command = new int [2][m];
			for(int i=0;i<m;i++) 
				command[0][i] = nextInt();
			for(int i=0;i<m;i++) 
				command[1][i] = nextInt();
			
			bclist = new BC[a];
			int r,c,range,power;
			for(int i=0;i<a;i++) {
				c=nextInt();r=nextInt();range=nextInt();power=nextInt();
				bclist[i] = new BC(r,c,range,power);
			}
			
			for(int i=0;i<=m;i++) {
				int bita=0, bitb=0;
				for(int j=0;j<a;j++) {
					if(isChargable(r1,c1,j)) {
						bita |= (1<<j);
					}
					if(isChargable(r2,c2,j)) {
						bitb |= (1<<j);
					}
				}
				
				int max=0;
				for(int f=0;f<a;f++) {
					for(int s=0;s<a;s++) {
						int sum =0;
						if((1<<f & bita)>0) sum+=bclist[f].power;
						if((1<<s & bitb)>0) sum+=bclist[s].power;
						
						if(f==s &&(1<<f & bita)>0 && (1<<s & bitb)>0) sum/=2;
						
						max =Math.max(sum, max);
					}
				}
				
				//System.out.println(i + " " + max);
				answer+= max;
				if(i<m)
					move(i);
			}
			
			System.out.println("#" + t + " " + answer);
		}
	}

}
