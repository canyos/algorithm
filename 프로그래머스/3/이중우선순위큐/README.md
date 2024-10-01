https://school.programmers.co.kr/learn/courses/30/lessons/42628

```java
import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        int[] answer = {0,0};
        
        List<Integer> li = new ArrayList<>();
        
        for(String oper : operations){
            String[] op = oper.split(" ");
            
            if(op[0].equals("I")){ //넣는거
                li.add(Integer.parseInt(op[1]));
            }
            
            else { // 빼는거
                if(li.size()>0){ //뺄거있음?
                    li.sort(Comparator.naturalOrder()); //정렬
                    if(op[1].equals("-1")){ //제일 작은거?
                        li.remove(0); //제일 앞에거
                    }else{
                        li.remove(li.size()-1);//제일 뒤에서
                    }
                }
                
            }
                
        }
        
        li.sort(Comparator.naturalOrder());
        if(li.size() == 0 ){
            answer[0] = 0;
            answer[1] = 0;
        }
            
        else{
            answer[0] = li.get(li.size()-1);
            answer[1] = li.get(0);
        }
            
            
        return answer;
    }
}
```

### 해설
1. arrayList를 이용해 빼는 조건이 들어오면 정렬해서 뺏음 nlogn * n인데 통과되네?;;
2. 탐색하면서 하나만 빼면 n*n까지는 줄일 수 있을 듯
3. pq에서도 erase(Object obj)를 지원해 pq를 두개 사용해 푸는 방법도 있음
