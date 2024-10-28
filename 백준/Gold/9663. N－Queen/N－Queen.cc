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
int cnt;
int board[15];

bool promising(int cdx) {
	for (int i = 0; i < cdx; i++) {
		if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i])) {
			return false;
		}
	}
	return true;
}

void nqueen(int cdx) {
	if (cdx == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		board[cdx] = i; 
		
		if (promising(cdx)) { 
			nqueen(cdx + 1); 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	nqueen(0);	
	cout << cnt;
	
	return 0;
}