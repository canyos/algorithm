#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

ll result = 0;
priority_queue < ll,vector<ll>,greater<ll> > pq;
int n, x;
int arr[100001];

void input() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}
bool process(int mid) {
	pq = {};
	for (int i = 1; i <= mid; i++)
		pq.push(arr[i]);
	int idx = mid + 1;
	while (!pq.empty() && idx<=n) {
		int cur = pq.top(); pq.pop();
		int next = cur + arr[idx++];
		//cout << cur << " " << next << endl;
		if (next > x)return false;
		pq.push(next);
	}
	result = mid;
	return true;

}
void binary() {
	int left = 1, right = 100000;
	while (left <= right) {
		int mid = (left + right) / 2;
		//cout << mid << endl;
		if (process(mid)) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	//process(3);
	binary();
	
		
	cout << result;
	return 0;
}