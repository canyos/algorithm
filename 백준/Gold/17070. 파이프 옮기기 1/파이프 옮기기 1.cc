#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n;
int arr[17][17];
queue<tuple<int, int, int>> qu;
int answer = 0;

bool checkCondition(int r, int c, int dir) {
	if (r >= n || c >= n) return false;

	if (dir == 1) {
		return arr[r][c] == 0 && arr[r - 1][c] == 0 && arr[r][c - 1] == 0;
	}
	else {
		return arr[r][c] == 0;
	}
}
int main() {
	cin.tie(NULL); //입출력 묶음 해제
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	qu.push({ 0,1,0 });
	while (!qu.empty()) {
		auto v = qu.front(); qu.pop();
		int r = get<0>(v), c = get<1>(v), dir = get<2>(v);

		if (r == n - 1 && c == n - 1) {
			answer++;
			continue;
		}

		if (dir == 0) {
			//가로
			if(checkCondition(r, c + 1, 0))
				qu.push({ r,c + 1,0 });
			if (checkCondition(r + 1, c + 1, 1))
				qu.push({ r + 1,c+1,1 });
		}
		else if (dir == 1) {
			if (checkCondition(r, c + 1, 0))
				qu.push({ r,c + 1,0 });
			if (checkCondition(r + 1, c + 1, 1))
				qu.push({ r + 1,c + 1,1 });
			if (checkCondition(r + 1, c, 2))
				qu.push({ r+1,c,2 });
		}
		else if (dir == 2) {
			if (checkCondition(r + 1, c + 1, 1))
				qu.push({ r + 1,c + 1,1 });
			if (checkCondition(r + 1, c, 2))
				qu.push({ r + 1,c,2 });
		}
	}

	cout << answer;
	return 0;
}