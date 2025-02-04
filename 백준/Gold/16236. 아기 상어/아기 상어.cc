#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
#include <stack>
#include <unordered_set>
using namespace std;

int n;
int arr[21][21];
int r, c;
int level = 2, cnt;
vector<pair<int, int>> fish[10];
unordered_set<int> eatable;

int dr[4] = { -1,0,0,1 }, dc[4] = { 0,-1,1,0 };
int answer;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				r = i, c = j;
				arr[i][j] = 0;
			}
			else if (arr[i][j]) {
				fish[arr[i][j]].push_back({ i,j });
				if (arr[i][j] == 1)
					eatable.insert(i*100+j);
			}
		}
	}
}

bool chkPos(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < n;
}

int main() {
	cin.tie(NULL); //입출력 묶음 해제
	ios_base::sync_with_stdio(false);
	
	input();

	while (eatable.size()) {
		queue<tuple<int, int, int>> qu = {};
		bool visited[21][21] = { 0 };
		priority_queue<tuple<int, int, int>> pq = {};

		qu.push({ r,c,0 });
		while (!qu.empty()) {
			auto v = qu.front(); qu.pop();
			int nr = get<0>(v), nc = get<1>(v), ncost = get<2>(v);
			if (visited[nr][nc])continue;
			visited[nr][nc] = true;

			if (eatable.count(nr * 100 + nc)) {
				pq.push({ -ncost, -nr, -nc });
			}
			for (int i = 0; i < 4; i++) {
				int tr = nr + dr[i], tc = nc + dc[i], tcost = ncost + 1;
				if(chkPos(tr,tc) && !visited[tr][tc] && arr[tr][tc]<=level)
					qu.push({ tr,tc,tcost });
			}
		}
		if (pq.empty())break;
		auto v = pq.top();
		answer -= get<0>(v), r = -get<1>(v), c = -get<2>(v), cnt++;
		arr[r][c] = 0;
		eatable.erase(r*100+c);
		if (cnt == level) {
			level = min(level+1, 8);
			for (auto v : fish[level-1]) {
				eatable.insert(v.first * 100 + v.second);
			}
			cnt = 0;
		}
	}

	cout << answer;
	return 0;
}