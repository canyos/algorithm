import java.io.*;
import java.util.*;

public class Solution {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;
	
	public static class Node implements Comparable<Node>{
		int cost;
		int x;
		int y;
		int dir;
		int dist;
		Node(int c, int x,int y, int dir, int dist){
			this.x=x;
			this.cost=c;
			this.y=y;
			this.dir = dir;
			this.dist = dist;
		}

		@Override
		public int compareTo(Node o2) {
			if(this.cost == o2.cost) {
				return this.dist - o2.dist;
			}
			return (this).cost - (o2).cost;
		}
	}

	
	public static void main(String[] args) throws Exception {
		int tc = nextInt();
		for(int t=1;t<=tc;t++) {
			int answer=-1;
			int x1 = nextInt()+100, y1=nextInt()+100, x2=nextInt()+100, y2=nextInt()+100;
			PriorityQueue<Node> pq = new PriorityQueue<>();
			boolean visited[][][] = new boolean[201][201][2];
			int dist = Math.abs(x2-x1)+Math.abs(y2-y1);
			pq.add(new Node(0,x1,y1,1, dist));
			pq.add(new Node(0,x1,y1,0,dist));
			
			while(!pq.isEmpty()) {
				Node cur = pq.poll();
				if(cur.x ==x2 && cur.y == y2) {
					answer = cur.cost;
					break;
				}
				
				if(visited[cur.x][cur.y][cur.dir])continue;
				visited[cur.x][cur.y][cur.dir]=true;
				
				if(cur.dir==1) {//가로임
					if(cur.x-1 >=0 && !visited[cur.x-1][cur.y][0]) {
						dist = Math.abs(x2-(cur.x-1))+Math.abs(y2-cur.y);
						pq.add(new Node(cur.cost+1, cur.x-1, cur.y, 0, dist));
					}
					if(cur.x+1<=200 && !visited[cur.x+1][cur.y][0]) {
						dist = Math.abs(x2-(cur.x+1))+Math.abs(y2-cur.y);
						pq.add(new Node(cur.cost+1, cur.x+1, cur.y, 0, dist));
					}
				}else {//세로임
					if(cur.y-1 >=0 && !visited[cur.x][cur.y-1][1]) {
						dist = Math.abs(x2-(cur.x))+Math.abs(y2-(cur.y-1));
						pq.add(new Node(cur.cost+1, cur.x, cur.y-1, 1, dist));
					}
					if(cur.y+1<=200 && !visited[cur.x][cur.y+1][1]) {
						dist = Math.abs(x2-(cur.x))+Math.abs(y2-(cur.y+1));
						pq.add(new Node(cur.cost+1, cur.x, cur.y+1, 1, dist));
					}
				}
			}
			
			bw.write("#"+t+ " " + answer+"\n");
		}
		bw.flush();
	}
	
	public static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());
		}
		return Integer.parseInt(st.nextToken());
	}
}
