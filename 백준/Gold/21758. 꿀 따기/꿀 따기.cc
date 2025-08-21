#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string>
#include <cstring>
#include <bitset>
#include <vector>
#include <map>
#define endl "\n"
using namespace std;
typedef long long ll;
const ll INF = 1e9;

int n;
int arr[100001];
int sum[100001];
int answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sum[0] = arr[0];
	for (int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + arr[i];
	
	int maxIndex = -1;
	int maxValue = 0;
	for (int i = 1; i < n - 1; i++) {
		if (maxValue < arr[i]) {
			maxValue = arr[i];
			maxIndex = i;
		}
	}

	answer = sum[maxIndex]-sum[0] + sum[n-2]-sum[maxIndex -1];//꿀통이 가운데

	for (int i = 1; i < n; i++) {
		answer = max(answer, sum[n - 1]*2 - sum[i]-arr[i] - arr[0]);
	}

	for (int i = 1; i < n-1; i++) {
		answer = max(answer, sum[n - 2] + sum[i - 1] - arr[i]);
	}
	
	cout << answer;
	return 0;
}