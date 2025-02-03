#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

int n, m;
int answer;
int start, dest, cost;
vector<pair<int, int>> edge[1001];
int dist[1001];
priority_queue<tuple<int, int, int, string>> pq;//비용, 노드, 도시 개수
const int INF = 100000 * 1000 + 1;

int answerCost, answerCnt;
string answerStr;

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> start >> dest >> cost;
		edge[start].push_back({ dest,cost });
	}

	cin >> start >> dest;
}

int main() {
	cin.tie(NULL); //입출력 묶음 해제
	ios_base::sync_with_stdio(false);
	
	input();
	fill(dist, dist + 1001, INF);
	pq.push({ 0, 1, start, "" + to_string(start) });
	while (!pq.empty()) {
		auto v = pq.top(); pq.pop();
		int curCost = -get<0>(v), cnt = get<1>(v), curNode = get<2>(v);
		string str = get<3>(v);
		if (dist[curNode] <= curCost) continue;

		dist[curNode] = curCost;
		if (curNode == dest) {
			answerCost = curCost;
			answerCnt = cnt;
			answerStr = str;
		}

		for (auto next : edge[curNode]) {
			int nextNode = next.first, nextCost = next.second;
			pq.push({ -(curCost + nextCost) , cnt + 1, nextNode, str + " " + to_string(nextNode) });
		}
	}
	
	cout << answerCost << "\n" << answerCnt << "\n" << answerStr;
	return 0;
}