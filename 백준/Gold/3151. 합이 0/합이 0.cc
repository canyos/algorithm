#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;
typedef long long ll;

int n;
vector<int> v;
ll answer;
unordered_map<int, int> mp;


int main()
{

	cin >> n ;
	int temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		v.push_back(temp);
		mp[temp]++;
	}

	sort(v.begin(), v.end()); 

	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			long long cnt = v[i] + v[j];
			int idx1 = lower_bound(v.begin() + j + 1, v.end(), -cnt) - v.begin();
			int idx2 = upper_bound(v.begin() + j + 1, v.end(), -cnt) - v.begin();
			answer += idx2 - idx1;
		}
	}
	
	
	cout << answer;

	return 0;
}