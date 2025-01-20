#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

long long n, m, answer;
vector<pair<int, int>> edge[1001];
priority_queue<pair<int, int>> pq;
bool visited[1001];

int main() {
	cin >> n >> m;

	long long start, end, cost;
	for (int i = 0; i < m; i++) {
		cin >> start >> end >> cost;
		edge[start].push_back({ end,cost });
		//edge[end].push_back({ start,cost });
	}

	cin >> start >> end;

	pq.push({ 0,start });

	while (!pq.empty()) {
		auto v = pq.top(); pq.pop();
		cost = -v.first; int cur = v.second;

		//cout << cur << " " << cost << endl;
		if (visited[cur])continue;
		visited[cur] = true;

		if (cur == end) {
			answer = cost;
			break;
		}

		for (auto it : edge[cur]) {
			if(!visited[it.first])
				pq.push({ -(cost + it.second), it.first });
		}
	}

	cout << answer;
	return 0;
}