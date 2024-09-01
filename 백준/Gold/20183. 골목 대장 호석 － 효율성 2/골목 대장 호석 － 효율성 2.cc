#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
#define INF 1000000001
class edge {
public:
	int end;
	ll cost;
	edge(int end, ll cost) {
		this->end = end;
		this->cost = cost;
	}
};

int N, M, A, B; ll C;
vector <edge> edges[100001];//시작,끝,비용
ll result = INF;

void input() {
	cin >> N >> M >> A >> B >> C;
	int start, end; ll cost;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> cost;
		edges[start].push_back(edge(end, cost));
		edges[end].push_back(edge(start, cost));
	}
}

bool dijkstra(ll mid) {
	vector<ll> dist(N + 1, INF);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

	dist[A] = 0; //초기값 설정
	pq.push({ 0,A });

	while (!pq.empty()) {
		int curr = pq.top().second;
		ll curr_dist = pq.top().first;
		pq.pop();

		if (curr == B) return true;
		if (curr_dist > dist[curr])continue;

		for (const edge e : edges[curr]) {
			if (e.cost > mid) continue;
			ll next_dist = curr_dist + e.cost;
			if (next_dist < dist[e.end] && next_dist <= C) {
				dist[e.end] = next_dist;
				pq.push({ next_dist, e.end });
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	ll left = 1, right = 1000000000;
	while (left <= right) {

		ll mid = (left + right) / 2;
		//cout << left << " "  << mid << " " << right << endl;
		if (dijkstra(mid)) {
			right = mid - 1;
			result = min(result, mid);
		}
		else
			left = mid + 1;
	}
	if (result == 1000000001) cout << "-1";
	else cout << result;

	return 0;
}