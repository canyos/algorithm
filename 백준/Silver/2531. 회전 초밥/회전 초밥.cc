#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	int n, d, k, c;
	cin >> n >> d >> k >> c;

	vector<int>v;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		v.push_back(v[i]);
		if (v[i] == c)cnt++;
	}
	
	int left = 0, right = 1;
	unordered_map<int, int> mp;
	
	for (int i = 0; i < k; i++) {
		mp[v[i]]++;
	}
	int answer = mp.size();
	if (v[k] == c && !mp.count(v[k]))
		answer++;

	for (int i = 0; i < n; i++) {
		mp[v[i]]--;
		if (mp[v[i]] == 0)
			mp.erase(v[i]);
		mp[v[i + k]]++;
		if ( (v[i] == c && !mp.count(v[i])) || (i + k +1 < v.size() && v[i + k + 1] == c && !mp.count(v[i+ k + 1])) || (mp.count(c)==0 && cnt==0) )
			answer = max(answer, (int)mp.size() + 1);
		else 
			answer = max(answer, (int)mp.size());

		int a = 0;
	}

	
	cout << answer;

	return 0;
}