import java.util.*;
import java.io.*;


public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static Scanner scanner = new Scanner(System.in);
	
	static class Pair{
		int y;
		int x;
		Pair(int y,int x){
			this.y=y;
			this.x=x;
		}
	}
	static class Node{
		int y;
		int x;
		int dir;
		int e;
		Node(int y, int x, int d, int e){
			this.y=y;
			this.x=x;
			this.dir=d;
			this.e=e;
		}
		boolean update() {
			int ty = this.y+dy[dir], tx = this.x+dx[dir];
			int cnt = mp.get(this.y*10000+this.x);
			if(!(ty>=0&& ty<4001 && tx>=0 && tx<4001)) {//맵밖으로나가서 지울거임
				list.remove(this);
				if(cnt==1)mp.remove(this.y*10000+this.x);
				else 
					mp.put(this.y*10000+this.x, cnt-1);
				return false;
			}
			
			if(cnt==1)mp.remove(this.y*10000+this.x);
			else 
				mp.put(this.y*10000+this.x, cnt-1);
			this.y=ty;
			this.x=tx;
			mp.put(this.y*10000+this.x, mp.getOrDefault(this.y*10000+this.x, 0)+1);
			return true;
		}
	}
	
	static int n;
	static int dy[] = {1,-1,0,0}, dx[] = {0,0,-1,1};
	static List<Node> list;
	static Map<Integer, Integer> mp;
	
	public static void main(String[] args) throws Exception {
		int tc= nextInt();
		for(int t=1;t<=tc;t++) {
			n= nextInt(); 
			int answer=0;
			list = new ArrayList<>();
			mp = new HashMap<>();
			int x,y,c,d;
			Queue<Integer> qu = new LinkedList<>();
			for(int i=0;i<n;i++) {
				x=nextInt();y=nextInt();c=nextInt();d=nextInt();
				list.add(new Node((y+1000)*2, (x+1000)*2, c, d));
				mp.put((y+1000)*2*10000+(x+1000)*2, 1);
			}
			
			for(int i=0;i<4000 && list.size()>1;i++) {
				for(int j=0;j<list.size();j++) {
					boolean res = list.get(j).update();
					if(!res) {
						j--;
					}
				}
				if(list.size()<=1)break;

				for(Map.Entry<Integer, Integer> e : mp.entrySet()) {
					if(e.getValue()>1) {
						for(int j=0;j<list.size();j++) {
							if(list.get(j).y == e.getKey()/10000 && list.get(j).x == e.getKey()%10000) {
								answer+=list.get(j).e;
								list.remove(j);
								j--;
							}
						}
						qu.add(e.getKey());
					}
				}
				while(!qu.isEmpty()) {
					mp.remove(qu.poll());
				}
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
