import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	public static void main(String[] args)throws Exception {
		String str = br.readLine();
		List<String> list = new ArrayList<>();
		String temp = "";
		for( int i = str.length()-1; i>=0;i--) {
			temp= str.charAt(i)+ temp;
			list.add(temp);
		}
		
		list.sort(Comparator.naturalOrder());
		for(String s : list) {
			bw.write(s+"\n");
		}
		bw.flush();
	}
	
	static int nextInt() throws IOException {
		if(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return Integer.parseInt(st.nextToken());
	}
}
