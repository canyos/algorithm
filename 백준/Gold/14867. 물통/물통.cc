#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
long long ll(int x, int y)
{
	return 1ll * x * 1000000 + y;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	unordered_map<long long,int> mp;
	queue < pair<int, int>> dq;
	int a, b, c, d,x=0,y=0;

	cin >> a >> b >> c >> d;
	
	dq.push({ 0, 0 });
	mp[0] = 1;

	while (!dq.empty())
	{
		pair<int, int> v = dq.front();
		long long temp = ll(v.first, v.second);
		dq.pop();
		//cout << v.first << " " << v.second << " " << mp[temp] << " " << temp << endl;
		if (v.first == c && v.second == d)
		{
			cout << mp[temp]-1;
			return 0;
		}
		
		if (v.first < a && !mp[ll(a,v.second)])
		{
			dq.push({ a,v.second });
			mp[ll(a, v.second)] = mp[temp] + 1;
		}
		if (v.second < b && !mp[ll(v.first, b)])
		{
			dq.push({ v.first,b });
			mp[ll(v.first, b)] = mp[temp] + 1;
		}
		if (v.first > 0 && v.second != b)
		{
			if (v.first - min(v.first, b - v.second) == 0 && !mp[ll(v.first - min(v.first, b - v.second), min(v.first + v.second, b))])
			{
				dq.push({ v.first - min(v.first,b - v.second),min(v.first + v.second,b) });
				mp[(ll(v.first - min(v.first, b - v.second), min(v.first + v.second, b)))] = mp[temp] + 1;
			}
			else
				if (!mp[ll(v.first - min(v.first, b - v.second), min(v.first + v.second, b))])
				{
					dq.push({ v.first - min(v.first,b - v.second),min(v.first + v.second,b) });
					mp[(ll(v.first - min(v.first, b - v.second), min(v.first + v.second, b)))] = mp[temp] + 1;
				}
					
		}
		if (v.second > 0 && v.first != a)
		{
			if (v.second - min(v.second, a - v.first) == 0 && !mp[ll(min(v.first + v.second, a), v.second - min(v.second, a - v.first))])
			{
				dq.push({ min(v.first + v.second,a),v.second - min(v.second,a - v.first) });
				mp[ll(min(v.first + v.second, a), v.second - min(v.second, a - v.first))] = mp[temp] + 1;
			}
				
			else
				if (!mp[ll(min(v.first + v.second, a), v.second - min(v.second, a - v.first))])
				{
					dq.push({ min(v.first + v.second,a),v.second - min(v.second,a - v.first) });
					mp[ll(min(v.first + v.second, a), v.second - min(v.second, a - v.first))]= mp[temp] + 1;
				}
					
		}
		if (v.first > 0 && !mp[ll(0, v.second)])
		{
			dq.push({ 0,v.second });
			mp[ll(0, v.second)] = mp[temp] + 1;
		}
		if (v.second > 0 && !mp[ll(v.first,0)])
		{
			dq.push({  v.first,0 });
			mp[ll(v.first, 0)] = mp[temp] + 1;
		}
	}
	
	cout << -1;
	
	
	return 0;
}