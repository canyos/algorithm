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
	static char map[][];
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int tc = nextInt();
		for(int t=1;t<=tc;t++) {
			int h = nextInt();
			int w = nextInt();
			map = new char[h][w];
			int r=-1,c=-1;
			int dir=-1;
			for(int i=0;i<h;i++) {
				String str = br.readLine();
				for(int j=0;j<w;j++) {
					map[i][j] = str.charAt(j);
					if(map[i][j] =='^' ) {
						r=i; c=j; dir=0;
					}
					if(map[i][j] =='v' ) {
						r=i;c=j;dir=1;
					}
					if(map[i][j] =='<' ) {
						r=i;c=j;dir=2;
					}
					if(map[i][j] =='>' ) {
						r=i;c=j;dir=3;
					}
				}
			}
			
			int n = nextInt();
			String str = br.readLine();
			for(int i=0;i<n;i++) {
				switch(str.charAt(i)) {
				case 'U':
					dir=0;
					map[r][c]='^';
					if(r-1>=0 && map[r-1][c]=='.') {
						map[r-1][c]='^';
						map[r][c] ='.';
						r--;
					}
					
					break;
				case 'D':
					dir=1;
					map[r][c]='v';
					if(r+1<h && map[r+1][c]=='.'){
						map[r+1][c]='v';
						map[r][c] ='.';
						r++;
					}
					break;
				case 'L':
					dir=2;
					map[r][c]='<';
					if(c-1>=0 && map[r][c-1]=='.'){
						map[r][c-1]='<';
						map[r][c] ='.';
						c--;
					}
					break;
				case 'R':
					dir=3;
					map[r][c]='>';
					if(c+1<w && map[r][c+1]=='.'){
						map[r][c+1]='>';
						map[r][c] ='.';
						c++;
					}
					break;
				case 'S':
					switch(dir) {
					case 0:
						for(int k=1;r-k>=0;k++) {
							if(map[r-k][c] == '*') {
								map[r-k][c] = '.';
								break;
							}
							else if(map[r-k][c] == '#')
								break;
						}
						break;
					case 1:
						for(int k=1;r+k<h;k++) {
							if(map[r+k][c] == '*') {
								map[r+k][c] = '.';
								break;
							}
							else if(map[r+k][c] == '#')
								break;
						}
						break;
					case 2:
						for(int k=1;c-k>=0;k++) {
							if(map[r][c-k] == '*') {
								map[r][c-k] = '.';
								break;
							}
							else if(map[r][c-k] == '#')
								break;
						}
						break;
					case 3:
						for(int k=1;c+k<w;k++) {
							if(map[r][c+k] == '*') {
								map[r][c+k] = '.';
								break;
							}
							else if(map[r][c+k] == '#')
								break;
						}
						break;
					}
					
				}
			}
			
			bw.write("#"+t+" ");
			for(int i=0;i<h;i++) {
				for(int j=0;j<w;j++) {
					bw.write(map[i][j]);
				}
				bw.write('\n');
			}
			
		}
		bw.flush();
	}

}
