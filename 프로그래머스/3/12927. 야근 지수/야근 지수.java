import java.util.*;

class Solution {
    public int min(int a, int b){
        return a>b?b:a;
    }
    
    public long solution(int n, int[] works) {
        long answer = 0;
        int[] visited = new int[50002];
        
        for(int i : works){
            visited[i]++;
        }
            
        for(int i=50000;i>0;i--){
            int minus=0;
            if(visited[i] > 0){
                minus = min(n,visited[i]);
                visited[i]-=minus;
                n-=minus;
                visited[i-1] +=minus;
            }
            if(n==0){
                break;
            }
        }
        for(int i=1;i<=50000;i++){
            answer+= 1L *i*i*visited[i];
        }
        
        return answer;
    }
}