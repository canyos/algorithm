import java.util.Scanner;


public class Main {
    static int[][] arr = new int[100002][2]; // 위치 저장
    static long[][] dp = new long[2][5]; //i개를 배달했을때 j위치 마다 최소 거리

    public static Long min(Long a, Long b){
        if(a<=b)
            return a;
        else{
            return b;
        }
    }
    public static long abs(long a){
        if(a>0)
            return a;
        else
            return -a;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        arr[0][0] = scanner.nextInt();
        arr[0][1] = scanner.nextInt();
        long result=Long.MAX_VALUE;

        for(int i=1;i<=n;i++){
            arr[i][0]=scanner.nextInt();
            arr[i][1]=scanner.nextInt();

        }
        //dp[0][0] = dp[0][1]=dp[0][2]=dp[0][3]=dp[0][4] = Long.MAX_VALUE;

        dp[1][0] = abs(arr[1][0]-arr[0][0]) + abs((arr[1][1]+1)-arr[0][1]);
        dp[1][1] = abs((arr[1][0]-1)-arr[0][0]) + abs(arr[1][1]-arr[0][1]);
        dp[1][2] = abs((arr[1][0]+1)-arr[0][0]) + abs(arr[1][1]-arr[0][1]);
        dp[1][3] = abs(arr[1][0]-arr[0][0]) + abs((arr[1][1]-1)-arr[0][1]);
        dp[1][4] = abs(arr[1][0]-arr[0][0]) + abs(arr[1][1]-arr[0][1]);

//        for(int i=0;i<=4;i++){
//            System.out.print(dp[1][i]+" ");
//        }
//        System.out.println();
        for(int i=2;i<=n;i++){
            //위에서 위
            dp[i%2][0] = dp[(i-1)%2][0] + abs(arr[i][0] - arr[i-1][0]) + abs((arr[i][1]+1) -  (arr[i-1][1]+1));
            //왼쪽에서 위
            dp[i%2][0] = min(dp[i%2][0], dp[(i-1)%2][1] + abs(arr[i][0] - (arr[i-1][0]-1)) + abs((arr[i][1]+1) -  arr[i-1][1]));
            //오른쪽에서 위
            dp[i%2][0] = min(dp[i%2][0], dp[(i-1)%2][2] + abs(arr[i][0] - (arr[i-1][0]+1)) + abs((arr[i][1]+1) -  arr[i-1][1]));
            //아래에서 위
            dp[i%2][0] = min(dp[i%2][0], dp[(i-1)%2][3] + abs(arr[i][0] - arr[i-1][0]) + abs((arr[i][1]+1) -  (arr[i-1][1]-1)));
            //중간에서 위
            dp[i%2][0] = min(dp[i%2][0], dp[(i-1)%2][4] + abs(arr[i][0] - arr[i-1][0]) + abs((arr[i][1]+1) -  (arr[i-1][1])));


            //위에서 왼쪽
            dp[i%2][1] = dp[(i-1)%2][0] + abs((arr[i][0]-1) - arr[i-1][0]) + abs(arr[i][1] -  (arr[i-1][1]+1));
            //왼쪽에서 왼쪽
            dp[i%2][1] = min(dp[i%2][1], dp[(i-1)%2][1] + abs((arr[i][0]-1) - (arr[i-1][0]-1)) + abs(arr[i][1] -  arr[i-1][1]));
            //오른쪽에서 왼쪽
            dp[i%2][1] = min(dp[i%2][1], dp[(i-1)%2][2] + abs((arr[i][0]-1) - (arr[i-1][0]+1)) + abs(arr[i][1] -  arr[i-1][1]));
            //아래에서 왼쪽
            dp[i%2][1] = min(dp[i%2][1], dp[(i-1)%2][3] + abs((arr[i][0]-1) - arr[i-1][0]) + abs(arr[i][1] -  (arr[i-1][1]-1)));
            //중간에서 왼쪽
            dp[i%2][1] = min(dp[i%2][1], dp[(i-1)%2][4] + abs((arr[i][0]-1)  - arr[i-1][0]) + abs(arr[i][1] -  (arr[i-1][1])));


            //위에서 오른쪽
            dp[i%2][2] = dp[(i-1)%2][0] + abs((arr[i][0]+1) - arr[i-1][0]) + abs(arr[i][1] - ( arr[i-1][1]+1));
            //왼쪽에서 오른쪽
            dp[i%2][2] = min(dp[i%2][2], dp[(i-1)%2][1] + abs((arr[i][0]+1) - (arr[i-1][0]-1)) + abs(arr[i][1] -  arr[i-1][1]));
            //오른쪽에서 오른쪽
            dp[i%2][2] = min(dp[i%2][2], dp[(i-1)%2][2] + abs((arr[i][0]+1) - (arr[i-1][0]+1)) + abs(arr[i][1] -  arr[i-1][1]));
            //아래에서 오른쪽
            dp[i%2][2] = min(dp[i%2][2], dp[(i-1)%2][3] + abs((arr[i][0]+1) - arr[i-1][0]) + abs(arr[i][1] -  (arr[i-1][1]-1)));
            //중간에서 오른쪽
            dp[i%2][2] = min(dp[i%2][2], dp[(i-1)%2][4] + abs((arr[i][0]+1)  - arr[i-1][0]) + abs(arr[i][1] -  (arr[i-1][1])));


            //위에서 아래
            dp[i%2][3] = dp[(i-1)%2][0] + abs(arr[i][0] - arr[i-1][0]) + abs((arr[i][1]-1) -  (arr[i-1][1]+1));
            //왼쪽에서 아래
            dp[i%2][3] = min(dp[i%2][3], dp[(i-1)%2][1] + abs(arr[i][0] - (arr[i-1][0]-1)) + abs((arr[i][1]-1) -  arr[i-1][1]));
            //오른쪽에서 아래
            dp[i%2][3] = min(dp[i%2][3], dp[(i-1)%2][2] + abs(arr[i][0] - (arr[i-1][0]+1)) + abs((arr[i][1]-1) -  arr[i-1][1]));
            //아래에서 아래
            dp[i%2][3] = min(dp[i%2][3], dp[(i-1)%2][3] + abs(arr[i][0] - arr[i-1][0]) + abs((arr[i][1]-1) -  (arr[i-1][1]-1)));
            //중간에서 아래
            dp[i%2][3] = min(dp[i%2][3], dp[(i-1)%2][4] + abs(arr[i][0] - arr[i-1][0]) + abs((arr[i][1]-1) -  (arr[i-1][1])));

            //위에서 중간
            dp[i%2][4] = dp[(i-1)%2][0] + abs(arr[i][0] - arr[i-1][0]) + abs(arr[i][1] -  (arr[i-1][1]+1));
            //왼쪽에서 중간
            dp[i%2][4] = min(dp[i%2][4], dp[(i-1)%2][1] + abs(arr[i][0] - (arr[i-1][0]-1)) + abs(arr[i][1] -  arr[i-1][1]));
            //오른쪽에서 중간
            dp[i%2][4] = min(dp[i%2][4], dp[(i-1)%2][2] + abs(arr[i][0] - (arr[i-1][0]+1)) + abs(arr[i][1] -  arr[i-1][1]));
            //아래에서 중간
            dp[i%2][4] = min(dp[i%2][4], dp[(i-1)%2][3] + abs(arr[i][0] - arr[i-1][0]) + abs(arr[i][1] -  (arr[i-1][1]-1)));
            //중간에서 중간
            dp[i%2][4] = min(dp[i%2][4], dp[(i-1)%2][4] + abs(arr[i][0] - arr[i-1][0]) + abs(arr[i][1] -  (arr[i-1][1])));
//            for(int j=0;j<=4;j++){
//                System.out.print(dp[i%2][j]+" ");
//            }
//            System.out.println();
        }

        for(int i=0;i<=4;i++){
            result = min(result, dp[n%2][i]);
        }
        System.out.println(result);
    }
}