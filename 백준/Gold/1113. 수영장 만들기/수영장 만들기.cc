#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int n, m;
int answer;
int arr[51][51];
bool visited[51][51];
bool boundary[51][51];
queue<pair<int, int>> qu;
int dr[] = { 0,0,-1,1 }, dc[] = { -1,1,0,0 };

bool checkPos(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

void bCheck(int r, int c) {
	if (!checkPos(r, c))return;
	if (boundary[r][c])return;
	boundary[r][c] = true;
	for (int k = 0; k < 4; k++) {
		int tr = r + dr[k], tc = c + dc[k];
		if (arr[r][c] <= arr[tr][tc] && !boundary[tr][tc])
			bCheck(tr, tc);
	}
}

bool dfs(int r, int c) {
	if (boundary[r][c])return false;
	bool res = true;
	for (int k = 0; k < 4; k++) {
		int tr = r + dr[k], tc = c + dc[k];
		if (!visited[tr][tc] && arr[tr][tc] == arr[r][c]) {
			visited[tr][tc] = true;
			res &= dfs(tr, tc);
		}
	}
	if(res) qu.push({ r,c });
	return res;
}

int main() { 
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++)
			arr[i][j] = str[j] - '0';
	}




	for (int k = 1; k <= 8; k++) {
		fill(&boundary[0][0], &boundary[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		for (int i = 0; i < n; i++) {
			if (!visited[i][0])
				bCheck(i, 0);
			if (!visited[i][m - 1])
				bCheck(i, m - 1);
		}

		for (int j = 0; j < m; j++) {
			if (!visited[0][j])
				bCheck(0, j);
			if (!visited[n - 1][j])
				bCheck(n - 1, j);
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (boundary[i][j])continue;
				if (arr[i][j] != k)continue;

				if (!visited[i][j]) {
					visited[i][j] = true;
					bool res = dfs(i, j);
					if (res == false) qu = {};
					else {
						while (!qu.empty()) {
							auto cur = qu.front();	qu.pop();
							answer++;
							arr[cur.first][cur.second]++;
						}
					}
				}
			}
		}
		//cout << k << " " << answer << endl;
	}
	
	
	cout << answer;

	return 0;
}
//11, 13 , 15