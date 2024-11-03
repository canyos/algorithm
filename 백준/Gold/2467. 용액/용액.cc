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
ll answer=1e10, answer1, answer2;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	int left = 0, right = n - 1;
	while (left < right) {
		ll cur = arr[left] + arr[right];

		if (abs(cur) < answer) {
			answer = abs(cur);
			answer1 = arr[left], answer2 = arr[right];
		}

		if (cur < 0) 
			left++;
		
		if (cur > 0) 
			right--;
		
		if (cur == 0)
			break;
	}
		
	cout << answer1 << " " << answer2;

	return 0;
}