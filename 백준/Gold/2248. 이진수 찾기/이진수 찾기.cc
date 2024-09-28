#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
int N, L;
ll I;
string result="";
int dp[32][32];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);    

	cin >> N >> L >> I;
	dp[0][0] = 1;

	for (int i = 0; i < 32; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	for (int i = 1; i < 32; i++) {
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}


	for (int i = N-1; i >= 0; i--) {
		ll sum = 0;
		for (int j = 0; j <= L; j++) {
			sum += dp[i][j];
		}
		if (sum < I) {
			result += "1";
			I -= sum;
			L -= 1;
		}
		else {
			result += "0";	
		}
	}


	cout << result;
	return 0;

}