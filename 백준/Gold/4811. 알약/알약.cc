#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <string>

typedef long long ll;
using namespace std;

int n;
ll nCr[61][61];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int i = 0; i <= 60; i++) {
		nCr[i][0] = 1;
		nCr[i][i] = 1;
		nCr[i][1] = i;
		nCr[i][i] = 1;
	}
	for (int i = 3; i <= 60; i++) {
		for (int j = 2; j < i; j++) {
			nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
		}
	}
	int num;
	cin >> num;
	do {
		cout << nCr[num * 2][num] / (num + 1) << "\n";
		cin >> num;
	} while (num > 0);
	return 0;
}