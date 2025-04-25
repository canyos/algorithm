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
int n, a, b;
pair<int,int> par[1000001]; 
pair<int, int> find(int a) {
	if (par[a].first == a)
		return par[a];
	return par[a] = find(par[a].first);
}

void merge(int a, int b) {
	pair<int, int> x = find(a), y = find(b);
	if (x.first == y.first)return;
	par[x.first].first = y.first;
	par[y.first].second += x.second;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	char ch;
	int idx = 1;
	for (int i = 1; i <= 1000000; i++)
		par[i] = { i,1 };

	for (int i = 1; i <= n; i++) {
		cin >> ch;
		if (ch == 'I') {
			cin >> a >> b;
			merge(a, b);
		}

		else {
			cin >> a;
			cout << find(a).second << '\n';
		}
	}
}
