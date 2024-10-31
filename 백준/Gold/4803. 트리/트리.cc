#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <cmath>
using namespace std;

typedef long long ll;
int n, m;
int turn = 1;
int start, to;
vector<int>arr(501);

vector<vector<int>> con(501);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)break;

		int visited[501] = { 0 };
		int cnt = 0;
		queue<int> qu = {};
		arr = {};
		for (auto& it : con)
			it = {};

		for (int i = 0; i < m; i++) {
			cin >> start >> to;
			con[start].push_back(to);
			con[to].push_back(start);
		}

		for (int i = 1; i <= n; i++) {
			bool isCycle=false;
			if (!visited[i]) {
				qu.push(i);
				visited[i] = true;
				cnt++;
			}
			
			while (!qu.empty()) {
				auto v = qu.front();
				qu.pop();
				for(auto it : con[v]){
					if (!visited[it]) {
						vector<int>::iterator iter = find(con[it].begin(), con[it].end(), v);
						con[it].erase(iter);
						qu.push(it);
						visited[it] = true;
					}
					else {
						isCycle = true;
					}
				}
			}
			if (isCycle)
				cnt--;
		}



		if (cnt == 1) {
			cout << "Case " << turn << ": There is one tree.\n";
		}
		else if (cnt == 0) {
			cout << "Case " << turn << ": No trees.\n";
		}
		else {
			cout << "Case " << turn << ": A forest of " << cnt << " trees.\n";
		}
		turn++;
	}
		
	return 0;
}