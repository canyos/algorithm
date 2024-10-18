#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
int T, N,M;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T ;
	for (int t = 0; t < T; t++) {
		int dp[21][10001] = { 0 };
		int coin[21] = { 0 };
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> coin[i];
		}
		cin >> M;
		for (int i = 1; i <= N; i++) {
			int c = coin[i];
			for (int j = 1; j <= M; j++) {
				for (int k = 0; k*c <= j; k++) {
					dp[i][j] += dp[i - 1][j - c * k];
				}
				if (j%c == 0)
					dp[i][j] += 1;
			}
		}
		
		cout << dp[N][M] << endl;
	}
	


	
	return 0;
}