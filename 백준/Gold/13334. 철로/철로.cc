#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <deque>

using namespace std;
bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second < p2.second;
}
int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	
	vector<pair<int, int>> list;
	priority_queue<pair<int, int>> pq;
	vector<int>v;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a < b)
			list.push_back({ a,b });
		else
			list.push_back({ b,a });
		v.push_back(a);
		v.push_back(b);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	sort(list.begin(), list.end(),compare);

	int d;
	cin >> d;
	int answer = 0;

	for (int i = 0; i < list.size(); i++) {
		int start = list[i].second - d, end = list[i].second;
		if (start <= list[i].first && list[i].second <= end) {
			pq.push({ -list[i].first, -list[i].second });
		}

		while (!pq.empty() && -pq.top().first < start) {
			pq.pop();
		}
		answer = max(answer, (int)pq.size());
	}
	cout << answer;


	return 0;
}
