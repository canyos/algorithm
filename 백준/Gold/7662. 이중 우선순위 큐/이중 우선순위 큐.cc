#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <cmath>
using namespace std;

typedef long long ll;
int n, k, num;
priority_queue<pair<int,int>> pq1;//최대
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2; //최소
string str;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		pq1 = {}, pq2 = {};
		bool visited[1'000'001] = { 0 };
		for (int ii = 0; ii < k; ii++) {
			cin >> str >> num;
			if (str == "I") {
				pq1.push({ num,ii });
				pq2.push({ num,ii });
			}
			else {
				if (pq1.empty() || pq2.empty() )
					continue;
				if (num == -1) {
					while (!pq2.empty() && visited[pq2.top().second])
						pq2.pop();
					if (pq2.empty()) {
						pq1 = {};
						continue;
					}
					visited[pq2.top().second] = true;
					pq2.pop();
				}
				else {
					while (!pq1.empty() && visited[pq1.top().second])
						pq1.pop();
					if (pq1.empty()) {
						pq2 = {};
						continue;
					}
					visited[pq1.top().second] = true;
					pq1.pop();
				}
			}
		}

		while (!pq1.empty() && visited[pq1.top().second]) {
			pq1.pop();
		}
		while (!pq2.empty() && visited[pq2.top().second]) {
			pq2.pop();
		}
		if (pq1.empty() || pq2.empty()) 
			cout << "EMPTY\n";
		else
			cout << pq1.top().first << " " << pq2.top().first << '\n';
	}
	
	return 0;
}