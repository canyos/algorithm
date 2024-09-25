#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
int n, m;
int temp;
bool small[10001];
int dp[10001][510];
int result=2e9;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);    

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		small[temp] = true;
	}

	if (small[2]) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 509; j++) {
			dp[i][j] = 2e9;
		}
	}

	dp[1][0] = 0;

	for (int i = 2; i <= n; i++) {
		if (small[i]) continue;
		for (int j = 1; j <= min(i,500); j++) {
			if (i - j > 0) {
				dp[i][j] = min(dp[i][j], dp[i - j][j - 1] + 1);

				dp[i][j] = min(dp[i][j], dp[i - j][j] + 1);

				dp[i][j] = min(dp[i][j], dp[i - j][j + 1] + 1);
			}
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 10; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	for (int i = 1; i <150; i++) {
		result = min(result, dp[n][i]);
	}

	if (result >= 2e9)
		result = -1;
	cout << result;
	return 0;

}