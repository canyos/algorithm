import java.io.*;

import java.util.*;

public class Main {
	public static int arr[];
	public static int n;
	public static List<List<Integer>> edges = new ArrayList<>();
	public static int answer=1001;
	
	public static void check(int cnt, boolean[] selected) {
		//System.out.println(Arrays.toString(selected));
		Set<Integer> st1 = new HashSet<>(), st2 = new HashSet<>();
		
		int head1 = 0,head2=0;
		boolean visited[] = new boolean[n+1];
		int cnt1=0, cnt2=0;
		for(int i=1;i<=n;i++) {
			if(selected[i]) {
				st1.add(i);
				head1 = i;
			}
			else {
				st2.add(i);
				head2=i;
			}
		}
		
		Queue<Integer> qu = new LinkedList<>();

		qu.add(head1);		

		while(!qu.isEmpty()) {
			int cur = qu.poll();
			if(visited[cur])continue;
			visited[cur]=true;
			st1.remove(cur);
			cnt1+=arr[cur];
			for(int next : edges.get(cur)) {
				if(selected[next])
					qu.add(next);
			}
		}
		
		if(st1.size()>0)
			return;
		
		qu = new LinkedList<>();
		visited = new boolean[n+1];
		qu.add(head2);		
		while(!qu.isEmpty()) {
			int cur = qu.poll();
			if(visited[cur])continue;
			visited[cur]=true;
			st2.remove(cur);
			cnt2+=arr[cur];
			for(int next : edges.get(cur)) {
				if(!selected[next])
					qu.add(next);
			}
		}
		if(st2.size()>0)
			return;
		
		answer = Math.min(answer, Math.abs(cnt1-cnt2));
		int a=0;
		a++;
		
		
	}
	
	public static void combination(int[] group, int cnt, int r, boolean[] visited) {
		if(cnt == r) {
			check(cnt, visited);
			//System.out.println(Arrays.toString(group));
			return;
		}
		else {
			for(int i=cnt==0?1:group[cnt-1]+1 ;i<=n;i++) {
				if(!visited[i]) {
					visited[i]=true;
					group[cnt] = i;
					combination(group,cnt+1,r,visited);
					visited[i] =false;
					group[cnt]=0;
				}
			}
		}
		
	}
	
	public static void main(String[] args) throws IOException{
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		arr = new int[n+1];
		for(int i=0;i<=n;i++) {
			edges.add(new ArrayList<Integer>());
		}
		
		st = new StringTokenizer(br.readLine());
		for(int i=1;i<=n;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		
		for(int i=1;i<=n;i++) {
			st = new StringTokenizer(br.readLine());
			int cnt = Integer.parseInt(st.nextToken());
			for(int j=0;j<cnt;j++)
				edges.get(i).add(Integer.parseInt(st.nextToken()));
		}

		for(int i=1;i<=n/2;i++) {
			combination(new int[i], 0, i, new boolean[11]);
		}
		
		bw.write(String.valueOf(answer==1001?-1:answer));
		bw.flush();
	}
}
