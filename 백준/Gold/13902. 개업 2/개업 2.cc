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
int arr[1001];
vector<int> v;
int answer = -1;
int dp[10001];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1e9;
	}
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
		v.push_back(arr[i]);
	}
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			v.push_back(arr[i] + arr[j]);
		}
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int sz = v.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sz; j++) {
			if (i + v[j] > n)break;
			dp[i + v[j]] = min(dp[i+v[j]], dp[i] + 1);
		}
	}

	if (dp[n] == 1e9)dp[n] = -1;
	cout << dp[n];
	return 0;
}