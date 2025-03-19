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

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int>v[4];
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> num;
			v[j].push_back(num);
		}
	}

	for (int j = 0; j < 4; j++) {
		sort(v[j].begin(), v[j].end());
	}
	
	vector<int> temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp.push_back(v[0][i] + v[1][j]);
		}
	}

	sort(temp.begin(), temp.end());
	long long answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			num = v[2][i] + v[3][j];
			int a = upper_bound(temp.begin(), temp.end(), -num) - lower_bound(temp.begin(), temp.end(), -num);
			//if (a)
			//	cout << v[2][i] << " " << v[3][j] << " " << -num << endl;
			answer += a;

		}
	}

	cout << answer;
	return 0;
}
