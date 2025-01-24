#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

long long n, k;
queue<pair<int, int>> qu;
int answer = 0;
int visited[100001];

int main() {
	cin.tie(NULL); //입출력 묶음 해제
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	fill(visited, visited + 100001, 1e9);

	qu.push({ n, 0 });
	while (!qu.empty()) {
		auto v = qu.front(); qu.pop();
		int cur = v.first, cost = v.second;

		if (visited[cur] <= cost)continue;
		if (visited[k] <= cost) continue;

		visited[cur] = cost;

		//cout << cur << endl;
		if (cur > 0) {
			qu.push({ cur - 1, cost + 1 });
		}
		if (cur < 100000) {
			qu.push({ cur + 1, cost + 1 });
		}
		if (cur * 2 < 100001) {
			qu.push({ cur * 2,cost });
		}
	}

	cout << visited[k];
	return 0;
}