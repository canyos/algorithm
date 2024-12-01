#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;
typedef long long ll;

int n, r, q;
int arr[100001];
bool visited[100001];
vector<vector<int>> conn(100001);

void subTree(int cur) {
	visited[cur] = true;
	int sum = 0;
	for (auto it : conn[cur]) {
		if (!visited[it]) {
			subTree(it);
			sum += arr[it];
		}
	}
	arr[cur] = sum+1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> r >> q;

	int start, to;
	for (int i = 1; i < n; i++) {
		cin >> start >> to;
		conn[start].push_back(to);
		conn[to].push_back(start);
	}
	
	subTree(r);
	
	for (int i = 0; i < q; i++) {
		cin >> start;
		cout << arr[start] << '\n';
	}

	return 0;
}