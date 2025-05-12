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

int n;
stack<int> st;
int answer = 0;
int h = 0;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;

	st.push(0);

	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (y > h) {
			st.push(y);
			answer++;
			//cout << "++";
		}
		else if (y < h) {
			while (st.top() > y) {
				st.pop();
			}
			if (st.top()!=y) {
				answer++;
				st.push(y);
				//cout << "++";
			}
		}
		h = y;
	}


	cout << answer;

	return 0;
}