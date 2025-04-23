#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;
typedef long long ll;
int n;
int mod = 10007;
ll dp[53][53];

int main() {
	cin >> n;
	dp[0][0] = 1;
	for (int i = 1; i < 53; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
		dp[i][i] = 1;
		dp[1][i] = 1;
	}
	for (int i = 3; i < 53; i++) {
		for (int j = 2; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] ;
		}
	}
	
	ll answer = 0;
	for (int j=1, i = 4, pos = 1; i <= n; j++,i += 4, pos *= -1) {
		answer += pos * ((dp[13][j] * dp[52 - i][n - i]) % mod) %mod;
		if (answer < 0)
			answer += mod;
	}
	cout << answer % mod;
}