import java.io.*;
import java.util.*;

public class Main{
    public static class Pair implements Comparable<Pair>{
        int first;
        int second;
        public Pair(int f, int s){
            this.first = f;
            this.second = s;
        }
        @Override
        public int compareTo(Pair o) {
            return this.second - o.second;
        }
    }

    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m= Integer.parseInt(st.nextToken());

        List<List<Pair>> edges = new ArrayList<>();
        for(int i=0;i<n+1;i++){
            edges.add(new ArrayList<>());
        }

        boolean visited[];
        visited = new boolean[n+1];
        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b= Integer.parseInt(st.nextToken()), c= Integer.parseInt(st.nextToken());
            edges.get(a).add(new Pair(b,c));
            edges.get(b).add(new Pair(a,c));
        }

        PriorityQueue<Pair> pq = new PriorityQueue<>();
        List<Integer> selected = new ArrayList<>();

        for(Pair p : edges.get(1)){
            pq.add(p);
        }
        visited[1] = true;
        
        while(!pq.isEmpty()){
            int cur = pq.peek().first, cost = pq.poll().second;
            if(visited[cur])continue;
            selected.add(cost);
            visited[cur]=true;

            for(Pair p : edges.get(cur)){
                if(!visited[p.first]){
                    pq.add(p);
                }
                    
            }
        }

        selected.sort(Comparator.reverseOrder());
        int answer=0;
        for(int i=1;i<selected.size();i++){
            answer+=selected.get(i);
        }

        bw.write(String.valueOf(answer));
        bw.flush();
    }
}