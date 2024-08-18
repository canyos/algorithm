#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> item;
int dp[101][100001];

int N, K, w, v;
int result;

void input() {
	item.push_back({ 0,0 });
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> w >> v;
		item.push_back({ w,v });
	}
}

int main() {
	input();
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= N; i++) {
		int tw = item[i].first, tv = item[i].second;
		for (int j = 1; j <= K; j++) {
			if (j < tw)dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i-1][j],dp[i - 1][j - tw] + tv);
			/*cout << i << " " << j << "\n";*/
		}
		result = max(result, dp[i][K]);
	}
	
	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= K; j++) {
	//		cout << dp[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	cout << result;
	return 0;
}