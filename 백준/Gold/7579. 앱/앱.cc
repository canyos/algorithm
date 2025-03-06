#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <deque>

using namespace std;

int answer=1e9+1;
int n, m;
int memory[101];
int time[101];
int dp[101][10001];

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> memory[i];
	for (int i = 0; i < n; i++)
		cin >> time[i];

	for (int i = time[0]; i < 10001; i++)
		dp[0][i] = memory[0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10001; j++) {
			if (j < time[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time[i]] + memory[i]);

			/*if (dp[i][j] >= m) 
				answer = min(answer, j);*/
		}
	}

	for (int c = 0; c < 10001; c++) {
		if (dp[n - 1][c] >= m)
		{
			answer = c;
			break;
		}
	}

	cout << answer;
	return 0;
}
