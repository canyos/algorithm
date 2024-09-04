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

int N, M, N2, M2;
string temp;
bool arr[51][51];
bool arr2[4][51][51];
int result;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 0; j < M; j++) {
			arr[i][j] = temp[j] - '0';
		}
	}
	cin >> N2 >> M2;
	for (int i = 0; i < N2; i++) {
		cin >> temp;
		for (int j = 0; j < M2; j++) {
			arr2[0][i][j] = temp[j] - '0';
			arr2[1][j][N2 - 1 - i] = temp[j] - '0';
			arr2[2][N2 - 1 - i][M2 - 1 - j] = temp[j] - '0';
			arr2[3][M2 - 1 - j][i] = temp[j] - '0';
		}
	}
}


bool combine(int i, int j, int k) {
	for (int a = 0; a + i < N; a++) {
		for (int b = 0; b + j < M; b++) {
			if (arr[a + i][b + j] & arr2[k][a][b])
				return false;
		}
	}
	return true;
}

bool combine2(int i, int j, int k) {
	for (int a = 0; a + i < (k % 2 == 0 ? N2 : M2); a++) {
		for (int b = 0; b + j < (k % 2 == 0 ? M2 : N2); b++) {
			if (arr[a][b] & arr2[k][a + i][b + j])
				return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();


	result = min((N + N2)*max(M, M2), (M + M2)*max(N, N2));
	result = min(result, (N + M2)*max(M, N2));
	result = min(result, (M + N2)*max(N, M2));//하나도 안겹쳤을때

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				if (combine(i, j, k)) {
					if (k % 2) {//n2 <->m2 교체
						result = min(result, max(N, i + M2)* max(M, j + N2));
						//cout << i << " " << j << " " << k << " " << max(N, i + M2) << " " << max(M, j + N2) << endl;
					}
					else { //n2, m2그대로
						result = min(result, max(N, i + N2)*max(M, j + M2));
						//cout << i << " " << j << " " << k << " " << max(N, i + N2) << " " << max(M, j + M2) << endl;
					}

				}
			}
		}
	}
	
	for (int k = 0; k < 4; k++) {//2번 그림 고정
		for (int i = 0; i < (k % 2 == 0 ? N2 : M2); i++) {//회전 체크
			for (int j = 0; j < (k % 2 == 0 ? M2 : N2); j++) {//회전 체크
				if (combine2(i, j, k)) {
					if (k % 2) {//n2 <->m2 교체
						result = min(result, max(M + j, N2)* max(N + i, M2));
						//cout << i << " " << j << " " << k << " " << max(N, i + M2) << " " << max(M, j + N2) << endl;
					}
					else { //n2, m2그대로
						result = min(result, max(N + i, N2)*max(M + j, M2));
						//cout << i << " " << j << " " << k << " " << max(N, i + N2) << " " << max(M, j + M2) << endl;
					}

				}
			}
		}
		
	}
	cout << result;
	return 0;
}