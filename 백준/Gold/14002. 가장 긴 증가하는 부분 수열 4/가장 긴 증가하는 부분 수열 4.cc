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
int arr[1001];
pair<int,int> dp[1001];
pair<int, int> result = { 0,1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		dp[i] = { -1,1 };
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j]) {
				if (dp[j].second >= dp[i].second) {
					dp[i] = { j,dp[j].second + 1 };
					if (result.second < dp[i].second) {
						result = { i, dp[i].second };
					}
				}
			}
		}
		
	}
	

	cout << result.second << '\n';
	vector<int> v;
	int i = result.first;

	while (i!=-1) {
		v.push_back(arr[i]);
		i = dp[i].first;
	}

	reverse(v.begin(), v.end());
	for (auto it : v) {
		cout << it << " ";
	}
	
	return 0;
}