#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int a, b, c;
map<tuple<int, int, int>, bool>visited;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> a >> b >> c;

	queue<tuple<int, int, int>> qu;
	qu.push({ a,b,c });
	visited[{ a, b, c }] = true;

	while (!qu.empty()) {
		auto cur = qu.front(); qu.pop();
		int aa = get<0>(cur), bb = get<1>(cur), cc = get<2>(cur);
		if (aa == bb && bb == cc) {
			cout << 1;
			return 0;
		}

		if (aa != bb) {
			if (aa<bb && !visited[{ aa * 2, bb - aa, cc }]) {
				qu.push({ aa * 2, bb - aa,cc });
				visited[{ aa * 2, bb - aa, cc }] = true;
			}
			if (aa > bb  && !visited[{ aa - bb, bb * 2, cc }]) {
				qu.push({ aa - bb, bb * 2,cc });
				visited[{ aa - bb, bb * 2, cc }] = true;
			}
		}
		if (aa != cc) {
			if (aa < cc  && !visited[{ aa * 2, bb, cc - aa }]) {
				qu.push({ aa * 2, bb,cc - aa });
				visited[{ aa * 2, bb, cc - aa }] = true;
			}
			if (aa > cc  && !visited[{ aa - cc, bb, cc * 2 }]) {
				qu.push({ aa - cc, bb,cc * 2 });
				visited[{ aa - cc, bb, cc * 2 }] = true;
			}
		}
		if (bb != cc) {
			if (bb < cc  && !visited[{ aa, bb * 2, cc - bb }]) {
				qu.push({ aa, bb*2,cc - bb });
				visited[{ aa, bb * 2, cc - bb }] = true;
			}
			if (bb > cc && !visited[{ aa, bb - cc, cc * 2 }]) {
				qu.push({ aa, bb - cc,cc * 2 });
				visited[{ aa, bb - cc, cc * 2 }] = true;
			}
		}
	}
	cout << 0;
	return 0;
}