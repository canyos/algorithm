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

int parent[100001];
bool isSelected[100001];

int find(int a) {
	if (a == parent[a])
		return a;
	return parent[a] = find(parent[a]);
}
int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int g, p;
	int cnt = 0;
	cin >> g >> p;
	for (int i = 1; i <= 100000; i++) {
		parent[i] = i;
	}

	int arr[100001] = { 0 };
	for (int i = 0; i < p; i++) {
		cin >> arr[i];	
	}

	for (int i = 0; i < p; i++) {
		int x = find(arr[i]);
		while (isSelected[x] == true) {
			x = find(x);
		}
		if (x > 0) {
			isSelected[x] = true;
			parent[x] = x - 1;
			parent[arr[i]] = x - 1;
			cnt++;
		}
		else {
			break;
		}

	}
	
	cout << cnt;
	
	return 0;
}
