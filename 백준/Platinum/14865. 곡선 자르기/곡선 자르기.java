import java.io.*;
import java.util.*;

public class Main {
	
	public static class Pair implements Comparable<Pair>{
		int x1;
		int x2;
		Pair(int x, int y){
			this.x1 = x;
			this.x2 = y;
		}
		@Override
		public int compareTo(Pair o) {
			// TODO Auto-generated method stub
			return this.x1 - o.x1;
		}
	}
	
	public static void main(String[] args) throws IOException{
		//--------------솔루션 코드를 작성하세요.--------------------------------
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		List<Pair> list = new ArrayList<>();
		
		int n = Integer.parseInt(st.nextToken());
		final int INF = (int) (1e9+1);
		int answer1=0, answer2=0;
		
		st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken()), y= Integer.parseInt(st.nextToken());//이전 x,y좌표
		int prev = INF;//이전 0 교차점
		int fx=x, fy= y;
		if(y>0) {
			int first=INF;
			for(int i=1;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken()), b= Integer.parseInt(st.nextToken());//현재 x,y좌표
				if(y>0 && b<0 || y<0 && b>0) {//0에서 교차함
					if(first == INF)
						first = a;
					else {
						if(prev == INF) {//시작점 존재하지않음
							prev = a;
						}else {//시작점 존재함 끝점
							if(a>prev)
								list.add(new Pair(prev, a));
							else
								list.add(new Pair(a,prev));
							prev = INF;
						}
					}
				}
				x=a;
				y=b;
			}
			if(first>x)
				list.add(new Pair(x, first));
			else
				list.add(new Pair(first,x));
		} else {
			for(int i=1;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken()), b= Integer.parseInt(st.nextToken());//현재 x,y좌표
				if(y>0 && b<0 || y<0 && b>0) {//0에서 교차함
					if(prev == INF) {//시작점 존재하지않음
						prev = a;
					}else {//시작점 존재함 끝점
						if(a>prev)
							list.add(new Pair(prev, a));
						else
							list.add(new Pair(a,prev));
						prev = INF;
					}
				}
				x=a;
				y=b;
			}
			if(fx==x && (fy>0 && y<0 || fy<0 && y>0))
				list.add(new Pair(x,prev));
		}
		
//		for(Pair a : list) {
//			System.out.println(a.x1 + " "+ a.x2);
//		}
		list.sort(Comparator.naturalOrder());//시작점x좌표 기준  오름차순 정렬
		
		for(int i=0;i<list.size();) {
			int e = list.get(i).x2;//기준 끝점
			int cnt = 1;
			while(i+cnt<list.size()) {//기준 끝점 보다 작으면 스킵
				if(list.get(i+cnt).x2<e) {
					cnt++;
				}
				else {
					break;
				}
			}
			answer1++;//다른 봉우리에 포함되지 않음
			i+=cnt;
		}
		
		
		for(int i=0;i<list.size()-1;i++) {
			if(list.get(i).x2 < list.get(i+1).x1) {//다음 봉우리가 나보다 오른쪽에 위치
				answer2++;// 다른봉우리를 포함하지 않는 봉우리임
			}
		}
		answer2++;//마지막 봉우리는 다른 봉우리를 포함할 수 없음
		
		System.out.println(answer1 + " " + answer2);
	}

}
