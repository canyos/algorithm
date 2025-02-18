#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> in[501];
vector<int> out[501];
int n, m;

int recursive(int start, bool flag) {
	auto edge = flag?in : out;

	queue<int> qu;
	bool visited[501] = { 0 };
	qu.push(start);
	while (!qu.empty()) {
		int cur = qu.front(); qu.pop();
		if (visited[cur])continue;
		visited[cur] = true;
		for (int next : edge[cur]) {
			if(!visited[next])
				qu.push(next);
		}
	}

	int temp = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i])temp++;
	}
	return temp - 1;
}

int main()
{

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		in[a].push_back(b);
		out[b].push_back(a);
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		int inCnt = recursive(i, false);
		int outCnt = recursive(i, true);

		if (inCnt + outCnt + 1 == n) {
			answer++;
		}
	}

	cout << answer;
}
