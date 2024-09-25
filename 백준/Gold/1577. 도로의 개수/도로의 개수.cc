#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
int n, m, k;
int a, b, c, d;
ll dp[105][105];
map<tuple<int, int, int, int>, bool> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);    

	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b >> c >> d;
		if (a > c || b > d)
			mp[{d, c, b, a}] = true;
		else
			mp[{b, a, d, c}] = true;
	}

	dp[0][0]  = 1;

	for (int i = 1; i <= n; i++) { //가로
		if (mp[{0, i - 1, 0, i}] == false) 
			dp[0][i] = 1;
		else
			break;
	}

	for (int i = 1; i <= m; i++) { //세로
		if (mp[{i-1, 0, i, 0}] == false) 
			dp[i][0] = 1;
		else
			break;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (mp[{i - 1, j, i, j}] == false) {
				dp[i][j] += dp[i - 1][j];
			}
			if (mp[{i, j - 1, i, j}] == false) {
				dp[i][j] += dp[i][j - 1];
			}
		}
	}

	cout << dp[m][n] << endl;
	return 0;

}