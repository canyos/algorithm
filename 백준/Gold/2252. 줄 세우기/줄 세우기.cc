#include <iostream>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m;
vector<int> conn[32001];
int inCnt[32001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int start, end;
	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		conn[start].push_back(end);
		inCnt[end]++;
	}

	queue<int> qu;
	for (int i = 1; i <= n; i++) {
		if (inCnt[i] == 0) {
			qu.push(i);
		}
	}

	while (!qu.empty()) {
		int cur = qu.front(); qu.pop();
		cout << cur << " ";

		for (auto it : conn[cur]) {
			inCnt[it]--;
			if (inCnt[it] == 0) {
				qu.push(it);
			}
		}
	}
}