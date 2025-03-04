import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException{
        //--------------솔루션 코드를 작성하세요.--------------------------------
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int arr[] = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        long left = 0, right = 1000000000;
        long answer=0;
        while(left<=right){
            long mid = left + (right - left)/2;
            long sum=0;
            for(int i=0;i<n;i++){
                sum+=Math.max(arr[i]-mid,0);
            }
            if(sum<m){
                right = mid-1;
            }else{
                answer = Math.max(answer,mid);
                left = mid+1;
            }
        }
        System.out.println(answer);
    }

}