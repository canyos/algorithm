#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <string>

typedef long long ll;
using namespace std;
int n, m;
int INF = 1e9;
int arr[51][51];
bool visited[51][51];
int dp[51][51];
int dr[] = { 0,0,-1,1 }, dc[] = { -1,1,0,0 };

bool checkPos(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

int recursive(int r, int c, int depth) {
	if (arr[r][c] == 0)return depth - 1;
	if (dp[r][c] >= 0) {
		if (dp[r][c] == INF)return INF;
		else return depth + dp[r][c];
	}
	if (visited[r][c])return INF;

	int res = depth;
	visited[r][c] = true;
	for (int k = 0; k < 4; k++) {
		int tr = r + dr[k] * arr[r][c], tc = c + dc[k] * arr[r][c];
		if (checkPos(tr, tc)) {
			res = max(res, recursive(tr, tc, depth + 1));
		}
	}
	visited[r][c] = false;
	if (res == INF)dp[r][c] = INF;
	else dp[r][c] = res - depth;
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	fill(&dp[0][0], &dp[0][0] + 51 * 51, -1);
	cin >> n >> m;
	char ch;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ch;
			if (ch == 'H')
				arr[i][j] = 0;
			else
				arr[i][j] = ch - '0';
		}
	}

	int answer = 1;
	answer = max(answer, recursive(0, 0, 1));
	if (answer == INF)answer = -1;
	cout << answer;

	return 0;
}