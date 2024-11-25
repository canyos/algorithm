#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <string>
#include <set>
#include <map>

using namespace std;

int n, m;
deque<int> dq;
int cur, answer;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		dq.push_back(i);
	
	for (int i = 0; i < m; i++) {
		cin >> cur;

		int dist;
		for (auto it = dq.begin(); it != dq.end(); it++) {
			if (*it == cur) {
				dist = it - dq.begin();
				break;
			}
		}

		if (dist <= dq.size() - dist) {
			
			while (dq.front() != cur) {
				dq.push_back(dq.front());
				dq.pop_front();
				answer++;
			}
			dq.pop_front();
		}
		else {
			while (dq.front() != cur) {
				dq.push_front(dq.back());
				dq.pop_back();
				answer++;
			}
			dq.pop_front();
		}
		//cout << answer << endl;
	}

	cout << answer;
	return 0;
}