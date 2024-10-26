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
int arr[1001][1001];
int dp[1001][1001][3];
int result;
bool isZero = true;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++) {
		int j = 0;
		cin >> str;
		for (auto it : str) {
			arr[i][j] = it - '0';

			if (arr[i][j] == 1) isZero = false;
			j++;
		}
		
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)
				continue;
			else if (i == 0) {
				dp[0][j][0] = dp[0][j-1][0]+1;
				dp[0][j][1] = 1;
				dp[0][j][2] = 1;
			}
			else if (j==0) {
				dp[i][0][0] = 1;
				dp[i][j][1] = dp[i - 1][j][1] + 1;
				dp[i][j][2] = 1;
			}
			else {
				dp[i][j][0] = dp[i][j - 1][0] + 1;
				dp[i][j][1] = dp[i - 1][j][1] + 1;
				if (min(dp[i][j][0], dp[i][j][1])-1 >= dp[i - 1][j - 1][2]) {
					dp[i][j][2] = dp[i - 1][j - 1][2] + 1;
				}
				else  {
					dp[i][j][2] = min(dp[i][j][0], dp[i][j][1]);
				}
				result = max(dp[i][j][2] * dp[i][j][2], result);
			}
		}
	}
	//
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << dp[i][j][2] << " ";
	//	}
	//	cout << endl;
	//}

	if (isZero)
		cout << "0";
	else if (result == 0)
		cout << "1";
	else
		cout << result;
	
	return 0;
}