#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;

int m, n;
int grow[1401];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> m >> n;

	int zero, one, two;
	for (int i = 0; i < n; i++) {
		cin >> zero >> one >> two;
		for (int j = zero; j < zero + one; j++)
			grow[j]++;
		for (int j = zero + one; j < zero + one + two; j++)
			grow[j] += 2;
	}

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < m;j++) {
			if (j == 0)
				cout << grow[m - 1 - i] + 1 << " ";
			else
				cout << grow[m - 1 + j] + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}