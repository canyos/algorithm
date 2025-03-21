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

int n, m, k;
int candy[30001];
vector<int> edges[30001];
vector<pair<int, int>> group;
bool visited[30001];
queue<int> qu;
int dp[30001][3001];

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> candy[i];

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			int sumChild = 1;
			int sumCandy = candy[i];
			qu.push(i);
			visited[i] = true;
			while (!qu.empty()) {
				int cur = qu.front(); qu.pop();
				for (int next : edges[cur]) {
					if (!visited[next]) {
						qu.push(next);
						visited[next] = true;
						sumChild++;
						sumCandy += candy[next];
					}
				}
			}
			group.push_back({ sumChild,sumCandy });
		}
	}

	for (int i = 0; i < group.size(); i++) {
		auto cur = group[i];
		for (int j = 0; j < k; j++) {
			if (i == 0) {
				if (cur.first <= j) {
					dp[i][j] = cur.second;
				}
			}
			else {
				dp[i][j] = dp[i - 1][j];
				if (cur.first <= j) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - cur.first] + cur.second);
				}
			}
		}
	}

	cout << dp[group.size() - 1][k - 1];

	return 0;
}
