#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
int n;
int start, to;
vector<pair<int, int>> edges;
int cnt[100001];
int result;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.first < p2.first)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);    

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start >> to;
		edges.push_back({ start,to });
	}
	sort(edges.begin(), edges.end(), compare);
	
	for (int i = 0; i < edges.size();i++) {
		cnt[i] = 1;
		for (int j = 0; j < i; j++) {
			if (edges[i].second > edges[j].second) {
				cnt[i] = max(cnt[i], cnt[j] + 1);
			}
		}
		result = max(result, cnt[i]);
	}

	cout << n-result;
	return 0;

}