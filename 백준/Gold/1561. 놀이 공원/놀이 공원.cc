#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;
typedef long long ll;


int n, m;
int arr[10001];


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}

	ll left = 0, right = 1e15;
	ll answer = 0;
	while (left <= right) {
		ll mid = left + (right - left) / 2;
		ll sum = 0;
		for (int i = 0; i < m; i++) {
			sum += mid / arr[i] + 1;
		}
		if (sum >= n) {//탈 수 있음
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	answer = left;//n번째애가 놀이기구 탑승 시간

	//cout << left;

	vector<int> v;
	ll sum = 0;
	for (int i = 0; i < m; i++) {
		if (answer%arr[i] == 0) {
			v.push_back(i);
			sum += answer / arr[i];
		}
		else {
			sum += answer / arr[i] + 1;// 7초 2
		}
	}

	cout << v[n - sum- 1]+1;


	//나눠떨어지지않는건  sum += mid / arr[i] + 1;
	//나눠떨어지는건 sum += mid / arr[i]
	//후보지배열에 놀이기구번호넣음
	//출력 후보지배열 v[n-sum-1]+1;


	return 0;
}
/*
5 30
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
*/