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
	
	static class coor{
		int r;
		int c;
		coor(int r , int c){
			this.r=r;
			this.c=c;
		}
	}
	static class Bug{
		int r;
		int c;
		int num;
		int dir;
		Bug(int r, int c, int num, int dir){
			this.r=r;
			this.c=c;
			this.num=num;
			this.dir=dir;
		}
	}
	
	static int dx[] = {0,-1,1,0,0}, dy[]= {0,0,0,-1,1};
	static List<Bug> list ;
	static int map[][] ;
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		int tc = nextInt();
		for(int t=1;t<=tc;t++) {
			int n=nextInt(), m = nextInt(), k=nextInt();
			list = new ArrayList<>();
			map = new int [n][n];
			for(int i=0;i<k;i++) {
				int r = nextInt();
				int c= nextInt();
				int num = nextInt();
				int dir = nextInt();
				list.add(new Bug(r,c,num,dir));
				map[r][c]++;
			}
			
			
			for(int i=0;i<m;i++) {
				List<coor> checkList = new ArrayList<>();
				for(int l=0;l<list.size();l++) {
					Bug bug = list.get(l);
					map[bug.r][bug.c]--;
					bug.r +=dx[bug.dir];
					bug.c +=dy[bug.dir];
					map[bug.r][bug.c]++;

					if(map[bug.r][bug.c]>1)checkList.add(new coor(bug.r,bug.c));
					if(bug.r==0 || bug.r == n-1 || bug.c==0 ||bug.c==n-1) {
						bug.num/=2;
						if(bug.num==0) {
							list.remove(bug);
							l--;
							continue;
						}
						if(bug.dir==1)bug.dir=2;
						else if(bug.dir==2)bug.dir=1;
						else if(bug.dir==3)bug.dir=4;
						else bug.dir=3;
					}		
				}
				
				for(coor c : checkList) {
					if(map[c.r][c.c]>1) {
						int dir=0;
						int sum=0;
						int maxNum=0;
						for(int b=0;b < list.size();b++) {
							Bug bug = list.get(b);
							if(!(bug.r == c.r && bug.c == c.c))continue;
							if(bug.num>maxNum) {
								dir = bug.dir;
								maxNum = bug.num;
							}
							sum+=bug.num;
							list.remove(bug);
							b--;
						}
						if(sum>0)
							list.add(new Bug(c.r,c.c,sum,dir));
					}
				}
			}
			int answer = 0;
			for(Bug bug : list) {
				answer+=bug.num;
			}
			bw.write("#"+t + " " + answer+"\n");
			
		}
		bw.flush();
	}

}
