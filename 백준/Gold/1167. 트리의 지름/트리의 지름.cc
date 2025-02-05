#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
#include <stack>
#include <unordered_set>
using namespace std;

int n;
vector<pair<int,int>> edge[100001];
bool visited[100001];
int answer;

int recursive(int cur, int cost) {
	visited[cur] = true;

	vector<int> v;
	for (auto e : edge[cur]) {
		if (visited[e.first]) continue;
		int a = recursive(e.first, cost + e.second) + e.second;
		v.push_back(a);
	}

	int a = 0;

	if (v.size() == 0) 
		return 0;
	else if (v.size() == 1) {
		answer = max(answer,v[0]);
		return v[0];
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	if(v.size()>1)	answer = max(answer, v[0] + v[1]);
	return v[0];
}

void input()
{
	cin >> n;
	int cur, next, cost;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		while (true) {
			cin >> next;
			if (next == -1)break;
			cin >> cost;
			edge[cur].push_back({ next,cost });
		}
	}
}

bool chkPos(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < n;
}

int main() {
	cin.tie(NULL); //입출력 묶음 해제
	ios_base::sync_with_stdio(false);
	
	input();
	
	cout << max(answer, recursive(1,0));

	return 0;
}