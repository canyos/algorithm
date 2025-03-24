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

bool isSame[2501][2501];
int dp[2501];

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int n = str.length();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i - j < 0 || i + j >= n)break;
			if (str[i - j] != str[i + j])break;

			isSame[i - j][i + j] = true;
		}
	}

	for (int i = 0; i < n; i++) {
		int left = i, right = i + 1;
		for (int j = 0; j < n; j++) {
			if (left - j < 0 || right + j >= n)break;
			if (str[left - j] != str[right + j])break;

			isSame[left - j][right + j] = true;
		}
	}

	for (int i = 0; i < n; i++) {
		dp[i] = dp[i-1]+1;
		for (int j = 0; j < i; j++) {
			if (isSame[j][i]) {
				if (j == 0)
					dp[i] = min(1, dp[i]);
				else
					dp[i] = min(dp[j - 1] + 1, dp[i]);
			}
		}
	}

	cout << dp[n - 1];


	return 0;
}
