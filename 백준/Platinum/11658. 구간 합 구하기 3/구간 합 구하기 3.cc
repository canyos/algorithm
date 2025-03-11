#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
int seg[1<<11][1 << 11] ;
int n, m, w, c,p = 1024;;
void update1(int x, int y,int c)
{
	int k = seg[x + p][y + p] - c;
	for (int tx = x + p; tx >= 1; tx /= 2)
	{
		for (int ty = y + p; ty >= 1; ty /= 2)
		{
			seg[tx][ty] -= k;
		}
	}
}
int sum2(int x,int y1, int y2)
{
	int temp = 0;
	int ly = y1+p, ry = y2+p;
	while (ly <= ry)
	{
		if (ly % 2 == 1) { temp += seg[x][ly]; ly += 1; }
		if (ry % 2 == 0) { temp += seg[x][ry]; ry -= 1; }
		ly /= 2, ry /= 2;
	}
	return temp;
}
int sumx(int x1, int y1, int x2, int y2)
{
	int temp = 0;
	int lx = x1+p, rx = x2+p;
	while (lx <= rx)
	{
		if (lx % 2 == 1) { temp += sum2(lx,y1, y2); lx += 1; }
		if (rx % 2 == 0) { temp += sum2(rx,y1, y2); rx -= 1; }
		lx /= 2, rx /= 2;
	}
	return temp;
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int x1, x2, y1, y2;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)          //n^2
		for (int j = 0; j < n; j++)
			cin >> seg[i+p][j + p];

	for (int i = p; i <2*p; i++)
	{
		for (int j =p-1 ; j > 0; j--)
		{
			seg[i][j] = seg[i][j * 2] + seg[i][j * 2 + 1];
		}
	}
	for (int i = p - 1; i > 0; i--)//p^2 =100만
	{
		for (int j = 1;j<2*p; j++)
		{
			seg[i][j] = seg[i * 2][j] + seg[i * 2 + 1][j];
		}
	}
	
	for (int i = 0; i < m; i++)//m
	{
		cin >> w;
		if (w == 0)
		{
			cin >> x1 >> y1 >> c;
			update1(x1-1, y1-1, c);//log p;
		}
		else
		{
			cin >> x1 >> y1 >> x2 >> y2;
			cout << sumx(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << '\n';
		}
	}
	return 0;
}