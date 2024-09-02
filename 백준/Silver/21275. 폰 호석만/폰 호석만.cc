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

ll X;
int A, B;
string strA, strB;
void input() {
	cin >> strA >> strB;
}

int findMax(string str) {
	int maxNum = 0;
	for (int i = 0; i < str.length(); i++) {
		if ('0' <= str[i] && str[i] <= '9')
			maxNum = max(maxNum, str[i] - '0');
		else
			maxNum = max(maxNum, str[i] - 'a'+10);
	}
	return maxNum;
}

int stringToDec(string str, int n) {
	int sum = 0;
	int k = pow(n, str.length() - 1);
	for (int i = 0; i < str.length(); i++) {
		if ('0' <= str[i] && str[i] <= '9')
			sum += (str[i] - '0')*k;
		else
			sum += (str[i] - 'a'+10)*k;
		k /= n;
	}
	return sum;
}

vector<tuple<ll, int, int>> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	int ii = findMax(strA), jj = findMax(strB);
	//cout << ii << " " << jj << endl;
	for (int i = ii + 1; i <= 36; i++) {
		for (int j = jj + 1; j <= 36; j++) {
			ll a = stringToDec(strA, i), b = stringToDec(strB, j);
			if (a == b && a >= 0 &&  i!=j) {
				v.push_back({ a, i, j });
			}
			//cout << a << " " << b << " " << i << " " << j << endl;
		}
	}
	if (v.size() == 0)cout << "Impossible";
	else if (v.size() == 1) cout << get<0>(v[0]) << " " << get<1>(v[0]) << " " << get<2>(v[0]);
	else cout << "Multiple";
	return 0;
}