import java.io.*;
import java.util.*;

public class Main {

	
	public static void main(String[] args) throws IOException{
		//--------------솔루션 코드를 작성하세요.--------------------------------
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		//StringTokenizer st = new StringTokenizer(br.readLine());
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		List<Integer> list = new ArrayList<>();
		for(int i=0;i<n;i++) {
			int temp = sc.nextInt();
			list.add(temp);
		}
		
		list.sort(Comparator.naturalOrder());
		
		int m= sc.nextInt();
		loop:for(int i=0;i<m;i++) {
			int target = sc.nextInt();
			int left=0, right=n-1;
			while(left<=right) {
				int mid = (left+right)/2;
				if(list.get(mid)>target) {
					right = mid-1;
				}else if(list.get(mid) < target){
					left = mid+1;
				}else {
					System.out.println(1);
					continue loop;
				}
			}
			System.out.println(0);
		}
	}

}
