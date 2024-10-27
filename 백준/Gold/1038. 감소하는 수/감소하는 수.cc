#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
int n;

int nCr[15][15];
int start[11][11] = { {}, {1,1,1,1,1,1,1,1,1,1} }; //i번째 자리수에서 j로 시작하는 수의 개수
ll result;

void func(int n, int k) {//n자리수 중 k번째로 감소하는 수
	if (n == 0) 
		return;
	if (n == 1) {
		result = result * 10 + k-1;
		return;
	}

	int sum=0;
	for (int i = n - 1; i <= 9; i++) {
		sum += start[n][i];
		if (sum >= k) {
			result = result * 10 + i;
			func(n - 1, k-(sum-start[n][i]));
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	if (n >= 1023) {
		cout << -1;
		return 0;
	}

	if (n <= 9) {
		cout << n;
		return 0;
	}

	for (int i = 1; i <= 10; i++) {
		nCr[i][0] = 1;
		nCr[i][1] = i;
		for (int j = 2; j <= i; j++) {
			nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
		}
	}
	
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k < j; k++) {
				start[i][j] += start[i - 1][k];
			}
		}
	}

	//for (int i = 1; i <= 10; i++) {
	//	for (int j = 1; j <= 10; j++) {
	//		cout << nCr[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	int sum=0;
	for (int i = 1; sum <= n; i++) {
		sum += nCr[10][i];
		if (sum > n) {
	 		func(i, n-(sum-nCr[10][i])+1); //i자리 수 중 sum-n번째 감소하는 수
			break;
		}
	}

	cout << result;
	return 0;
}