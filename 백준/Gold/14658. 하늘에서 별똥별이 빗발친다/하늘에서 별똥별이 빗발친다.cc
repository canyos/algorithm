#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;
typedef long long ll;

int n, m, l, k;
vector<pair<int, int>> stars;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> l >> k;
	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		stars.push_back({ a,b });
	}

	int answer = 0;
	for (auto star : stars) {
		int r = star.first, c = star.second;
		for (int i = r; i >= r - l; i--) {
			int cnt = 0;
			
			for (auto star2 : stars) {
				if (star2.first >= i && star2.first <= i + l && star2.second >= c && star2.second <= c + l) {
					cnt++;
				}
			}
			//cout << i << " " << i + l << " " << c << " " << c + l <<  " " << cnt << "\n" ;
			answer = max(answer, cnt);
		}
	}
	cout << k-answer;
}
