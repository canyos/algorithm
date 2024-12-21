#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <string>
#include <set>
#include <unordered_map>
#include <map>

using namespace std;
typedef long long ll;

int n, m;
int r, c;
int answer = 1'000'001;
int arr[1001][1001];
pair<int,int> visited[1001][1001];
queue<tuple<int, int,int,int>> qu;
int dr[4] = { 0,0,-1,1 }, dc[4] = { -1,1,0,0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j] - '0';
			visited[i][j].first = 1'000'001;
		}
	}
	
	
	qu.push({ 0, 0, 0, 1 });

	while (!qu.empty()) {
		auto v = qu.front(); qu.pop();
		int r = get<0>(v), c = get<1>(v), cnt = get<2>(v), dist = get<3>(v);

		if (visited[r][c].first <= dist && visited[r][c].second <= cnt)continue;
		visited[r][c].first = dist, visited[r][c].second = cnt;

		//cout << r << " " << c << " " << dist << endl;

		if (r == n-1 && c == m-1) {
			answer = min(answer, dist);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int tr = r + dr[i], tc = c + dc[i];
			int tCnt = cnt + arr[tr][tc];

			if (tCnt >= 2)continue;
			if (tr<0 || tr>n || tc<0 || tc>m) continue;
			qu.push({ tr,tc,tCnt,dist + 1 });
		}
	}

	if (answer == 1000001)
		cout << "-1";
	else
		cout << answer;

	return 0;
}