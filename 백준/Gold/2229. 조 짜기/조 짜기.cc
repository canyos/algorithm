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
int dp[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);    

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++) { //새로 들어갈거
		int m = arr[i];
		int M = arr[i];
		for (int j = i - 1; j >= 0; j--) { //새로운거가 어디까지 묶을지
			m = arr[i];
			M = arr[i];
			for (int k = j; k <= i; k++) {
				if (m > arr[k]) m = arr[k];
				if (M < arr[k])M = arr[k];
			}
			//새로운 거 넣은 묶음의 합 + dp[j-1]의 최대값으로 갱신
			dp[i] = max(dp[i], dp[j - 1] + M - m);
		}
	}
	
	cout << dp[n - 1];
	return 0;

}