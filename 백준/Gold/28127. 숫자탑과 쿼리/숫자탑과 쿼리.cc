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
int a, d, x;
int r, c;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int ii = 0; ii < n; ii++) {
		cin >> a >> d >> x;
		ll sum = 0;
		for (int i = 0; i < 100000; i++) {
			sum += a + d * i;
			if (sum >= x) {
				r = i + 1;
				c = x - (sum - (a + d * i));
				break;
			}
		}

		cout << r << " " << c << "\n";
	}
	
	
	return 0;
}