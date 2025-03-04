import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) throws IOException{
        //--------------솔루션 코드를 작성하세요.--------------------------------
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int tc = Integer.parseInt(st.nextToken());
        for(int t=1;t<=tc;t++){
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            String dir = st.nextToken();
            int arr[][] = new int[n][n];

            for(int i=0;i<n;i++){
                st = new StringTokenizer(br.readLine());
                for(int j=0;j<n;j++){
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            if(dir.equals("up")){
                for(int i=0;i<n;i++){//열
                    loop:for(int j=0;j<n;j++){//행
                        if(arr[j][i] == 0){
                            for(int k=j+1;k<n;k++){
                                if(arr[k][i] !=0){
                                    arr[j][i] = arr[k][i];
                                    arr[k][i] = 0;
                                    j--;
                                    break;
                                }
                            }
                        }
                        else{
                            for(int k=j+1;k<n;k++){//다음행
                                if(arr[k][i]==0)continue;
                                if(arr[j][i] == arr[k][i]){
                                    arr[j][i] +=arr[j][i];
                                    arr[k][i] =0;
                                }else{
                                    if(j+1!=k) {
                                        arr[j + 1][i] = arr[k][i];
                                        arr[k][i] = 0;
                                    }
                                }
                                continue loop;
                            }
                        }
                    }
                }
            }

            if(dir.equals("down")){
                for(int i=0;i<n;i++){//열
                    loop:for(int j=n-1;j>=0;j--){//행
                        if(arr[j][i] == 0){
                            for(int k=j-1;k>=0;k--){
                                if(arr[k][i] !=0){
                                    arr[j][i] = arr[k][i];
                                    arr[k][i] = 0;
                                    j++;
                                    break;
                                }
                            }
                        }
                        else{
                            for(int k=j-1;k>=0;k--){//다음행
                                if(arr[k][i]==0)continue;
                                if(arr[j][i] == arr[k][i]){
                                    arr[j][i] +=arr[j][i];
                                    arr[k][i] =0;
                                }else{
                                    if(j-1!=k) {
                                        arr[j - 1][i] = arr[k][i];
                                        arr[k][i] = 0;
                                    }
                                }
                                continue loop;
                            }
                        }
                    }
                }
            }

            if(dir.equals("left")){
                for(int i=0;i<n;i++){//행
                    loop:for(int j=0;j<n;j++){//열
                        if(arr[i][j] == 0){
                            for(int k=j+1;k<n;k++){
                                if(arr[i][k] !=0){
                                    arr[i][j] = arr[i][k];
                                    arr[i][k] = 0;
                                    j--;
                                    break;
                                }
                            }
                        }
                        else{
                            for(int k=j+1;k<n;k++){//다음행
                                if(arr[i][k]==0)continue;
                                if(arr[i][j] == arr[i][k]){
                                    arr[i][j] +=arr[i][j];
                                    arr[i][k] =0;
                                }else{
                                    if(j+1!=k) {
                                        arr[i][j+1] = arr[i][k];
                                        arr[i][k] = 0;
                                    }
                                }
                                continue loop;
                            }
                        }
                    }
                }
            }

            if(dir.equals("right")){
                for(int i=0;i<n;i++){//행
                    loop:for(int j=n-1;j>=0;j--){//열
                        if(arr[i][j] == 0){
                            for(int k=j-1;k>=0;k--){
                                if(arr[i][k] !=0){
                                    arr[i][j] = arr[i][k];
                                    arr[i][k] = 0;
                                    j++;
                                    break;
                                }
                            }
                        }
                        else{
                            for(int k=j-1;k>=0;k--){//다음행
                                if(arr[i][k]==0)continue;
                                if(arr[i][j] == arr[i][k]){
                                    arr[i][j] +=arr[i][j];
                                    arr[i][k] =0;
                                }else{
                                    if(j-1!=k) {
                                        arr[i][j-1] = arr[i][k];
                                        arr[i][k] = 0;
                                    }
                                }
                                continue loop;
                            }
                        }
                    }
                }
            }

            bw.write("#"+t+'\n');
            for(int i=0;i<n;i++) {//열
                for (int j = 0; j < n; j++) {//행
                    bw.write(arr[i][j] + " ");
                }
                bw.write("\n");
            }
            bw.flush();
        }
    }

}