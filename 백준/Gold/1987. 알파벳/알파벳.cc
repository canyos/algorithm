#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[21][21];
bool visited2[26];
int r, c, answer;
int tx[4] = { 0,0,-1,1 }, ty[4] = { -1,1,0,0 };
char alpha[21][21];

bool check(int x, int y)
{
	return !(x < 0 || x >= r || y < 0 || y >= c);
}

void dfs(int x, int y,int st)
{
	visited[x][y] = 1;
	visited2[alpha[x][y]-'A'] = 1;
	//cout << alpha[x][y]<<" " <<  st << endl;
	answer = max(answer, st);
	for (int i = 0; i < 4; i++)
	{
		if (check(x + tx[i], y + ty[i]) && !visited[x + tx[i]][y + ty[i]] && !visited2[alpha[x + tx[i]][y + ty[i]] - 'A'])
		{
			dfs(x + tx[i], y + ty[i],st+1);
		}
	}
	visited2[alpha[x][y] - 'A'] = 0;
	visited[x][y] = 0;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> alpha[i];
	}
	
	dfs(0, 0,1);
	cout << answer;
	return 0;
}