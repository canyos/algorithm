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

int parent[201];

int find(int a) {
	if (a == parent[a])
		return a;
	return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	parent[x] = y;
}
int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	int num;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num;
			if (num == 1) {
				merge(i, j);
			}
		}
	}

	int arr[1001] = { 0 };
	for (int i = 0; i < m; i++){
		cin >> arr[i];
	}

	bool isPossible = true;
	for (int i = 0; i < m - 1; i++) {
		if (find(arr[i]) != find(arr[i + 1])) {
			isPossible = false;
			break;
		}
	}
	if(!isPossible)
		cout << "NO";
	else
		cout << "YES";
	return 0;
}
