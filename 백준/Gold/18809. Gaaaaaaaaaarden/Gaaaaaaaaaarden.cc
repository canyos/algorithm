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

int n, m, G, R;
int arr[51][51];
int arr2[51][51];

vector<pair<int, int>> v;
vector<int> perm;

bool checkPos(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}
int dr[] = { 0,0,-1,1 }, dc[] = { -1,1,0,0 };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> G >> R;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				v.push_back({ i,j });
			}
		}
	}
	//0은 호수, 1은 뿌릴 수 없는 땅, 2는 뿌릴 수 있는 땅
	for (int i = 0; i < v.size() - G - R; i++) {
		perm.push_back(1);
	}
	for (int i = 0; i < G; i++) {
		perm.push_back(2);
	}
	for (int i = 0; i < R; i++) {
		perm.push_back(3);
	}
	

	queue<tuple<int, int, int>> qu;
	int answer = 0;
	do {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr2[i][j] = arr[i][j];
		
		int visited[51][51] = { 0 };

		//0은 호수, 1은 확장가능한 공간, 2는 녹색, 3은 빨강
		for (int i = 0; i < v.size(); i++) {
			arr2[v[i].first][v[i].second] = perm[i];
			if (perm[i] != 1) {
				qu.push({ v[i].first,v[i].second,1 });
				visited[v[i].first][v[i].second] = 1;
			}
		}

		int cnt = 0;

		while (!qu.empty()) {
			auto cur = qu.front(); qu.pop();
			int r = get<0>(cur), c = get<1>(cur), depth = get<2>(cur);

			if (arr2[r][c] == 4) {//현재 위치는 꽃이핌
				cnt++;
				continue;
			}

			for (int k = 0; k < 4; k++) {
				int tr = r + dr[k], tc = c + dc[k];
				if (checkPos(tr, tc)) {
					if (arr2[tr][tc] == 1) {//확장 가능한 공간임
						qu.push({ tr,tc,depth + 1 });
						visited[tr][tc] = depth + 1;
						arr2[tr][tc] = arr2[r][c];
					}
					else if (arr2[tr][tc] == 2 && arr2[r][c] == 3 ||
						arr2[tr][tc]==3 && arr2[r][c]==2) {//빨강이랑 녹색이 만남
						if (visited[tr][tc] == depth + 1) {//동시에 도착
							arr2[tr][tc] = 4;
						}	
					}
				}
			}
		}
		answer = max(answer, cnt);
	} while (next_permutation(perm.begin(), perm.end()));
	cout << answer;

	return 0;
}
/*
5 30
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
*/