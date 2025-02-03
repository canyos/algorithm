#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

int n, m;
queue<pair<int, int>> qu;
int arr[101][101];
int cnt;
int answer;
int dr[4] = { 0,0,1,-1 }, dc[4] = { 1,-1,0,0 };

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			cnt += arr[i][j];
		}
	}
}

bool chkPos(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

int main() {
	cin.tie(NULL); //입출력 묶음 해제
	ios_base::sync_with_stdio(false);
	
	input();

	while (cnt) {
		qu.push({ 0, 0 });
		int visited[101][101] = { 0 };
		unordered_map<int, int> mp;

		while (!qu.empty()) {
			auto v = qu.front(); qu.pop();
			int r = v.first, c = v.second;
			if (visited[r][c])continue;
			visited[r][c] = true;
			
			
			for (int i = 0; i < 4; i++) {
				int tr = r + dr[i], tc = c + dc[i];
				if (chkPos(tr, tc) && arr[tr][tc]) {
					mp[tr*1000+tc]++;
				}
				if (chkPos(tr, tc) && !arr[tr][tc]) {
					if(!visited[tr][tc])
						qu.push({ tr,tc });
				}
			}
		}

		for (auto v : mp) {
			if (v.second >= 2) {
				cnt--;
				arr[v.first / 1000][v.first % 1000] = 0;
			}
		}
		answer++;
	}
	cout << answer;
	return 0;
}