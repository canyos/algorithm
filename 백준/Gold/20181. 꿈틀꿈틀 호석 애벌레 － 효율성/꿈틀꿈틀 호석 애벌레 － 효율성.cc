#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>

using namespace std;
int N, M, K;
int arr[100001];
long long dp[100001];
class stick {
public:
	int start;
	int end;
	int value;

	stick(int start, int end, long long value) {
		this->start = start;
		this->end = end;
		this->value = value;
	}
};

vector<stick> sticks[100001];

void input() {
	cin >> N  >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void twoPointer() {
	int left = 1, right = 1;
	int sum = arr[1];
	while (right <= N) {
		if (sum >= K) {
			sticks[right].push_back(stick(left, right, sum - K));
			sum -= arr[left];
			left++;

		}
		else {
			right++;
			sum += arr[right];
		}
	}
}

void DP() {
	for (int i = 1; i <= N; i++) {
		long long temp = 0;
		for (int j = 0; j < (int)sticks[i].size(); j++) {
			temp = max(temp, dp[sticks[i][j].start - 1] + sticks[i][j].value);
		}
		dp[i] = max(dp[i - 1], temp);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	twoPointer();
	DP();

	cout << dp[N];
	return 0;
}