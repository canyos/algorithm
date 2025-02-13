import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
	public static int answer=0;
	public static void recursive(List<List<Integer>> edge, int prev, int cur, boolean[] checked, boolean[] visited) {
		visited[cur]=true;
		
		if(edge.get(cur).size()==1 && cur!=1)return;//리프노드일 때
		
		for(int i=0;i<edge.get(cur).size();i++) {
			int next = edge.get(cur).get(i);
			if(!visited[next])
				recursive(edge,cur, next,checked,visited);
		}
		
		boolean isLeaf=false;//자식이 리프노트면 자신을 체크
		for(int i=0;i<edge.get(cur).size();i++) {
			int next = edge.get(cur).get(i);
			if(next==cur)continue;
			if(edge.get(next).size()==1 && next!=1) {
				isLeaf=true;
				break;
			}
		}
		if(isLeaf) {
			checked[cur]=true;
			return;
		}
		
		boolean allChecked=true;
		for(int i=0;i<edge.get(cur).size();i++) {
			int child = edge.get(cur).get(i);
			if(child == cur)continue;
			if(!checked[child] && child !=prev) {
				allChecked=false;
				break;
			}
		}
		
		if(allChecked) 	return;
		
		checked[cur]=true;
		return;		
	}
	
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		
		List<List<Integer>> edge = new ArrayList<>();
		for(int i=0;i<n+1;i++) {
			edge.add(new ArrayList<Integer>());
		}
		
		int start, end;
		boolean[] checked = new boolean[n+1];
		
		for(int i=0;i<n-1;i++) {
			st = new StringTokenizer(br.readLine());
			start = Integer.parseInt(st.nextToken());
			end = Integer.parseInt(st.nextToken());
			
			edge.get(start).add(end);
			edge.get(end).add(start);
		}
		boolean visited[] = new boolean[n+1];
		recursive(edge, 0, 1,checked,visited);
		
		int answer=0;
		for(int i=0;i<n+1;i++) {
			if(checked[i]) {
				//System.out.print(i + " ");
				answer++;
			}
		}
		
		//System.out.println();
		bw.write(String.valueOf(answer));
		bw.flush();
	}

}
