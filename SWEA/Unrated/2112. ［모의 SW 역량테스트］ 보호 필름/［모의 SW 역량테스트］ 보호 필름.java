import java.io.*;
import java.util.*;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static int d,w,k;
	static int arr[][];
	static int map[][];
	static int answer;
	static boolean isEnd=false;
	static int[] selected;
	
	public static int nextInt() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());
		}
		return Integer.parseInt(st.nextToken());
	}
	
	private static void swap(int[] list, int i, int j) {
		int temp = list[i];
		list[i] = list[j];
		list[j] = temp;
	}
	
	private static boolean next_permutation(int[] origin) {
		int i = d - 1;
		while(i > 0 && origin[i - 1] >= origin[i]) --i;
		if(i == 0) return false;
		
		int j = d - 1;
		while(origin[i - 1] >= origin[j]) --j;
		
		int tmp = origin[i - 1];
		origin[i - 1] = origin[j];
		origin[j] = tmp;
		
		int k = d - 1;
		while(i < k) {
			tmp = origin[i];
			origin[i] = origin[k];
			origin[k] = tmp;
			++i;
			--k;
		}
		return true;
	}
	
	public static void recursive(int pos, int[] bitmap) {//
		if(pos == d) {
			
			loop:for(int c=0;c<w;c++) {
				r:for(int r=0;r<=d-k;r++) {
					int value = map[r][c];
					for(int j=1;j<k;j++) {//다음 k개 같냐?
						if(map[r+j][c]!=value) {
							continue r;//다르면 행 내려
						}
					}
					continue loop;//같으면 다음 열 체크해
				}
				return;//한 행에 같은거 없으면 리턴
			}//모든 행에 같은거있음
			isEnd = true;
			return; 
		}
		if(bitmap[pos] > 0) {//pos행이 선택됨
			for(int i=0;i<w;i++) 
				map[pos][i] = 0;//pos행 0으로 선택
			recursive(pos+1, bitmap);
			if(isEnd)return;
			
			for(int i=0;i<w;i++) 
				map[pos][i] = 1;//pos행 1로 선택
			recursive(pos+1, bitmap);
			if(isEnd)return;
			
			for(int i=0;i<w;i++) 
				map[pos][i] = arr[pos][i];//원래 값으로 복귀
		}
		else {
			recursive(pos+1,bitmap);
			if(isEnd)return;
		}
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int tc = nextInt();
		for(int t=1;t<=tc;t++) {
			d = nextInt();
			w = nextInt();
			k = nextInt();
			
			isEnd = false;
			arr = new int [d][w];
			map = new int [d][w];
			answer = k;
			selected = new int[d];
			for(int i=0;i<d;i++) {
				for(int j=0;j<w;j++) {
					arr[i][j] = nextInt();
					map[i][j] = arr[i][j];
				}
			}
			
			
			loop:for(int r=0 ; r<d ; r++) {//r개 고를거임
				for(int i=0;i<d-r; i++)
					selected[i] = 0;
				for(int i=d-r;i<d;i++)
					selected[i] = 1;
				do {
					//System.out.println(Arrays.toString(selected));
					recursive(0, selected);//
					if(isEnd) {
						answer = r;
						break loop;
					}
				}while(next_permutation(selected));
			}
			System.out.println("#" + t + " " + answer);
		}
	}

}
