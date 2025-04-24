#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;
typedef long long ll;
int n, m;
vector<int> edges[101];
vector<int> redges[101];

queue<int> qu;
int bfs(int n) {
	int cnt = 0;
	qu.push(n);

	bool visited[101] = { 0 };
	visited[n] = true;
	while (!qu.empty()) {
		int cur = qu.front(); qu.pop();
		for (int next : edges[cur]) {
			if (!visited[next]) {
				qu.push(next);
				visited[next] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int rbfs(int n) {
	int cnt = 0;
	qu.push(n);

	bool visited[101] = { 0 };
	visited[n] = true;
	while (!qu.empty()) {
		int cur = qu.front(); qu.pop();
		for (int next : redges[cur]) {
			if (!visited[next]) {
				qu.push(next);
				visited[next] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edges[a].push_back(b);
		redges[b].push_back(a);
	}

	int answer = 0;

	int limit = (n + 1) / 2;
	for (int i = 1; i <= n; i++) {
		if (bfs(i) >= limit || rbfs(i) >= limit)answer++;
	}

	cout << answer;
}