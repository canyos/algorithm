import java.util.*;

class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        Arrays.sort(A);
        Arrays.sort(B);
        
        for(int a=A.length-1,b=B.length-1; a>=0;a--){
            if(A[a]<B[b]){
                answer++;
                b--;
            }
        }
        
        return answer;
    }
}