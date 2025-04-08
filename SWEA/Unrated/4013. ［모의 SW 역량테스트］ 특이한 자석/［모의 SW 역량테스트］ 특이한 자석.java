import java.util.*;
import java.io.*;


public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static Scanner scanner = new Scanner(System.in);

	
	static int k;
	static List<Integer> arr[];
	static int answer;
	static boolean visited[];
	static void cw(int num) {
		if(num<0 || num>3 || visited[num])return;
		visited[num]=true;
		
		int last = arr[num].remove(7);
		arr[num].add(0,last);
		
		if(num+1<4 && arr[num].get(3) != arr[num+1].get(6)) {
			ccw(num+1);
		}
		if(num-1>=0 && arr[num].get(7) != arr[num-1].get(2)) {
			ccw(num-1);
		}
	}
	static void ccw(int num) {
		if(num<0 || num>3 || visited[num])return;
		visited[num]=true;
		
		int first = arr[num].remove(0);
		arr[num].add(first);
		
		if(num+1<4 &&  arr[num].get(1) != arr[num+1].get(6)) {
			cw(num+1);
		}
		if(num-1>=0 && arr[num].get(5) != arr[num-1].get(2)) {
			cw(num-1);
		}
	}
	
	public static void main(String[] args) throws Exception {
		int tc= nextInt();
		
		for(int t=1;t<=tc;t++) {
			k=nextInt();
			arr = new List[4];
			answer=0;
			int num;
			for(int i=0;i<4;i++) {
				arr[i] = new ArrayList<>();
				for(int j=0;j<8;j++) {
					num = nextInt();
					arr[i].add(num);
				}
			}
			
			int dir;
			for(int i=0;i<k;i++) {
				visited=new boolean[4];
				num = nextInt();dir=nextInt();
				if(dir==1) {
					cw(num-1);
				}else {
					ccw(num-1);
				}
				
			}
			
			for(int idx=0,score=1;idx<4;idx++,score*=2) {
				answer+=arr[idx].get(0)*score;
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
