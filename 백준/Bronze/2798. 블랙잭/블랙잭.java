import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static int answer=0;
	public static int n,m;
	public static int arr[];
	
	public static void recursive(int pos, int[] seq, int sum) {
		if(sum>m)return;
		if(pos == 3) {
			answer = Math.max(sum, answer);
			//System.out.println(sum);
			//System.out.println(Arrays.toString(seq));
			return;
		}
		for(int i=(pos==0?0:seq[pos-1]+1);i<n;i++) {
			seq[pos] = i;
			recursive(pos+1,seq,sum+arr[i]);
		}
	}
	
	public static void main(String[] args){
		//--------------솔루션 코드를 작성하세요.--------------------------------
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		
		arr = new int[n];
		for(int i=0;i<n;i++)
			arr[i] = sc.nextInt();
		
		recursive(0, new int[3], 0);
		
		System.out.println(answer);
	}

}
