import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()), s = Integer.parseInt(st.nextToken());
		int arr[] = new int[n];
		st= new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		int left=0,right=1;
		int temp = arr[0];
		int answer=100001;
		while(left<n && right<=n) {
			
			if(temp>=s) {
				//System.out.println(left + " " + right);
				answer=Math.min(answer, right-left);
				temp-=arr[left++];
			}
			else if(temp<s) {
				if(right==n)break;
				temp+=arr[right++];
			}
		}
		if(answer==100001)answer=0;
		bw.write(String.valueOf(answer));
		bw.flush();
	}

}
