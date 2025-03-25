#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <deque>
#include <climits>
#include <stack>
#include <bitset>
#include <unordered_set>
typedef long long ll;

using namespace std;

int n;
const int MOD = 1'000'000'000;
ll dp[101][1<<10][10];

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i < 10; i++) {
		dp[1][1 << i][i] = 1;
	}

	for (int j = 1; j < n; j++) {
		for (int i = 0; i < (1 << 10); i++) {
			for (int k = 0; k < 10; k++) {
				if (k < 9) {
					dp[j + 1][i | (1 << (k + 1))][k + 1] += dp[j][i][k];
					dp[j + 1][i | (1 << (k + 1))][k + 1] %= MOD;
				}
				if (k > 0) {
					dp[j + 1][i | (1 << (k - 1))][k - 1] += dp[j][i][k];
					dp[j + 1][i | (1 << (k - 1))][k - 1] %= MOD;
				}
			}
		}
	}

	ll sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = (sum + dp[n][(1 << 10) - 1][i])%MOD;
	}
	
	cout << sum;


	return 0;
}
