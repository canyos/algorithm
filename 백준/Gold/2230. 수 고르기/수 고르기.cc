#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <string>
#include <set>
#include <map>

using namespace std;
vector<int> v;

int n, m;
int answer = 2000000001;

int main()
{
	cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	int index = 1;

	for (int i = 0; i < n-1; i++) {
		while (index<n && v[index] - v[i] < m)
			index++;
		if (index >= n)break;
		answer = min(answer, v[index] - v[i]);
	}

	cout << answer;
	return 0;
}