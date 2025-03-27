import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Solution {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static StringTokenizer st;

	public static int nextInt() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());	
		}
		return Integer.parseInt(st.nextToken());
	}
	
	static class Person{
		int r;
		int c;
		Person(int r,int c){
			this.r=r;
			this.c=c;
		}
	}
	
	static class Stair{
		int r;
		int c;
		int time;
		Stair(int r, int c, int time){
			this.r=r;
			this.c=c;
			this.time= time;
		}
	}
	
	static class Line{
		int num;
		int time;
		Line(int num, int time){
			this.num = num;
			this.time = time;
		}
	}
	
	static int dr[] = {0,0,-1,1}, dc[] = {1,-1,0,0};
	static List<Stair> stairs;
	static List<Person> peoples;
	static int answer;
	static int n,m;
	static List<Line> line;
	
	
	static void calc(int seq[]){
		Deque<Integer> dq[] = new ArrayDeque[2];
		dq[0] = new ArrayDeque<Integer>();
		dq[1] = new ArrayDeque<Integer>();
		
		line = new ArrayList<>();
		for(int i=0;i<peoples.size();i++) {
			Person person = peoples.get(i);
			Stair stair = stairs.get(seq[i]);
			
			int dist = Math.abs(person.r - stair.r) + Math.abs(person.c - stair.c);
			line.add(new Line(seq[i], dist));
		}
		
		line.sort((l1,l2) -> l1.time - l2.time);//대기 줄 오름차순 정렬
		
		for(Line l : line) {
			int num = l.num, time = l.time;
			while(!dq[num].isEmpty() && dq[num].peekFirst() <= time) {//내 도착시간전에 완료된거 빼주기
				dq[num].pollFirst();
			}

			if(dq[num].size() == 3) {//꽉차있으면 젤 앞에거 끝나는시간 + 내가 내려가는시간 더해줌
				int t = dq[l.num].pollFirst();
				dq[num].addLast(t+stairs.get(num).time);
			}
			
			else {//꽉 안차있으면 그냥 뒤에 넣음
				dq[num].addLast(time+stairs.get(num).time+1);
			}
		}
		
		int maxNum=0;
		while(!dq[1].isEmpty()) {
			maxNum = Math.max(maxNum,dq[1].pollFirst());
		}
		while(!dq[0].isEmpty()) {
			maxNum = Math.max(maxNum,dq[0].pollFirst());
		}
		
		//System.out.println(maxNum);
		answer = Math.min(answer, maxNum);
		
	}
	
	static void recursive(int pos, int seq[]) {
		if(pos == peoples.size()) {
			//System.out.println(Arrays.toString(seq));
//			if(Arrays.toString(seq).equals("[0, 0, 0, 1, 1, 1]")) {
//				System.out.println("1");
//			}
			calc(seq);
			return;
		}
		
		seq[pos]=0;
		recursive(pos+1,seq);
		seq[pos]=1;
		recursive(pos+1,seq);
	}
	
	public static void main(String[] args) throws Exception{
		int tc = nextInt();
		for(int t=1;t<=tc;t++) {
			int n = nextInt();
			answer=0;
			stairs = new LinkedList<>();
			peoples = new LinkedList<>();
			answer = 9999;
			
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					int temp = nextInt();
					if(temp==1)
						peoples.add(new Person(i,j));
					if(temp>1)
						stairs.add(new Stair(i,j, temp));
				}
			}
			
			recursive(0,new int[peoples.size()]);
			
			bw.write("#"+t+" " + answer + "\n");
		}
		bw.flush();
	}

}
