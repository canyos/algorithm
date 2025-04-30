#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;
typedef long long ll;

int N, Q, L;
int arr[64][64];
int temp[64][64];

int dr[4] = { 0,0,-1,1 }, dc[4] = { -1,1,0,0 };

bool checkPos(int r, int c, int n) {
	return r >= 0 && r < n && c >= 0 && c < n;
}

void rotateBox(int r, int c, int L) {
	if (L == 0)return;
	int len = (1 << L);

	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			temp[r + j][c + len - 1 - i] = arr[r + i][c + j];
		}
	}
	

	for (int i = r; i < r + len; i++) {
		for (int j = c; j < c + len; j++)
			arr[i][j] = temp[i][j];
	}
}

void check0(int n) {
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			if (arr[i][j] != 0) {
				if (i - 1 >= 0 && arr[i - 1][j])cnt++;
				if (i + 1 < n && arr[i + 1][j])cnt++;
				if (j - 1 >= 0 && arr[i][j - 1])cnt++;
				if (j + 1 < n && arr[i][j + 1])cnt++;
			}
			if (cnt < 3)v.push_back({ i,j });
		}
	}
	for (auto p : v) {
		arr[p.first][p.second] = max(arr[p.first][p.second]-1, 0);
	}
}

int sumIce(int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}

int maxIce(int n) {
	bool visited[64][64] = { 0 };
	queue<pair<int, int>> qu;
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cnt = 0;

			if (!visited[i][j] && arr[i][j]) {
				qu.push({ i,j });
				visited[i][j] = true;
				cnt++;

				while (!qu.empty()) {
					auto cur = qu.front(); qu.pop();
					int r = cur.first, c = cur.second;
					for (int k = 0; k < 4; k++) {
						int tr = r + dr[k], tc = c + dc[k];
						if (checkPos(tr,tc,n) && !visited[tr][tc] && arr[tr][tc]) {
							qu.push({ tr,tc });
							visited[tr][tc] = true;
							cnt++;
						}
					}
				}
			}
			res = max(res, cnt);
		}
	}
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> Q;
	int n = (1 << N);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int q = 0; q < Q; q++) {
		cin >> L;
		int l = (1 << L);
		for (int i = 0; i < n; i += l) {
			for (int j = 0; j < n; j += l) {
				rotateBox(i, j, L);
			}
		}
		check0(n);
	}

	cout << sumIce(n) << "\n";
	cout << maxIce(n);

}
