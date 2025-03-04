import java.io.*;
import java.util.*;

public class Solution {
    public static long lower_bound(long arr[], long n){
        int s=0, e= 1000001;
        while(s<e){
            int m = (s+e)/2;
            if(arr[m]<n){
                s=m+1;
            }else{
                e=m;
            }
        }
        return arr[e];
    }
    public static void main(String[] args) throws IOException{
        //--------------솔루션 코드를 작성하세요.--------------------------------
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long arr[] = new long[1000001];
        for(long i=1;i<1000001;i++){
            arr[(int)i] = i*i;
        }

        int tc = Integer.parseInt(st.nextToken());
        for (int t=1;t<=tc;t++) {
            st = new StringTokenizer(br.readLine());
            long n = Long.parseLong(st.nextToken());
            long sum=0;
            while(n>2){
                long lb =lower_bound(arr,n);
                sum+= lb-n;
                n=lb;
                n= (long) (Math.sqrt((double)n));
                sum++;
            }

            System.out.println("#"+t+ " " +sum);

        }
    }

}