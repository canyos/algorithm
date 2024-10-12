#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
int N, M;
int t[100001];
ll result;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> t[i];
	}
	ll left, right, mid;
	left = 1ll, right = 1e18;

	while (left <= right) {
		mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 0; i < N; i++) {
			sum += mid / t[i];
			if (sum > M)
				break;
		}
		if (sum >= M) {
			result = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << result;
	return 0;
}