#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <string>

typedef long long ll;
using namespace std;

int cnt[1000001];
int n,m;
priority_queue<pair<int,int>> pq;
bool btn[10];
int answer;
void recursive(int num, int pos, int r) {
	if (pos == r) {
		pq.push({ -r, num });
		return;
	}

	for (int i = (pos==0?1:0); i <= 9; i++) {
		if (btn[i]) {
			int temp = num * 10 + i;
			recursive(temp, pos + 1, r);
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	int a;
	fill(btn, btn + 10, true);
	for (int i = 0; i < m; i++) {
		cin >> a;
		btn[a] = false;
	}
	for (int i = 0; i < 1000001; i++) {
		cnt[i] = -1;
	}

	for (int i = 1; i <= 6; i++) {
		recursive(0, 0, i);
	}
	if(btn[0]) pq.push({ -1,0 });
	pq.push({ 0, 100 });
	
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int cost = -cur.first, num = cur.second;
		if (cnt[num] != -1)continue;
		cnt[num] = cost;
		if (num == n) {
			answer = cost;
			break;
		}
		if (cnt[num - 1] == -1 ) {
			pq.push({  -(cost + 1), num-1 });
		}
		if (cnt[num + 1] == -1) {
			pq.push({ -(cost + 1), num + 1 });
		}
	}
	cout << answer;
	return 0;
}