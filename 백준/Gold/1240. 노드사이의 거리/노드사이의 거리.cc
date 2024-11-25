#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <string>
#include <set>
#include <map>

using namespace std;

vector<vector<pair<int, int>>> tree(1001);
queue<pair<int, int>> qu;
int visited[1001];
int n, m;
int start, to, dist;
int answer;

int main()
{

	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		cin >> start >> to >> dist;

		tree[start].push_back({ to, dist });
		tree[to].push_back({ start, dist });
	}

	for (int i = 0; i < m; i++) {

		cin >> start >> to;

		qu = {};
		
		for (int i = 1; i <= n; i++) {
			visited[i] = false;
		}

		qu.push({ start,0 });

		while (!qu.empty()) {
			pair<int, int> cur = qu.front(); qu.pop();
			visited[cur.first] = true;

			if (cur.first == to) {
				cout << cur.second << '\n';
				break;
			}

			for (auto it : tree[cur.first]) {		
				if (!visited[it.first]) {
					int next = it.first, dist = it.second + cur.second;
					visited[next] = true;
					qu.push({ next,dist });
				}
			}
		}
	}


	return 0;
}