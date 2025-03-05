#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <deque>

using namespace std;

int n, m, x;
int u, v;
vector<int> inEdges[100001];
vector<int> outEdges[100001];
bool visited[100001];
int gt = -1, lt = -1;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> x;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		inEdges[b].push_back(a);//a가 b보다 잘함
		outEdges[a].push_back(b);//b가 a보다 못함
	}

	queue<int> qu;
	qu.push(x); 
	visited[x] = true;
	while (!qu.empty()) {
		auto cur = qu.front(); qu.pop();
		gt++;
		for (auto it : inEdges[cur]) {
			if (!visited[it]) {
				qu.push(it);
				visited[it] = true;
			}
		}
	}
	fill(visited, visited + 100001, false);
	qu.push(x);
	visited[x] = true;
	while (!qu.empty()) {
		auto cur = qu.front(); qu.pop();
		lt++;
		for (auto it : outEdges[cur]) {
			if (!visited[it]) {
				qu.push(it);
				visited[it] = true;
			}
		}
	}

	int answer1 = gt+1;//나보다 확실히 잘하는놈 몇명임?
	int answer2 = gt+ 1 + (n-gt-lt-1);//나보다 확실히 잘하는놈 더하고 모르는놈 더하기

	cout << answer1 << " " << answer2;
	return 0;
}
