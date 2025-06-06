#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;

int s;
queue<tuple<int, int, int>> qu;
bool visited[2001][2001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> s;

	qu.push({ 1,0,0 });
	visited[1][0] = true;
	while (!qu.empty()) {
		auto q = qu.front();qu.pop();
		int screen = get<0>(q), clipboard = get<1>(q), depth = get<2>(q);
		
		if (screen == s) {
			cout << depth;
			return 0;
		}

		if (screen <2001 && !visited[screen][screen]) {
			qu.push({ screen, screen, depth+1 });
			visited[screen][screen] = true;
		}

		if (screen + clipboard < 2001 && !visited[screen + clipboard][clipboard]) {
			qu.push({ screen + clipboard, clipboard, depth + 1 });
			visited[screen + clipboard][clipboard] = true;
		}
		
		if (screen-1 > 0 && !visited[screen - 1][clipboard]) {
			qu.push({ screen - 1, clipboard, depth + 1 });
			visited[screen - 1][clipboard] = true;
		}
	}

	return 0;
}
