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
		if (v.first == c && v.second == d)//같으면 출력
		{
			cout << mp[temp]-1;
			return 0;
		}
		
		if (v.first < a && !mp[ll(a,v.second)]) //a를 채울 수 있으면 채움
		{
			dq.push({ a,v.second });
			mp[ll(a, v.second)] = mp[temp] + 1;
		}
		if (v.second < b && !mp[ll(v.first, b)]) //b를 채울 수 있으면 채움
		{
			dq.push({ v.first,b });
			mp[ll(v.first, b)] = mp[temp] + 1;
		}
		if (v.first > 0 && v.second != b)//(a->b로 이동할 거임)
		{
			if (v.first - min(v.first, b - v.second) == 0 && !mp[ll(v.first - min(v.first, b - v.second), min(v.first + v.second, b))]) //a에 b의 빈 공간보다 물이 더 많음
			{
				dq.push({ v.first - min(v.first,b - v.second),min(v.first + v.second,b) }); 
				mp[(ll(v.first - min(v.first, b - v.second), min(v.first + v.second, b)))] = mp[temp] + 1;
			}
			else //b에 공간이 더 적음
				if (!mp[ll(v.first - min(v.first, b - v.second), min(v.first + v.second, b))])
				{
					dq.push({ v.first - min(v.first,b - v.second),min(v.first + v.second,b) });
					mp[(ll(v.first - min(v.first, b - v.second), min(v.first + v.second, b)))] = mp[temp] + 1;
				}
					
		}
		if (v.second > 0 && v.first != a) b->a로 이동할 거임
			
		{
			if (v.second - min(v.second, a - v.first) == 0 && !mp[ll(min(v.first + v.second, a), v.second - min(v.second, a - v.first))]) //b에 a의 빈 공간보다 양이 많음
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
		if (v.first > 0 && !mp[ll(0, v.second)]) //a를 버림
		{
			dq.push({ 0,v.second });
			mp[ll(0, v.second)] = mp[temp] + 1;
		}
		if (v.second > 0 && !mp[ll(v.first,0)]) //b를 버림
		{
			dq.push({  v.first,0 });
			mp[ll(v.first, 0)] = mp[temp] + 1;
		}
	}
	
	cout << -1;
	
	
	return 0;
}
