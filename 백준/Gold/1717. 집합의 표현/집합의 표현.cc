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
int arr[1000001];

int find(int a) {
	if (arr[a] == a)
		return a;
	return arr[a] = find(arr[a]);
}

void Union(int a, int b) {
	int x = find(a);
	int y = find(b);
	arr[x] = y;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n,m;
	cin >> n >> m;
	
	
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}

	int cmd, a, b;
	for (int i = 0; i < m; i++) {
		cin >> cmd >> a >> b;
		if (cmd == 0) {
			Union(a, b);
		}
		else {
			if (find(a) == find(b))
				cout << "YES\n" ;
			else
				cout << "NO\n";
		}

	}


	return 0;
}
