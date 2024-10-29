#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <cmath>
using namespace std;

typedef long long ll;
int n;
void hanoi(int start, int mid, int dest, int n) {
	if (n == 1) {
		cout << start << " " << dest << '\n';
		return;
	}
	
	hanoi(start, dest, mid, n - 1);
	hanoi(start, mid, dest, 1);
	hanoi(mid, start, dest, n - 1);
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	cout << 1ll * (ll) pow(2, n) - 1 << '\n';
	hanoi(1, 2, 3, n);
	
	return 0;
}