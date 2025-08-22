#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string>
#include <cstring>
#include <bitset>
#include <vector>
#include <map>
#define endl "\n"
using namespace std;
typedef long long ll;
const ll INF = 1e9;

int n, m;
int arr[100001];
ll dp[5][100001];
int sum[100001];
int quarter;
vector<int> v[5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sum[0] = arr[0];
	for (int i = 1; i < n; i++) 
		sum[i] = sum[i - 1] + arr[i];
	
	quarter = sum[n - 1]/4;

	for (int i = 0; i < n; i++) {
		for (int k = 1; k <= 4; k++) {
			if (quarter * k == sum[i])
				v[k].push_back(i);
		}
	}

	for (auto idx : v[1]) {
		dp[1][idx] = 1;
	}

	for (int k = 2; k <= 4; k++) {
		for (int idx : v[k]) {//합이 k인거
			for (int prev : v[k - 1]) {
				if (prev >= idx)break;
				dp[k][idx] += dp[k - 1][prev];
			}
		}
	}
		
	cout << dp[4][n - 1];


	return 0;
}