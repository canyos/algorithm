#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <cmath>
#include <unordered_map>
using namespace std;

typedef long long ll;
int n;
vector<int> arr;
unordered_map <int,vector<pair<int,int>>> mp;

int answer;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int j = 0; j < n; j++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	for (int i = 0; i < n; i++) { //2000*2000 = 4,000,000
		for (int j = i + 1; j < n; j++) {
			mp[arr[i] + arr[j]].push_back({ i,j });
		}
	}
	
	for (int i = 0; i < n; i++) {//4,000,000
		for (auto& it : mp[arr[i]]) {
			if (i != it.first && i != it.second) {
				//cout << i << endl;
				answer++;
				break;
			}
		}
	}
	cout << answer;
	return 0;
}