#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <deque>

using namespace std;

vector<int> edges[1001];
int arr[1001];
int cnt[1001];
int dist[1001];

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n, m;
		cin >> n >> m;
		fill(dist, dist + 1001, 0);
		fill(cnt, cnt + 1001, 0);
		
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			edges[i] = {};
		}
		int a, b;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			edges[a].push_back(b);
			cnt[b]++;
		}

		queue<int> qu;
		for (int i = 1; i <= n; i++) {
			if (cnt[i] == 0) {
				qu.push(i);
				dist[i] = arr[i];
			}
		}

		int w;
		cin >> w;
		
		while (!qu.empty()) {

			auto cur = qu.front(); qu.pop();

			for (int next : edges[cur]) {
				cnt[next]--;
				dist[next] = max(dist[next], dist[cur] + arr[next]);
				if (cnt[next] == 0) {
					qu.push(next);
				}
			}
		}


		cout << dist[w] << '\n';
	}

	
	return 0;
}
