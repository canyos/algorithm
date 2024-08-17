#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> v(1001);
int col, row;
int arr[1001][1001];
int zeroCnt,bfsCnt;
queue<pair<int,int>> qu;
int result;

void input() {
	cin >> col >> row;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			if (!arr[i][j])zeroCnt++;
			if (arr[i][j] == 1) qu.push({ i,j });
		}
	}
}
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 };

int main() {
	input();
	if (zeroCnt == 0) {
		cout << 0;
		return 0;
	}

	while (!qu.empty()) {
		auto v = qu.front(); qu.pop();
		
		int y = v.first, x = v.second;//y가 세로 x가 가로
		//cout << y << " " << x << "\n";
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (arr[ty][tx]==0 && ty>=0 && tx>=0 && tx<col && ty<row) {
				qu.push({ ty,tx });
				arr[ty][tx] = arr[ty][tx]==0 ? arr[y][x] + 1 : min(arr[ty][tx], arr[y][x] + 1);
				if (arr[ty][tx] > result)result = arr[ty][tx];
				bfsCnt++;
			}
		}
	}
	
	if (bfsCnt == zeroCnt)cout << result-1;
	else cout << -1;
	
	return 0;
}