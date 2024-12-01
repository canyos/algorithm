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

int n, m, l;
vector<int>v;
int answer;

int main()
{
	cin >> n >> m >> l;

	v.push_back(0);
	int temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	v.push_back(l);

	sort(v.begin(), v.end()); 

	int left = 1, right = l;

	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;
		for (int i = 0; i <= n; i++) {
			sum += (v[i + 1] - v[i] - 1) / mid;
		}
		if (sum > m) {
			
			left = mid + 1;
		}
		else {
			answer = mid;
			right = mid - 1;
		}
		//cout << mid << " " << sum << endl;
	}
	
	
	cout << answer;

	return 0;
}