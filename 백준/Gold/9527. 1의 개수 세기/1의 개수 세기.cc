#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <deque>
#include <climits>
#include <stack>
#include <bitset>
typedef long long ll;

using namespace std;

ll count(ll n) {
	ll sum = 0;
	int a = 0;
	for (int i = 62; i >= 0; i--) {
		ll b = (1ll << i);
		if (n & b) {
			if (a == 0) {
				sum += (b / 2 * i + 1);
				a++;
			}
			else {
				sum += (b / 2 * i + 1) + b * (a++);
			}
		}			
	}
	return sum;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	ll a, b;
	cin >> a >> b;
	cout << count(b) - count(a - 1);


	return 0;
}
