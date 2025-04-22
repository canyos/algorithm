#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

typedef long long ll;
using namespace std;

int arr[3][3];
int INF = 9999999;
int dr[] = { 0,0,-1,1 }, dc[] = { -1,1,0,0 };
int r, c;
unordered_map<ll, bool> visited;
int answer=-1;

ll make() {
	ll temp = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp = temp * 10 + arr[i][j];
		}
	}
	return temp;
}

void swap(int r, int c, int tr, int tc) {
	int temp = arr[r][c];
	arr[r][c] = arr[tr][tc];
	arr[tr][tc] = temp;
}

bool checkPos(int r, int c) {
	return r >= 0 && r < 3 && c >= 0 && c < 3;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0)r = i, c = j;
		}
	}
	
	ll start = make();
	if (start == 123456780L) {
		cout << 0;
		return 0;
	}
	visited[start] = true;

	queue<tuple<ll, int, int, int>> qu;
	qu.push({ start, 0, r, c });
	while (!qu.empty()) {
		auto v = qu.front(); qu.pop();
		ll cur = get<0>(v);
		int depth = get<1>(v), r = get<2>(v), c = get<3>(v);
		if (cur == 123456780L) {
			answer = depth;
			break;
		}
		
		for (int i = 2; i >= 0; i--) {
			for (int j = 2; j >= 0; j--) {
				arr[i][j] = cur % 10;
				cur /= 10;
			}
		}

		for (int k = 0; k < 4; k++) {
			int tr = r + dr[k], tc = c + dc[k];
			if (!checkPos(tr, tc)) continue;
			swap(r, c, tr, tc);
			ll next = make();
			if (!visited[next]) {
				qu.push({ next, depth + 1, tr,tc });
				visited[next] = true;
			}
			swap(r, c, tr, tc);
		}
	}
	cout << answer;	
}