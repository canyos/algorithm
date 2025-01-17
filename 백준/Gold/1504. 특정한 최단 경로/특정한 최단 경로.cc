#include <iostream>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

const int INF =  1e9;

int n; long long answer;
int e, u, v;
vector<pair<int, int>> edge[801];
long long dist1[801], dist2[801];
bool visited[801];
priority_queue<pair<int, int>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> e;
	int start, end, cost;

	for (int i = 0; i < e; i++) {
		cin >> start >> end >> cost;
		edge[start].push_back({ end,cost });
		edge[end].push_back({ start,cost });
	}

	cin >> u >> v;

	fill(dist1, dist1 + 801, INF);
	fill(dist2, dist2 + 801, INF);

	pq.push({ 0, u });
	
	while (!pq.empty()) {
		auto aa = pq.top(); pq.pop();
		int cost = -aa.first, cur = aa.second;
		if (visited[cur])continue;

		visited[cur] = true;
		dist1[cur] = cost;
		for (auto ed : edge[cur]) {
			if(!visited[ed.first])
				pq.push({ -(cost + ed.second), ed.first });
		}
	}

	fill(visited, visited + 801, false);

	pq = {};
	pq.push({ 0,v });
	
	while (!pq.empty()) {
		auto aa = pq.top(); pq.pop();
		int cost = -aa.first, cur = aa.second;
		if (visited[cur])continue;
		visited[cur] = true;
		dist2[cur] = cost;
		for (auto ed : edge[cur]) {
			if (!visited[ed.first])
				pq.push({ -(cost + ed.second), ed.first });
		}
	}

	answer = min(dist1[1] + dist2[u] + dist2[n], dist2[1] + dist2[u] + dist1[n]);
	if (answer >= INF) answer = -1;
	cout << answer;
}