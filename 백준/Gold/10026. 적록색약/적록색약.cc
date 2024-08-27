#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>

using namespace std;
int n;
char arr[101][101];
int result, result2;
stack<pair<int, int>> st;
int dr[4] = { 0,0,1,-1 }, dc[4] = { 1,-1,0,0 };
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

void dfs() {
	bool visited[101][101] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				st.push({ i,j }); 
				result++; 
				visited[i][j] = 1;
			};
			while (!st.empty()) {
				auto r = st.top().first, c = st.top().second;
				st.pop();
				for (int k = 0; k < 4; k++) {
					int tr = r + dr[k], tc = c + dc[k];
					if (tr >= 0 && tr < n&& tc >= 0 && tc < n && !visited[tr][tc] && arr[r][c]==arr[tr][tc]) {
						st.push({ tr,tc });
						visited[tr][tc] = 1;
					}
				}
			}
		}
	}
	cout << result;
}

void dfs2() {
	bool visited[101][101] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				st.push({ i,j });
				result2++;
				visited[i][j] = 1;
			};
			while (!st.empty()) {
				auto r = st.top().first, c = st.top().second;
				st.pop();
				for (int k = 0; k < 4; k++) {
					int tr = r + dr[k], tc = c + dc[k];
					if (tr >= 0 && tr < n&& tc >= 0 && tc < n && !visited[tr][tc] ) {
						if (arr[r][c] == 'R' && arr[tr][tc] == 'G' || arr[r][c] == 'G' && arr[tr][tc] == 'R' || arr[r][c] == arr[tr][tc]) {
							st.push({ tr,tc });
							visited[tr][tc] = 1;
						}
					}
				}
			}
		}
	}
	cout << " " << result2;
}


int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	dfs();
	dfs2();
	return 0;
}