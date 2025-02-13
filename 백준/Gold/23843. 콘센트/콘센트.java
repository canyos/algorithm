import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
		List<Long> list = new ArrayList<>();
		st= new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			list.add( Long.parseLong(st.nextToken()));
		}
		
		list.sort(Comparator.reverseOrder());
		
		PriorityQueue<Long> pq = new PriorityQueue<>();
		for(int i=0;i<m;i++) {
			pq.add(0L);
		}
		
		for(int i=0;i<n;i++) {
			Long t=pq.poll();
			pq.add(t+list.get(i));
		}
		
		long answer = 0;
		while(!pq.isEmpty()) {
			answer = Math.max(answer, pq.poll());
		}
		
		bw.write(String.valueOf(answer));
		bw.flush();
	}

}
