#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;

int tc, n, m;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> tc;
	for (int t = 0;t < tc;t++) {
		cin >> n;
		vector<int> nums;
		vector<int> edges[501]; //edges[a]에 b가 있으면 a가 b보다 순위높음
		int cnts[501] = { 0 };//인엣지 카운트

		nums.resize(n);
		for (int i = 0;i < n;i++) {
			cin >> nums[i];
		}
		
		for (int i = 0;i < n;i++) {
			for (int j = i + 1;j < n;j++) {
				edges[nums[i]].push_back(nums[j]);
				cnts[nums[j]]++;
			}
		}

		cin >> m;
		int a, b;

		bool isCycle = false;
		bool isNotOne = false;

		for (int i = 0;i < m;i++) {
			cin >> a >> b;//이제 a가 b보다 순위 높음

			auto it = find(edges[b].begin(), edges[b].end(), a);
			auto it2 = find(edges[a].begin(), edges[a].end(), b);

			if (it != edges[b].end()) {
				edges[b].erase(it);
				edges[a].push_back(b);

				cnts[a]--;
				cnts[b]++;
			}
			else if (it2 != edges[a].end()) {
				edges[a].erase(it2);
				edges[b].push_back(a);

				cnts[b]--;
				cnts[a]++;
			}
			else {
				isCycle = true;
			}
			
		}

		int cnt = 1;
		vector<int> seq;
		queue<int> qu;
		bool visited[501] = { 0 };
		for (int i = 1;i <= n;i++) {
			if (cnts[i] == 0) {
				qu.push(i);
				visited[i] = true;
			}
		}

		if (isCycle) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		else if (!(qu.size() == 1)) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

		while (!qu.empty()) {
			if (!(qu.size() == 1)) {
				isNotOne = true;
				break;
			}
			int cur = qu.front();qu.pop();
			seq.push_back(cur);
			for (int next : edges[cur]) {
				cnts[next]--;
				if (cnts[next] == 0) {
					if (visited[next]) {
						isCycle = true;
						break;
					}
					qu.push(next);
					visited[next] = true;
					cnt++;
				}
			}
			if (isCycle) {
				break;
			}
		}

		if (isCycle) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		else if (isNotOne || cnt !=n ) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		
		for (int i = 0;i < n;i++) {
			if (i != n - 1)
				cout << seq[i] << " ";
			else
				cout << seq[i];
		}
		if(t != tc-1)
			cout << "\n";
	}
	
	return 0;
}
/*

*/