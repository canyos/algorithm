#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
ll nCr[10001];
int N, mod = 987654321;
ll dp[10001];


ll sol(int n) {
	if (n == 0 || n == 2) return 1;

	ll& ret = dp[n];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <= n - 2; i += 2) {
		ret += sol(i)*sol(n - 2 - i);
		ret %= mod;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i <= N; i++) {
		dp[i] = -1;
	}
	printf("%lld", sol(N));
	return 0;
}