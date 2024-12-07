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
int answer;
int arr[51][51];
bool visited[51][51];

int dc[4] = { 0,1,0,-1 }, dr[4] = { -1,0,1,0 }; //상 우 하 좌
int dirIndex = 1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	cin >> r >> c >> dirIndex;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];
	
	while (true) {
		if (!visited[r][c]) {
			answer++;
			visited[r][c] = true;
		}
			
		bool clean4 = false;
		for (int i = 0; i < 4; i++) {
			dirIndex = (dirIndex + 3) % 4;
			int tr = r + dr[dirIndex], tc = c + dc[dirIndex];
			if (arr[tr][tc] == 0 && !visited[tr][tc]) {
				clean4 = true;

				if (arr[tr][tc] == 0 && !visited[tr][tc]) {
					r = tr, c = tc;
				}
				break;
			}
		}

		if (clean4 == false) {
			int tr = r + dr[(dirIndex + 2) % 4];
			int tc = c + dc[(dirIndex + 2) % 4];
			if (arr[tr][tc] == 1)
				break;
			r = tr, c = tc;
		}
		//else {
		//	
		//}

	}

	cout << answer;

	return 0;
}