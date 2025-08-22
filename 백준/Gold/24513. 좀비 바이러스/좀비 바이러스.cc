#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string>
#include <cstring>
#include <bitset>
#include <vector>
#include <map>
#define endl "\n"
using namespace std;
typedef long long ll;
const ll INF = 1e9;

int n, m;
int arr[1001][1001];
queue<tuple<int, int, int>> qu;
int dr[] = { 0,0,1,-1 }, dc[] = { -1,1,0,0 };
bool visited[1001][1001][3];
int turn[1001][1001];

bool checkPos(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0) {
				qu.push({ i,j,arr[i][j] });
				visited[i][j][arr[i][j]] = true;
				turn[i][j] = 1;
			}
		}
	}

	int prev = 0;
		
	int r, c, num;
	while (!qu.empty()) {
		tie(r, c, num) = qu.front(); qu.pop();
		if (arr[r][c] == 3)continue;
		if (prev != num) {
			prev = num;
		}

		for (int k = 0; k < 4; k++) {
			int tr = r + dr[k], tc = c + dc[k];
			if (checkPos(tr, tc) && !visited[tr][tc][num] 
				&& arr[tr][tc] != -1 && arr[tr][tc]!=3 
				&& (arr[tr][tc]==0 || (arr[tr][tc]>0 && turn[tr][tc] == turn[r][c]+1))) {
				qu.push({ tr,tc,num });
				arr[tr][tc] += num;
				visited[tr][tc][num] = true;
				turn[tr][tc] = turn[r][c] + 1;
			}
		}
	}


	int answer[] = { 0,0,0,0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > 0) {
				answer[arr[i][j]]++;
			}
		}
	}

	cout << answer[1] << " " << answer[2] << " " << answer[3];
	return 0;
}