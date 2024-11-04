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
int n;
vector<int> arr;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt = 0;
	int result = 1;
	for (int i = 1; i<=46341; i++) {
		cnt += i;
		if (cnt < 0) {
			//cout << i;
			break;
		}
			
		arr.push_back( cnt );
		
		cnt += i;
		if (cnt < 0) {
			//cout << i;
			break;
		}
			
		arr.push_back( cnt );
	}

	arr.push_back( 2147483647 );
	
	cin >> n;
	int start, end;
	for (int j = 0; j < n; j++) {
		
		cin >> start >> end;

		int dist = end-start;

		for (int i = 0; i < 92682; i++) {
			if (arr[i] >= dist) {
				cout << i+1 << '\n';
				break;
			}
		}
	}

	return 0;
}