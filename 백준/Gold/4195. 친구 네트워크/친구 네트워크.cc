#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <deque>
#include <climits>

using namespace std;

int parent[200001];
int num[200001];

int find(int a) {
	if (a == parent[a])
		return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	auto x = find(a);
	auto y = find(b);

	if (x == y)return;
	parent[x] = y;
	num[y] += num[x];
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n ;
	
	for (int t = 0; t < n; t++) {
		int m;
		cin >> m;
		int cnt = 1;
		unordered_map<string, int> mp;
		for (int i = 1; i <= 200000; i++) {
			parent[i] = i;
			num[i] = 1;
		}

		for (int i = 0; i < m; i++) {
			string str1, str2;
			cin >> str1 >> str2;
			if (mp.find(str1) == mp.end()) {
				mp[str1] = cnt++;
			}
			if (mp.find(str2) == mp.end()) {
				mp[str2] = cnt++;
			}

			merge(mp[str1], mp[str2]);
			cout << num[find(mp[str2])] <<'\n';
		}
	}
	
	return 0;
}
