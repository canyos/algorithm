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
int N, L, M;
vector<pair<int, int>> fishes;
vector<int> x;
vector<int> y;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> L >> M;
	L /= 2;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		fishes.push_back({ a,b });
		x.push_back(a);
		y.push_back(b);
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	y.erase(unique(y.begin(), y.end()), y.end());

	int answer = 0;
	for (auto r : x) {
		for (auto c : y) {
			for (int h = 1; h < L; h++) {
				int w = L - h;
				int cnt = 0;
				for (auto fish : fishes) {
					if (r <= fish.first && fish.first <= r + h && c <= fish.second && fish.second <= c + w) {
						cnt++;
					}
				}
				answer = max(answer, cnt);


			}
		}
	}

	cout << answer;

	return 0;
}