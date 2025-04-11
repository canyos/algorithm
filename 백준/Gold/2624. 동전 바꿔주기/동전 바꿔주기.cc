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
int answer = -1;
vector<pair<int, int>> v;
int dp[101][10001];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
		dp[i][0] = 1;
	}

	for (int i = 1; i <= v[0].second; i++) {
		dp[0][i*v[0].first] = 1;
	}

	for (int i = 1; i < m; i++) {//동전
		for (int j = 1; j <= n; j++) {//돈
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; k <= v[i].second; k++) {//개수
				if (j - k * v[i].first < 0)break;
				dp[i][j] += dp[i - 1][j - k * v[i].first];
			}
		}
	}

	cout << dp[m-1][n];
	return 0;
}