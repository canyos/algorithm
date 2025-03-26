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
int dist[16][16];
int dp[16][1<<16][16];
const int INF = 1e6 * 16 + 1;
int MOD = 1e8;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;
	int n2 = 1 << n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> dist[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n2; j++) {
			for (int k = 0; k < n; k++) {
				dp[i][j][k] = INF;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		dp[0][1 << i][i] = i * MOD;
	}

	for (int i = 0; i < n-1; i++) {//현재 자리수
		for (int j = 0; j < n2; j++) {//비트
			for (int k = 0; k < n; k++) {//현재 끝 숫자
				int cur = dp[i][j][k] % MOD, first = dp[i][j][k] / MOD;
				for (int l = 0; l < n; l++) {//다음에 올 숫자
					if (cur < INF && dist[k][l] && !(j&(1<<l)) ) {
						if (dp[i + 1][j | (1 << l)][l] % MOD > cur + dist[k][l]) {
							dp[i + 1][j | (1 << l)][l] = cur + dist[k][l];
							dp[i + 1][j | (1 << l)][l] += first * MOD;
						}
					}
				}
			}
		}
	}	

	int answer = INF;
	for (int k = 0; k < n; k++) {//현재 끝 숫자
		int cur = dp[n - 1][n2 - 1][k] % MOD;
		int next = dp[n - 1][n2 - 1][k] / MOD;

		if (cur < INF && k!=next && dist[k][next]) {
			answer = min(answer, cur + dist[k][next]);
		}
	}
	

	cout << answer;

	return 0;
}
