#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
int n;
int t[1500001];
int p[1500001];
vector<pair<int,int>> tp[1510000];
int dp[1500001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
		tp[i + t[i] -1].push_back({ t[i], p[i] });
	}

	for (int i = 1 ; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (t[i] == 1)
			dp[i] += p[i];
		
			
		for (auto it : tp[i]) {
			dp[i] = max(dp[i], dp[i - it.first] + it.second);
		}

		//cout << i << " " << dp[i] <<endl;
	}
	
	cout << dp[n];
	
	return 0;
}