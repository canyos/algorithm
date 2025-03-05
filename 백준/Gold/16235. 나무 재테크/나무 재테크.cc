#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <deque>

using namespace std;

int n, m, k;
int map[11][11];
int arr[11][11];
deque<int> dq[11][11];
vector<tuple<int, int, int>> removeList;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	fill(&map[0][0], &map[0][0] + 11 * 11, 5);

	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
			cin >> arr[i][j];

	int rr, cc, age;
	for (int i = 0; i < m; i++) {
		cin >> rr >> cc >> age;
		dq[rr][cc].push_front(age);
	}

	for (int i = 0; i < k; i++) {
		//봄
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {

				int sz = dq[r][c].size();
				for (int k = 0; k < sz;k++) {
					int a = dq[r][c].front(); dq[r][c].pop_front();
					if (map[r][c] >= a) {
						map[r][c] -= a;
						dq[r][c].push_back(a + 1);
					}
					else {
						removeList.push_back({ r,c, a });
					}
				}
			}
		}

		//여름
		for (auto it : removeList) {
			int r = get<0>(it), c = get<1>(it), age = get<2>(it);
			map[r][c] += age / 2;
		}

		removeList = {};

		//가을
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= n; c++) {
				int sz = dq[r][c].size();

				for (int k = 0; k < sz; k++) {
					int a = dq[r][c].front(); dq[r][c].pop_front(); dq[r][c].push_back(a);
					if (a % 5 == 0) {
						for (int rr = max(1, r - 1); rr <= min(r + 1, n); rr++) {
							for (int cc = max(1, c - 1); cc <= min(c + 1, n); cc++) {
								if (r == rr && cc == c)continue;
								dq[rr][cc].push_front(1);
							}
						}
					}
				}
			}
		}

		//겨울
		for (int r = 1; r <= n; r++)
			for (int c = 1; c <= n; c++)
				map[r][c] += arr[r][c];
	}
	int sum = 0;
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			sum += dq[r][c].size();
			//cout << st[r][c].size() << " ";
		}
		//cout << '\n';
	}

	cout << sum;
	return 0;
}
