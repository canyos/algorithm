#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <deque>
#include <climits>
#include <stack>
#include <bitset>
#include <unordered_set>
typedef long long ll;

using namespace std;

int tc;
int n, m;
char map[101][101];
string keyString;
int answer;
bool visited[101][101];
bool key[26];
queue<pair<int, int>> qu;
vector<pair<int, int>> door[26];

void reset() {
	for (int i = 0; i < 101; i++) {
		fill(visited[i], visited[i] + 101, false);
	}
}

bool checkCondition(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= m)
		return false;
	char ch = map[r][c];
	if (ch == '*')
		return false;
	return (ch == '.' || (ch >= 'a' && ch <= 'z')  || ch=='$') && !visited[r][c];
}
int dr[4] = { 0,0,1,-1 }, dc[4] = { -1,1,0,0 };

int bfs(int r, int c) {
	int keyCnt = 0;

	qu.push({ r,c });
	visited[r][c] = true;
	while (!qu.empty()) {
		auto cur = qu.front(); qu.pop();
		char curCh = map[cur.first][cur.second];
		//cout << cur.first << " " << cur.second << " " << map[cur.first][cur.second] << endl;
		if (curCh >= 'a' && curCh <= 'z') {
			key[curCh - 'a'] = true;
			keyCnt++;
			map[cur.first][cur.second] = '.';
			for (auto d : door[curCh - 'a']) {
				map[d.first][d.second] = '.';
			}
		}
		if (curCh == '$') {
			answer++;
			map[cur.first][cur.second] = '.';
			//cout << cur.first << " " << cur.second << endl;
		}
		for (int k = 0; k < 4; k++) {
			int tr = cur.first + dr[k], tc = cur.second + dc[k];
			if (checkCondition(tr, tc)) {
				qu.push({ tr,tc });
				visited[tr][tc] = true;
			}
		}
	}
	return keyCnt;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> n >> m;
		answer = 0;
		
		fill(key, key + 26, false);
		for (int i = 0; i < 26; i++)
			door[i] = {};

		string str;
		for (int i = 0; i < n; i++) {
			cin >> str;
			for (int j = 0; j < m; j++) {
				map[i][j] = str[j];
				if (map[i][j] >= 'A' && map[i][j] <= 'Z') {
					door[map[i][j] - 'A'].push_back({ i,j });
				}
			}
		}
			
				

		cin >> keyString;
		if (keyString != "0") {
			for (char ch : keyString) {
				key[ch - 'a'] = true;
				for (auto d : door[ch - 'a']) {
					map[d.first][d.second] = '.';
				}
			}
		}

		int keyCnt = 0;
		do {
			reset();

			keyCnt = 0;
			for (int i = 0; i < n; i++) {
				if (checkCondition(i,0)) {
					keyCnt += bfs(i, 0);
				}
				if (checkCondition(i, m - 1)) {
					keyCnt += bfs(i, m - 1);
				}
			}
			for (int i = 0; i < m ; i++) {
				if (checkCondition(0, i)) {
					keyCnt += bfs(0, i);
				}
				if (checkCondition(n-1,i)) {
					keyCnt += bfs(n-1,i);
				}
			}
		} while (keyCnt);
		
		cout << answer << endl;
	}

	return 0;
}
