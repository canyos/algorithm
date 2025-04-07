import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static class Node{//지름길 여부와 칸의 숫자
		int sc;
		int num;
		Node(int b, int n){
			this.sc=b;
			this.num=n;
		}
	}
	
	static boolean visited[][] = new boolean[2][42];
	static int arr[] = new int [10];
	static Node horse[] = new Node[4];
	static int answer;
	
	//도착지점 계산해주는 함수
	static Node calc(int sc, int pos, int num) {
		if(sc==1)
			return shortCut(pos,num);
		else if(pos==10)
			return shortCut(13,num-1);
		else if(pos==20)
			return shortCut(22,num-1);
		else if(pos==30)
			return shortCut(28,num-1);
		else if(pos+2*num>40)
			return new Node(0,41);
		else
			return new Node(0, pos+2*num);
	}
	
	//지름길 계산해줌
	static Node shortCut(int pos, int num) {
		if(num==0) {
			if(pos==40)
				return new Node(0,40);
			return new Node(1,pos);
		}
		
		if(pos==13)
			return shortCut(16,num-1);
		if(pos==16)
			return shortCut(19,num-1);
		if(pos==19)
			return shortCut(25,num-1);
		

		if(pos==22)
			return shortCut(24,num-1);
		if(pos==24)
			return shortCut(25,num-1);
		
		if(pos==28)
			return shortCut(27,num-1);
		if(pos==27)
			return shortCut(26,num-1);
		if(pos==26)
			return shortCut(25,num-1);
		
		if(pos == 25)
			return shortCut(30,num-1);
		if(pos==30)
			return shortCut(35,num-1);
		if(pos==35)
			return shortCut(40,num-1);
		
		if(pos==40)
			return new Node(0,41);
		return null;
	}

	static void recursive(int pos, int sum) {
		if(pos==10) {
			answer = Math.max(answer, sum);
			return;
		}
		
		for(int i=0;i<4;i++) {//이동할 말 선택
			if(horse[i].num == 41)continue;//도착말은 고르지않음
			Node next = calc(horse[i].sc, horse[i].num, arr[pos]);
			
			if(next.num == 41 || !visited[next.sc][next.num]) {//다음지점 방문안했거나 도착지점임
				int temps=horse[i].sc;
				int tempn = horse[i].num;
				
				visited[temps][tempn]=false;
				visited[next.sc][next.num]=true;
				horse[i].sc = next.sc;
				horse[i].num = next.num;
				
				if(next.num==41)//도착지점이면 점수안더함
					recursive(pos+1,sum);
				else
					recursive(pos+1, sum+next.num);
				
				horse[i].sc=temps;
				horse[i].num=tempn;
				

				visited[next.sc][next.num]=false;
				visited[temps][tempn]=true;
			}
		}
	}
	
	public static void main(String[] args)throws Exception {
		for(int i=0;i<10;i++)
			arr[i] = nextInt();
		
		horse[0]=new Node(0,0);
		horse[1]=new Node(0,0);
		horse[2]=new Node(0,0);
		horse[3]=new Node(0,0);
		
		recursive(0,0);
		System.out.println(answer);
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
