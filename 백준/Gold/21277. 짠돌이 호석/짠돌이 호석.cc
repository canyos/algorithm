#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int N1, M1, N2, M2; 
string temp;
bool arr1[51][51];
bool arr2[4][51][51];
int result ;

void input() {
	cin >> N1 >> M1;
	for (int i = 0; i < N1; i++) {
		cin >> temp;
		for (int j = 0; j < M1; j++) {
			arr1[i][j] = temp[j] - '0';
		}
	}
	cin >> N2 >> M2;
	for (int i = 0; i < N2; i++) {
		cin >> temp;
		for (int j = 0; j < M2; j++) {
			arr2[0][i][j] = temp[j] - '0';
			arr2[1][j][N2 - 1 - i] = temp[j] - '0';
			arr2[2][N2 - 1 - i][M2 - 1 - j]= temp[j] - '0';
			arr2[3][M2 - 1 - j][i] = temp[j] - '0';
		}
	}
}


bool combine(int i, int j, int k, bool first_fixed) {
	int h = (k % 2 == 0) ? N2 : M2;
	int w = (k % 2 == 0) ? M2 : N2;
	for (int a = 0; a < h; a++) {
		for (int b = 0; b < w; b++) {
			if (first_fixed) {
				if (i + a >= N1 || j + b >= M1) continue;
				if (arr1[i + a][j + b] && arr2[k][a][b]) return false;
			}
			else {
				if (a + i >= N2 || b + j >= M2) continue;
				if (arr1[a][b] && arr2[k][a + i][b + j]) return false;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	result = min({ (N1 + N2) * max(M1, M2),
				  (M1 + M2) * max(N1, N2),
				  (N1 + M2) * max(M1, N2),
				  (M1 + N2) * max(N1, M2) });

	// First puzzle fixed, second puzzle moving
	for (int i = 0; i < N1; i++) {
		for (int j = 0; j < M1; j++) {
			for (int k = 0; k < 4; k++) {
				if (combine(i, j, k, true)) {
					int h = (k % 2 == 0) ? N2 : M2;
					int w = (k % 2 == 0) ? M2 : N2;
					result = min(result, max(N1, i + h) * max(M1, j + w));
				}
			}
		}
	}

	// Second puzzle fixed, first puzzle moving
	for (int i = 0; i < N2; i++) {
		for (int j = 0; j < M2; j++) {
			for (int k = 0; k < 4; k++) {
				if (combine(i, j, k, false)) {
					int h = (k % 2 == 0) ? N2 : M2;
					int w = (k % 2 == 0) ? M2 : N2;
					result = min(result, max(N1 + i, h) * max(M1 + j, w));
				}
			}
		}
	}

	cout << result;
	return 0;
}