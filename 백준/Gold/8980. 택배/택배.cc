#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int box[2001];
bool compare(const vector<int>&v1, const vector<int>&v2)
{
	bool s = 0;
	if (v1[1] < v2[1])
		s = 1;
	else if (v1[1] == v2[1])
	{
		if (v1[0] < v2[0])
			s = 1;
	}
	return s;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, c, m, x, y, w,answer=0;
	vector<vector<int>> v;
	cin >> n >> c;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y >> w;
		v.push_back({ x,y,w });
	}

	sort(v.begin(), v.end(), compare);
	
	for (auto it : v)
	{
		int temp = 0;
		for (int i = it[0]; i < it[1]; i++)
			temp = max(temp, box[i]);

		int left = min(c - temp,it[2]);
		answer += left;
		//cout << answer;
		for (int i = it[0]; i < it[1]; i++)
			box[i] += left;

		
	}
	cout << answer;
	return 0;
}