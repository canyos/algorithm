import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	public static int nextInt() throws IOException {
		if(st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());
		}
		return Integer.parseInt(st.nextToken());
	}	
	
	static List<String> list;
	public static void recursive(int pos,int seq[], int n, int r) throws IOException {
		if(pos == r) {
			String answer="";
			int cnt1=0, cnt2=0;
			for(int i=0;i<r;i++) {
				String str = list.get(seq[i]);
				answer+=str;
				if(str.equals("a") || str.equals("e") ||str.equals("i") ||str.equals("o") ||str.equals("u") )cnt1++;
				else cnt2++;
			}
			
			if(cnt1>=1 && cnt2>=2)
			//bw.write(Arrays.toString(seq)+"\n");
				bw.write(answer + "\n");
			return;
		}
		for(int i=(pos==0?0:seq[pos-1]+1);i<n;i++ ) {
			seq[pos]=i;
			recursive(pos+1,seq,n,r);
		}
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int r = nextInt();
		int n = nextInt();
		list = new ArrayList<>();
		st=  new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			list.add(st.nextToken());
		}
		list.sort(Comparator.naturalOrder());
		
		recursive(0,new int[r], n, r);
		bw.flush();
	}

}
