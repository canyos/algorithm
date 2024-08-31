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

class edge {
public:
	int start;
	int end;
	int cost;
	edge(int start, int end, int cost) {
		this->start = start;
		this->end = end;
		this->cost = cost;
	}
};
class node {
public:
	int cur;
	int cost;
	int maxCost;
	int visited;
	node(int cur, int cost, int maxCost, int visited) {
		this->cur = cur;
		this->cost = cost;
		this->maxCost = maxCost;
		this->visited = visited;
	}
};

int N, M, A, B, C;
vector <edge> edges[11];//시작,끝,비용
queue <node> qu; //현재 방문 노드, 비용, 수치심, 방문한 노드
int result = 100000000;

void input() {
	cin >> N >> M >> A >> B >> C;
	int start, end, cost;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> cost;
		edges[start].push_back(edge(start,end,cost));
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	qu.push(node(A, 0, 0, 1 << A));

	
	while (!qu.empty()) {
		auto v = qu.front(); qu.pop();//v는 현재 노드
		//cout << v.cur << endl; 
		if (v.cost > C)continue;//비용을 넘었는지
		if (v.cur == B) { //현재 방문한 노드가 목표지점인지
			result = min(result, v.maxCost);
			//cout << result << endl;
			continue;
		}
		
		for (auto it : edges[v.cur]) {//it는 edge
			if (v.visited & (1 << it.end)) continue; //방문한 적 있으면 패스
			qu.push({ it.end, v.cost + it.cost, max(v.maxCost, it.cost), v.visited | (1<< it.end) });
		}
	}
	if (result == 100000000) cout << "-1";
	else cout << result;
	return 0;
}