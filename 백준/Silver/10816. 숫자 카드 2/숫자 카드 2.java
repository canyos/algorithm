import java.io.*;
import java.util.*;

public class Main {
    static List<Integer> list;
    public static int lower_bound(int left, int right,int target) {
        while(left<right) {
            int mid = (left+right)/2;
            if(list.get(mid)<target) {
                left = mid+1;
            }else {
                right = mid;
            }
        }

        return right;
    }
    public static int upper_bound(int left, int right,int target) {
        while(left<right) {
            int mid = (left+right)/2;
            if(list.get(mid)<=target) {
                left = mid+1;
            }else {
                right = mid;
            }
        }

        return right;
    }
    public static void main(String[] args) throws IOException{
        //--------------솔루션 코드를 작성하세요.--------------------------------
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());


        int n = Integer.parseInt(st.nextToken());
        list = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) {
            int temp = Integer.parseInt(st.nextToken());
            list.add(temp);
        }

        list.sort(Comparator.naturalOrder());

        st = new StringTokenizer(br.readLine());
        int m= Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        loop:for(int i=0;i<m;i++) {
            int target = Integer.parseInt(st.nextToken());

            int ub = upper_bound(0,n,target);
            int lb = lower_bound(0,n,target);
            //System.out.println(ub + " " + lb);
            bw.write((ub-lb) + " ");
        }
        bw.flush();
    }

}