import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException{
        //--------------솔루션 코드를 작성하세요.--------------------------------
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int k = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int arr[] = new int[k];
        for(int i=0;i<k;i++){
            arr[i] = Integer.parseInt(br.readLine());
        }

        long left = 1, right = Integer.MAX_VALUE;
        long answer=0;
        while(left<=right){
            long mid = left + (right - left)/2;
            int sum=0;
            for(int i=0;i<k;i++){
                sum+=arr[i]/mid;
            }
            if(sum<n){
                right = mid-1;
            }else{
                answer = Math.max(answer,mid);
                left = mid+1;
            }
        }
        System.out.println(answer);
    }

}