#include <iostream>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m, x;
vector<pair<int,int>> con1[1001], con2[1001];
int dist1[1001], dist2[1001], dist3[1001];
priority_queue<pair<int,int>> pq;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> x;

	for (int i = 1; i <= n; i++)
		if(i!=x) dist1[i] = dist2[i] = 1e10;
	
	int start, end, cost;
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> cost;
		con1[start].push_back({ end,cost });
		con2[end].push_back({ start,cost });
	}
	
	pq.push({ 0,x });
	while (!pq.empty()) {
		int cur = pq.top().second, cost = -(pq.top().first); pq.pop();
		if (cost > dist1[cur])continue;

		for (auto v : con1[cur]) {
			int next = v.first, nextCost = v.second;
			dist1[next] = min(dist1[next], cost + nextCost);
			pq.push({ -(cost + nextCost), next  });
		}
	}

	pq.push({ 0,x });
	while (!pq.empty()) {
		int cur = pq.top().second, cost = -(pq.top().first); pq.pop();
		if (cost > dist2[cur])continue;

		for (auto v : con2[cur]) {
			int next = v.first, nextCost = v.second;
			dist2[next] = min(dist2[next], cost + nextCost);
			pq.push({ -(cost + nextCost), next });
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		dist3[i] = dist1[i] + dist2[i];
		answer = max(answer, dist3[i]);
	}
		
	cout << answer;
}