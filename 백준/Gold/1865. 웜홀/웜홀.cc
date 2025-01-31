#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

int tc;
int n, m, w;
int s, e, t;
vector<tuple<int, int, int>> edge;
const int INF = 50000000;
int dist[501];

void input()
{
	cin >> n >> m >> w;

	for (int i = 0; i < m; i++) {
		cin >> s >> e >> t;
		edge.push_back({ s,e,t });
		edge.push_back({ e,s,t });
	}

	for (int i = 0; i < w; i++) {
		cin >> s >> e >> t;
		edge.push_back({ s,e,-t });
	}
}

void bell() {
	edge.clear();
	input();

	fill(dist, dist + 501, INF);
	dist[1] = 0;
	bool answer = false;

	for (int i = 0; i < n; i++) {
		for (auto e : edge) {
			int cur = get<0>(e), next = get<1>(e), cost = get<2>(e);

			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				if (i == n - 1) 
					answer = true;
			}
		}
	}
	
	if (answer)cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	cin.tie(NULL); //입출력 묶음 해제
	ios_base::sync_with_stdio(false);

	cin >> tc;
	for (int i = 0; i < tc; i++)
		bell();
	return 0;
}