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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		int num;
		cin >> num;
		int temp = num;
		int cnt = 0;
		while (temp != 1) {
			if (temp % 2)temp = temp * 3 + 1;
			else temp /= 2;
			cnt++;
		}
		cout << "#" << T << " " << num << " " << cnt << "\n";
	}

	return 0;
}