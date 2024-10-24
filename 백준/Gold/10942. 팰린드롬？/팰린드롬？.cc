#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
int n, m;
int arr[2001];
int dp[2001][2001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
		for (int j = 1; j <= n / 2; j++) {
			if (i - j <= 0 || i + j > n)break;
			if (arr[i - j] == arr[i + j])
				dp[i - j][i + j] = 1;
			else
				break;
		}
		if (arr[i] == arr[i - 1]) {
			dp[i-1][i] = 1;
			for (int j = 1; j <= n / 2; j++) {
				if (i - j - 1 <= 0 || i + j > n)break;
				if (arr[i - j - 1] == arr[i + j])
					dp[i - j - 1][i + j] = 1;
				else
					break;
			}
		}
	}


	cin >> m;
	int start, end;
	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		cout << dp[start][end] << '\n';
	}
	
	return 0;
}