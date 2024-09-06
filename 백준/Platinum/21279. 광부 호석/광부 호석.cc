#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
vector<int> itemX[100001];
vector<int> itemY[100001];

int N, C;
int x, y, v;
int h = 100000, w = 0, sum = 0, result = 0,cnt=0;


void input() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> v;
		itemX[x].push_back(v);
		itemY[y].push_back(v);
	}
}
void del(int h) {
	for (int v : itemY[h]) {
		cnt--;
		sum -= v;
	}
}

void add(int w) {
	for (int v : itemX[w]) {
		cnt++;
		sum += v;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	
	while (h > 0 && w <= 100000) {
		//cout << w << " " << h << " " <<cnt << endl;
		if (cnt > C)del(h--);
		else add(w++);
		
		if (cnt <= C) {
			if (sum > result) {
				
				result = max(result, sum);
			}
			
		}
			

	}
	cout << result;
	
	
	return 0;
}