#include <iostream>

using namespace std;

int n, m;
int arr[100001];
const int INF = 1e9 + 1;
pair<int, int> tree[300001]; // {값, 인덱스}
pair<int, int> init(int pos, int left, int right) {
	if (left == right) {
		tree[pos] = { arr[left],left };
		return tree[pos];
	}
	int mid = (left + right) / 2;
	auto l = init(pos * 2, left, mid);
	auto r = init(pos * 2 + 1, mid + 1, right);
	if (l.first <= r.first) {
		tree[pos] = l;
	}
	else {
		tree[pos] = r;
	}
	return tree[pos];
}
pair<int, int> update(int pos, int left, int right, int idx, int value) {
	if (idx<left || idx>right)return tree[pos];
	if (left == right) {
		tree[pos] = { value, idx };
		return tree[pos];
	}
	int mid = (left + right) / 2;
	auto l = update(pos * 2, left, mid, idx, value);
	auto r = update(pos * 2 +1 , mid + 1,right, idx, value);
	
	if (l.first <= r.first) {
		tree[pos] = l;
		return l;
	}
	else {
		tree[pos]=r;
		return r;
	}
}
pair<int,int> query(int pos, int left, int right, int s, int e) {
	if (e<left || s>right)return { INF,-1 };
	if (left == right) {
		return tree[pos];
	}
	if (s <= left && right <= e) { return tree[pos]; }
	int mid = (left + right) / 2;
	auto l = query(pos * 2, left, mid, s, e);
	auto r = query(pos * 2 + 1, mid + 1, right, s, e);

	if (l.first <= r.first) {
		return l;
	}
	else {
		return r;
	}
	
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	init(1, 0, n - 1);

	cin >> m;
	int cmd, a, b;
	for (int i = 0; i < m; i++) {
		cin >> cmd >> a >> b;
		if (cmd == 1) {
			update(1, 0, n - 1, a-1, b);
		}
		else {
			cout << query(1, 0, n - 1, a-1, b-1).second+1 << "\n";
		}
	}

}