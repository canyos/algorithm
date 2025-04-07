import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static class Block{
		int num;
		int area;
		int height;
		int weight;
		Block(int num, int a, int b, int c){
			this.num = num;
			this.area=a;
			this.height=b;
			this.weight=c;
		}
	}
	
	static class Node{
		int weight;
		int height;
		int cnt;
		String path;
	
		Node(int b, int c, int d, String prev){
			this.weight = b;
			this.height = c;
			this.cnt=d;
			this.path = prev;
		}
	}
	
	static Node dp[][];
	static int n;
	static List<Block> arr = new ArrayList<>();
	
	public static void main(String[] args)throws Exception {
		n = nextInt();
		dp = new Node[n+1][10001];//index, 무게

		int a,b,c;
		
		for(int i=1;i<=n;i++) {
			a=nextInt();b=nextInt();c=nextInt();
			arr.add(new Block(i,a,b,c));
		}
		arr.sort((b1,b2)-> b1.area - b2.area); //후에 오는 블럭은 무조건 면적 더 큼
		
		for(int j=0;j<10001;j++) {
			if(j>=arr.get(0).weight) {
				Block block = arr.get(0);
				dp[0][j] = new Node(block.weight, block.height, 1, String.valueOf(block.num));
			}else {
				dp[0][j] = new Node(0,0,0,"");
			}
		}
		
		for(int i=1;i<n;i++) {
			Block cur = arr.get(i);
			for(int j=0;j<10001;j++) {
				dp[i][j] = dp[i-1][j];//기존 값 가져오기
				
				if(j>=cur.weight && //지금거 담을 수 있고
						dp[i-1][cur.weight-1].height + cur.height > dp[i][j].height) {//담아서 높이가 더 높아진다면
					dp[i][j] = new Node(
							cur.weight, 
							dp[i-1][cur.weight-1].height + cur.height, 
							dp[i-1][cur.weight-1].cnt+1, 
							 dp[i-1][cur.weight-1].path + "\n" + String.valueOf(cur.num)
							);
				}
			}
		}
		
		System.out.println(dp[n-1][10000].cnt);
		System.out.println(dp[n-1][10000].path);
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
