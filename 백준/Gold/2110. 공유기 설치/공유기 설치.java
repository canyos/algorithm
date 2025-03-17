import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// --------------솔루션 코드를 작성하세요.--------------------------------
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());

		List<Integer> list = new ArrayList<>();
		int n = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			list.add(Integer.parseInt(st.nextToken()));
		}
		list.sort(Comparator.naturalOrder());

		int left = 1;
		int right = list.get(n - 1) - list.get(0);
		int answer = right;

		while (left <= right) {
			int mid = (left + right) / 2;// 방역 가스 사이 거리

			int sum = 1;
			int last = list.get(0);
			for (int i = 1; i < n; i++) {
				if (list.get(i) - last >= mid) {
					last = list.get(i);
					sum++;
				}
			}

			if (sum < c) {
				right = mid - 1;
			} else {
				if (sum == c)
					answer = mid;
				left = mid + 1;
			}
		}

		bw.write(String.valueOf(right));
		bw.flush();

	}

}
