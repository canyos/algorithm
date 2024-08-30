#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <map>

using namespace std;
int N, M, K;
char arr[11][11];
map<string, int> mp;

void input() {
	cin >> N  >>M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
}
int dr[8] = { 0,0,1,-1,-1,1,-1,1 }, dc[8] = { -1,1,0,0,1,1,-1,-1 };

void bfs(int r,int c) {
	string str = "";
	queue<pair<string,int>> qu;
	qu.push({ str+arr[r][c],r * 100 + c });
	while (!qu.empty()) {
		string v = qu.front().first;
		//cout << v << endl;
		int r = qu.front().second / 100, c = qu.front().second % 100; 
		qu.pop();
		mp[v]++;
		if (v.length() ==5) {
			continue;
		}
		for (int i = 0; i < 8; i++) {
			int tr = r + dr[i], tc = c + dc[i];
			if (tr == 0)tr = N;
			if (tr == N + 1)tr = 1;
			if (tc == 0) tc = M;
			if (tc == M + 1) tc = 1;
			qu.push({ v + arr[tr][tc], tr * 100 + tc });
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			bfs(i, j);
		}
	}
	string temp;
	for (int i = 0; i < K; i++) {
		cin >> temp;
		cout << mp[temp] << '\n';
	}

	return 0;
}