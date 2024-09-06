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
struct item {
	int x;
	int y;
	int value;
} ;
vector<item> itemX[100001];
vector<item> itemY[100001];

int N, C;
int x, y, v;
int h = 100000, w = 0, cnt=0;
ll sum = 0,result = 0;


void input() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> v;
		itemX[x].push_back({ x,y,v });
		itemY[y].push_back({ x,y,v });
	}
}
void del(int h) {
	for (item it : itemY[h]) {
		if (it.x <= w) {
			cnt--;
			sum -= it.value;
		}
		
	}
}

void add(int w) {
	for (item it : itemX[w]) {
		if (it.y <= h) {
			cnt++;
			sum += it.value;
		}

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