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
			temp = max(temp, box[i]);//배송 구간 중 최대 실린 무게

		int left = min(c - temp,it[2]); // (용량-최대무게, 현재 무게) 중 작은거 고름 -> 더 실을 수 있는 무게
		answer += left; // 무게를 담음
		//cout << answer;
		for (int i = it[0]; i < it[1]; i++)
			box[i] += left; //해당 구간동안 배송하도록 함

		
	}
	cout << answer;
	return 0;
}
