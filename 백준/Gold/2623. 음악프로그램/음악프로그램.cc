#include<iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <set>
typedef long long ll;
using namespace std;

int n, m;
int inEdge[1001];//i번째로 향하는 엣지 개수
vector<int> outEdge[1001];//i번째노드에서 향하는 엣지 개수
bool con[1001][1001]; 
bool isCycle;
int main() {
	cin.tie(0); 
	cout.tie(0); 
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		vector<int> v(num);
		for (int j = 0; j < num; j++) {
			cin >> v[j];
			if (j > 0) {
				if (!con[v[j - 1]][v[j]]) {
					outEdge[v[j - 1]].push_back(v[j]);
					inEdge[v[j]]++;
					con[v[j - 1]][v[j]] = true;
				}
			}
		}
	}
	
	queue<int> qu;
	for (int i = 1; i <= n; i++) {
		if (inEdge[i] == 0)
			qu.push(i);
	}
	if (qu.size() == 0)isCycle = true;

	int cnt = 0;
	vector<int> answer;
	while (!qu.empty()) {
		int cur = qu.front(); qu.pop();
		answer.push_back(cur);
		cnt++;
		for (int next : outEdge[cur]) {
			inEdge[next]--;
			if (inEdge[next] == 0) {
				qu.push(next);
			}
		}
	}
	
	if (cnt != n)isCycle = true;
	
	if (isCycle)
		cout << "0";
	else {
		for (auto a : answer) {
			cout << a << "\n";
		}
	}

}