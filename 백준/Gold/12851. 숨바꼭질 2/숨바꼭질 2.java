import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	public static int nextInt() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());
		}
		return Integer.parseInt(st.nextToken());
	}	
	
	public static class node{
		int cur;
		int cnt;
		node(int a, int b){
			this.cur=a;
			this.cnt=b;
		}
	}
	
	static int dx[] = {0,0,1,-1,1,1,-1,-1},dy[] = {1,-1,0,0,1,-1,1,-1};
	static Queue<node> qu = new LinkedList<>();
	static int visited[];
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int n = nextInt();
		int k = nextInt();
		visited = new int[200001];
		for(int i=0;i<200001;i++)
			visited[i] = 2000000;
		
		qu.add(new node(n,0));
		visited[n]=0;
		
		int answer=200001;
		int answerCnt=0;
		while(!qu.isEmpty()) {
			node cur = qu.poll();
			if(cur.cnt>visited[cur.cur])continue;//이미 더 적게 방문가능
			if(cur.cur == k) {//k에 도착했을 때
				if(visited[cur.cur] == answer) {//최단경로랑 같으면
					answerCnt++;
				}
				else {//최단경로보다 적으면
					answer = cur.cnt;
					answerCnt = 1;
				}
			}
			visited[cur.cur]=cur.cnt;
			
			
			if(cur.cur+1<=200000 ) {
				qu.add(new node(cur.cur+1,cur.cnt+1));
			}
			if(cur.cur>0 ){
				qu.add(new node(cur.cur-1,cur.cnt+1));
				//visited[cur.cur-1]=true;
			}
			if(cur.cur*2<=200000 ) {
				qu.add(new node(cur.cur*2,cur.cnt+1));
				//visited[cur.cur*2]=true;
			}
		}
		System.out.println(answer);
		System.out.println(answerCnt);
	}

}
