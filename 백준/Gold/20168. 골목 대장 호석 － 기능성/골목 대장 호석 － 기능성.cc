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
int N, M, A, B, C;
vector<tuple<int,int,int>> edge[11];//시작,끝,비용
queue < tuple<int, int, int,int>> qu; //현재 방문 노드, 비용, 수치심, 방문한 노드
int result = 1e10;

void input() {
	cin >> N >> M >> A >> B >> C;
	int start, end, cost;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> cost;
		edge[start].push_back({ start,end,cost });
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	qu.push({ A,0,0, 1<<A });
	
	while (!qu.empty()) {
		auto v = qu.front(); qu.pop();//v는 현재 노드
		//cout << get<0>(v) << endl; 
		if (get<1>(v) > C)continue;//비용을 넘었는지
		if (get<0>(v) == B) { //현재 방문한 노드가 목표지점인지
			result = min(result, get<2>(v));
			//cout << result << endl;
			continue;
		}
		

		for (auto it : edge[get<0>(v)]) {//it는 edge
			if ((get<3>(v) & (1 << (get<1>(it))))) continue; //방문한 적 없으면
				qu.push({ get<1>(it),get<1>(v) + get<2>(it), max(get<2>(it),get<2>(v)), (get<3>(v)) | (1 << get<1>(it)) });
		}
	}
	if (result == 1e10) cout << "-1";
	else cout << result;
	return 0;
}