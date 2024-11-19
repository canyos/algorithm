#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <string>
#include <set>
#include <map>

using namespace std;


int n, k;
set<pair<int, int>> st;
map<int, int> mp;
int p, l, m;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> l;
		st.insert({ l,p });
		mp[p] = l;
	}

	cin >> m;
	string instruction;
	for (int i = 0; i < m; i++) {
		cin >> instruction;
		if (instruction == "add") {
			cin >> p;
			cin >> l;

			st.insert({ l,p });
		}
		if (instruction == "recommend") {
			int x;
			cin >> x;
			if (x==1) {
				cout << st.rbegin()->second << '\n';
			}
			else {
				cout << st.begin()->second << '\n';
			}

		}
		if (instruction == "solved") {
			cin >> p;
			l = mp[p];
			st.erase({ l,p });
		}
	}
	return 0;
}