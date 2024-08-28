#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>

using namespace std;
int N, M, R,result;
int arr[101][101];
bool stand[101][101];

void input() {
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i + 1][j + 1];
			stand[i + 1][j + 1] = 1;
		}
	}
}

void attack() {
	int r, c;
	char dir;
	int height;
	cin >> r >> c >> dir;
	height = arr[r][c];
	if (dir == 'N') {
		for (int i = r; i > 0; i--) {
			if (stand[i][c] && height>0) {
				stand[i][c] = 0;
				result++;
				height = max(height - 1, arr[i][c]-1);
			}
			else {
				height = height - 1;
			}
		}
	}
	else if (dir == 'E') {
		for (int i = c; i <=M; i++) {
			if (stand[r][i] && height>0) {
				stand[r][i] = 0;
				result++;
				height = max(height - 1, arr[r][i]-1);
			}
			else {
				height = height - 1;
			}
		}
	}
	else if (dir == 'S') {
		for (int i = r; i <=N ; i++) {
			if (stand[i][c] && height>0) {
				stand[i][c] = 0;
				result++;
				height = max(height - 1, arr[i][c]-1);
			}
			else {
				height = height - 1;
			}
		}
	}
	else if (dir == 'W') {
		for (int i = c; i >0; i--) {
			if (stand[r][i] && height>0) {
				stand[r][i] = 0;
				result++;
				height = max(height - 1, arr[r][i]-1);
			}
			else {
				height = height - 1;
			}
		}
	}
	
}

void defense() {
	int r, c;
	cin >> r >> c ;
	stand[r][c] = 1;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	for (int i = 0; i < R; i++) {
		attack();
		defense();
	}
	
	cout << result << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (stand[i][j])
				cout << "S ";
			else
				cout << "F ";
		}
		cout << '\n';
	}

	return 0;
}