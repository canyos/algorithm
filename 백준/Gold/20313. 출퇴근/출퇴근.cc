#include <iostream>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m, a, b, k;
int edgeIndex[1001][1001];
vector<int> edge[1001];// 이어진 노드들 담음
int T[101][2001]; //k, index 에 따른 코스트
bool visited[1001][101]; // 노드,k 에 따른 방문 결과
priority_queue<tuple<long long, long long, long long>> qu;
long long answer = 1e13;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> a >> b;
	int temp,start,end;

	for (int i = 1; i <= m; ++i) {
		cin >> start >> end >> temp;
		edge[start].push_back(end);
		edge[end].push_back(start);

		edgeIndex[start][end] = edgeIndex[end][start] = i;
		T[0][i] = temp;
	}

	cin >> k;
	for (int j = 1; j <= k; ++j) {
		for (int i = 1; i <= m; i++) {
			cin >> T[j][i];
		}
	}
	
	qu.push({ 0,a,0 });

	while (!qu.empty()) {
		auto cur = qu.top(); qu.pop();
		long long cost = -get<0>(cur), node = get<1>(cur), magic = get<2>(cur);
		//auto [cost, node, magic] = cur;

		if (visited[node][magic])
			continue;
		visited[node][magic] = true;
		
		if (node == b) {
			answer = min(answer, cost);
			continue;
		}
	
		for (int next : edge[node]) {
			int index = edgeIndex[node][next];
			qu.push({ -(cost + T[magic][index]), next,magic });
		}
		if(magic<k)
			qu.push({ -cost,node, magic + 1 });
	}

	cout << answer;
}