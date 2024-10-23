#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
string str;
vector<int> arr;
int dp[5001];
int len;
bool isBreak;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin >> str;
	if (  str[0] == '0' )
		isBreak = true;
	if(str.compare("0") == 0)
		isBreak = true;

	for (auto it : str) {
		char a = it - '0';
		
		if (a < 0 || a > 26) 
			isBreak = true;
		if (a == 0 && len>0 && (arr[len-1] >= 3 || arr[len-1]==0))
			isBreak = true;
		arr.push_back(a);
		len++;
	}

	dp[0]= dp[1] = 1;
	for (int i = 2; i <= len; i++) {
		if (arr[i - 1] == 0)
			dp[i] += dp[i - 2];

		else if (arr[i - 2] == 0)
			dp[i] += dp[i - 1];

		else {
			int temp = arr[i - 2] * 10 + arr[i - 1];
			if (temp <= 26)
				dp[i] += dp[i - 2];

			dp[i] += dp[i - 1];
		}
			

		dp[i] %= 1000000;
	}

	if (isBreak)
		cout << "0";
	else
		cout << dp[len];
	
	return 0;
}