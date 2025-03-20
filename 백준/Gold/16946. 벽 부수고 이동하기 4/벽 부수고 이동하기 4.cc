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

int n, m;
int arr[1001][1001];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { -1,1,0,0, };
int cnt = 1;
int parentCnt[500001];
int result[1001][1001];
int parent[1001][1001];

queue<pair<int, int>> qu;

bool checkPos(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);



	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++)
			arr[i][j] = str[j] - '0';
	}
	bool visited[1001][1001] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && !visited[i][j]) {
				qu.push({ i, j });
				int tempSum = 1;//0의 개수
				parent[i][j] = cnt;
				visited[i][j] = true;
				while (!qu.empty()) {
					auto cur = qu.front(); qu.pop();
					
					for (int kk = 0; kk < 4; kk++) {
						int tr = cur.first + dr[kk], tc = cur.second + dc[kk];
						if (checkPos(tr, tc) && !arr[tr][tc] && !visited[tr][tc]) {
							//좌표는 유효한지      빈공간인지   이미 탐색하지않았는지
							qu.push({ tr,tc });
							parent[tr][tc] = cnt;
							tempSum++;
							visited[tr][tc] = true;
						}
					}

				}
				parentCnt[cnt] = tempSum;
				cnt++;
			}
		}
	}


	unordered_set<int> st;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {//벽임
				int sum = 1;//지금 칸 포함
				st = {};
				for (int k = 0; k < 4; k++) {//벽의 상하좌우
					int nr = i + dr[k], nc = j + dc[k];
					if (!checkPos(nr, nc))continue;//유효하지 않은 좌표
					if (arr[nr][nc] == 1) continue;//옆칸이 벽임
					if (parent[nr][nc]) {//이미 탐색한 공간임
						if (st.find(parent[nr][nc]) != st.end())continue;//이미 더한 빈공간 더미임
						sum = sum + parentCnt[parent[nr][nc]];
						st.insert(parent[nr][nc]);
					}
				}
				result[i][j] = sum%10;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << result[i][j];
		}
		cout << '\n';
	}

	return 0;
}
