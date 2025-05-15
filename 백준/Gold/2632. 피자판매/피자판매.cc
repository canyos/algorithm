#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int goal;
int n, m;
int answer;
int cntA[1000001], cntB[1000001];
int arr[2001], arr2[2001];
int sum[2001], sum2[2001];

int main() { 
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> goal;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		arr[i + n] = arr[i];
	for (int j = 0; j < m; j++)
		cin >> arr2[j];
	for (int i = 0; i < m; i++)
		arr2[i + m] = arr2[i];
	
	for (int i = 1; i <= n*2; i++)
		sum[i] = sum[i - 1] + arr[i-1];

	for(int i = 1; i <= m*2; i++)
		sum2[i] = sum2[i - 1] + arr2[i-1];

	
	for (int i = 0; i < n; i++) {
		for (int len = 1; len < n; len++) {
			cntA[sum[i + len] - sum[i]]++;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int len = 1; len < m; len++) {
			cntB[sum2[i + len] - sum2[i]]++;
		}
	}

	cntA[sum[n]]++, cntB[sum2[m]]++;
	cntA[0] = 1, cntB[0] = 1;

	for (int i = 0; i <= goal; i++) {
		answer += cntA[i] * cntB[goal - i];
	}
	
	cout << answer;

	return 0;
}
//11, 13 , 15