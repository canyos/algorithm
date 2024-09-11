#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
queue<int> qu;

int n, m;
int arr[102][102];
int sr, sc, er, ec;
ll result= 0x7fffffffffffffff;
ll visited[101][101][3];

int dr1[4] = { 0,0,1,-1 }, dc1[4] = { -1,1,0,0 };
int dr2[2] = { 1,-1 }, dc2[2] = { 0,0 };
int dr3[2] = { 0,0 }, dc3[2] = { 1,-1 };

void input() {
	cin >> n >> m;
	cin >> sr >>  sc >> er >> ec;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			for (int k = 0; k < 3; k++)
				visited[i][j][k] = 0x7fffffffffffffff;

		}
	}
			
	
}

void bfs() {
	queue<tuple<int,int,ll,int>> qu;
	qu.push({ sr,sc ,0, 1});
	while (!qu.empty()) {
		int r = get<0>(qu.front());
		int c = get<1>(qu.front());
		ll cost = get<2>(qu.front());
		int cnt = get<3>(qu.front())%3;
		qu.pop();

		//cout << r << " " << c << " " << cost << " " << cnt << endl;
		if (cost >= result) continue;

		if (cnt == 1) { //상하 이동
			for (int i = 0; i < 2; i++) {
				int tr = r + dr2[i], tc = c + dc2[i];
				ll visit = (tr * 1000 + tc) * 10 + cnt;
				int ncost = cost + arr[tr][tc];
				if (arr[tr][tc] != -1 && tr > 0 && tr <= n && visited[tr][tc][cnt]>ncost){
					visited[tr][tc][cnt] = ncost;
					qu.push({ tr,tc,ncost, cnt + 1 });
					if (tr == er && tc == ec) {
						result = min(result, cost);
					}
				}
			}
		}
		else if (cnt == 2) { //좌우 이동
			for (int i = 0; i < 2; i++) {
				int tr = r + dr3[i], tc = c + dc3[i];
				int ncost = cost + arr[tr][tc];
				ll visit = (tr * 1000 + tc) * 10 + cnt;
				if (arr[tr][tc] != -1 && tc > 0 && tc <= m && visited[tr][tc][cnt] > ncost) {
					visited[tr][tc][cnt] = ncost;
					qu.push({ tr,tc,cost + arr[tr][tc] , cnt + 1 });
					if (tr == er && tc == ec) {
						result = min(result, cost);
					}
				}
			}
		}
		else if (cnt == 0) { //상하 좌우 이동
			for (int i = 0; i < 4; i++) {
				int tr = r + dr1[i], tc = c + dc1[i];
				int ncost = cost + arr[tr][tc];
				ll visit = (tr * 1000 + tc) * 10 + cnt;
				if (arr[tr][tc] != -1 && tr > 0 && tr <= n && tc > 0 && tc <= m && visited[tr][tc][cnt] > ncost) {
					visited[tr][tc][cnt] = ncost;
					qu.push({ tr,tc,cost + arr[tr][tc] , cnt + 1 });
					if (tr == er && tc == ec) {
						result = min(result, cost);
					}
				}
			}
		}

	}

}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	bfs();	
	if (result == 0x7fffffffffffffff) cout << -1;
	else cout << result;
	return 0;
}