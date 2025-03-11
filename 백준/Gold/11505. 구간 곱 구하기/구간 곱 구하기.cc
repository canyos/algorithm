#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <deque>

using namespace std;
const int MOD = 1'000'000'007;
int tree[4000001];
int arr[1000001];
int init(int pos, int left, int right) {
	if (left == right) {
		return tree[pos] = arr[left-1];
	}
	int mid = (left + right) / 2;
	return tree[pos] = 1ll*init(pos * 2, left, mid) * init(pos * 2 + 1, mid + 1, right) % MOD;
}
int update(int pos, int left, int right, int idx, int num) {
	if (idx<left || idx>right)
		return tree[pos];
	if (left == right) 
		return tree[pos] = num;
	
	int mid = (left + right) / 2;
	return tree[pos] = 1ll * update(pos * 2, left, mid, idx, num) * update(pos*2+1,mid+1,right,idx,num) % MOD;
}

int calc(int pos, int left, int right, int start, int end) {
	if (left > end || right < start)
		return 1;
	if (left == right)
		return tree[pos];
	if (start <= left && right <= end) {
		return tree[pos];
	}
	int mid = (left + right) / 2;
	return 1ll * calc(pos * 2, left, mid, start, end) * calc(pos * 2 + 1, mid + 1, right, start, end) % MOD;
}
int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n,m,k;
	cin >> n>>m>>k;


	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	init(1, 1, n);

	int cmd, idx, num;
	for (int i = 0; i < m+k; i++) {
		cin >> cmd >> idx >> num;
		if (cmd == 1) {
			update(1, 1,n, idx, num);
		}
		else {
			cout << calc(1,1,n,idx, num) << '\n';
		}
	}



	return 0;
}
