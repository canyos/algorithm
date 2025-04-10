import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	public static void main(String[] args)throws Exception {
		
		char[] text = br.readLine().toCharArray();
		char[] pattern = br.readLine().toCharArray();
		
		int tLen = text.length;
		int pLen = pattern.length;
		
		int[] pi = new int[pLen];
		for(int i=1,j=0;i<pLen;i++) {
			while(j>0 && pattern[i]!=pattern[j]) {
				j=pi[j-1];
			}
			if(pattern[i] == pattern[j]) {
				pi[i] = ++j;			
			}
			else {
				pi[i] = 0;
			}
		}
		
		//System.out.println(Arrays.toString(pi));
		
		int cnt=0;
		List<Integer> list = new ArrayList<>();
		for(int i=0, j=0;i<tLen;i++) {
			while(j>0 && text[i] != pattern[j]) {
				j=pi[j-1];
			}
			if(text[i] == pattern[j]) {
				if(j==pLen-1) {
					cnt++;
					list.add(i-j);
					j=pi[j];
				}else {
					j++;
				}
			}
		}
		System.out.println(cnt);
		for(int idx : list) {
			System.out.println(idx+1);
		}
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
