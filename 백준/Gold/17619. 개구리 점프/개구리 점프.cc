#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int n, m;
vector<tuple<int, int, int, int>> v;
int par[100001];

bool compare(const tuple<int, int, int, int>& t1, const tuple<int, int, int, int>& t2) {
	return (get<0>(t1) < get<0>(t2)) ;
}

int find(int a) {
	if (par[a] == a)
		return a;
	return par[a] = find(par[a]);
}

void merge(int a, int b) {
	int x = find(a), y = find(b);
	par[x] = y;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int x1, x2, y;

	//for (int i = 1; i <= 100000; i++)
	//	par[i] = i;

	for (int i = 1; i <= n; i++) {
		cin >> x1 >> x2 >> y;
		v.push_back({ x1,x2,y,i });
	}

	sort(v.begin(), v.end(), compare);

	int right = get<1>(v[0]);
	int idx = 1;
	par[get<3>(v[0])] = 1;
	for (int i = 1; i < n; i++) {
		if (get<0>(v[i]) <= right) {
			par[get<3>(v[i])] = idx;
			right = max(right, get<1>(v[i]));
		}
		else {
			par[get<3>(v[i])] = ++idx;
			right = get<1>(v[i]);
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> x1 >> x2;

		if (par[x1] == par[x2]) 
			cout << "1\n";
		else 
			cout << "0\n";
	}

	return 0;
}