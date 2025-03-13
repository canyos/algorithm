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

using namespace std;

int n, m;
char arr[1001][1001];
bool visited[1001][1001];

bool checkPos(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m && !visited[r][c];
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j];
		}
	}
	
	queue<pair<int, int>> qu;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				qu.push({ i,j });
				visited[i][j] = true;
				answer++;
				while (!qu.empty()) {
					auto cur = qu.front(); qu.pop();
					int r = cur.first, c = cur.second;
					if (arr[r][c] == 'U') {
						if (checkPos(r - 1, c)) {
							qu.push({ r - 1,c });
							visited[r - 1][c] = true;
						}
					}
					if (arr[r][c] == 'D') {
						if (checkPos(r + 1, c)) {
							qu.push({ r + 1,c });
							visited[r + 1][c] = true;
						}
					}
					if (arr[r][c] == 'L') {
						if (checkPos(r, c-1)) {
							qu.push({ r, c - 1 });
							visited[r][c-1] = true;
						}
					}
					if (arr[r][c] == 'R') {
						if (checkPos(r, c + 1)) {
							qu.push({ r, c + 1 });
							visited[r][c + 1] = true;
						}
					}
					if (checkPos(r + 1, c) && arr[r + 1][c] == 'U') {
						qu.push({ r + 1,c });
						visited[r + 1][c] = true;
					}
					if (checkPos(r - 1, c) && arr[r - 1][c] == 'D') {
						qu.push({ r - 1,c });
						visited[r - 1][c] = true;
					}
					if (checkPos(r, c + 1) && arr[r][c + 1] == 'L') {
						qu.push({ r, c + 1 });
						visited[r][c + 1] = true;
					}
					if (checkPos(r, c - 1) && arr[r][c - 1] == 'R') {
						qu.push({ r, c - 1 });
						visited[r][c - 1] = true;
					}
				}
			}
		}
	}

	cout << answer;

	return 0;
}
