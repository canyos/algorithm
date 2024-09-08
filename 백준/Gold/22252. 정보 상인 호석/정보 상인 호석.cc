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


ll result = 0;
int q, state, items, value;
int nameCnt = 1;
map<string, int> mp;
string name;
priority_queue<int> qu[100005];

void input() {
	cin >> q;
}

void insertItem() {
	if (!mp[name]) {
		mp[name] = nameCnt++;
	}
	int idx = mp[name];

	for (int i = 0; i < items; i++) {
		cin >> value;
		qu[idx].push(value);
	}
	//cout << qu[idx].top() << endl;

}

void popItem() {
	if (!mp[name])return;
	int idx = mp[name];

	while (items > 0 && !qu[idx].empty()) {
		result += qu[idx].top();
		qu[idx].pop();
		items--;
	}
	//cout << result << endl;
}

void process() {
	
	cin >> state >> name >> items;
	if (state == 1) {
		insertItem();
	}
	if (state == 2) {
		popItem();
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	for (int i = 0; i < q; i++) {
		process();
	}
	
		
	cout << result;
	return 0;
}