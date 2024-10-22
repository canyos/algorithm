#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
int t, w;
int arr[1001];
int dp[1001][31];
int result= 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t >> w;
	for (int i = 0; i < t; i++) {
		cin >> arr[i];
	}

	dp[0][0] = (arr[0] == 1 ? 1 : 0);
	dp[0][1] = (arr[0] == 2 ? 1 : 0);

	for (int i = 1; i < t; i++) {
		dp[i][0] = dp[i - 1][0] + (arr[i] == 1 ? 1 : 0);
		for (int j = 1; j <= min(i+1,w); j++) {
			int cur = (j % 2 == 0 ? 1 : 2);//현재위치

			if (arr[i] == cur) //현재위치에 자두 떨어지면 
				dp[i][j] = max(dp[i - 1][j] + 1, dp[i - 1][j - 1]+1); // i-1에서 j번 옮겼을때 최대값 +1 , i-1에서 j-1번 옮겼을때 최대값 +1
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	//for (int j = 0; j <= w; j++) {
	//	for (int i = 0; i < t; i++) {
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	result = max(result, dp[t - 1][w]);
	cout << result;

	
	return 0;
}