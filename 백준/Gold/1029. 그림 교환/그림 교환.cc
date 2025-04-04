#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <string>

typedef long long ll;
using namespace std;

int n;
vector<pair<int,int>> edges[16];
int dp[16][1<<16][16];//길이, 비트마스킹, 현재위치일 때 최소 가격
int answer = 1;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			edges[i].push_back({j, str[j] - '0' });
		}
	}

	for (int i = 1; i < n; i++) 
		for (int b = 1; b < (1 << n); b++) 
			for (int k = 0; k < n; k++) 
				dp[i][b][k] = 10;//미방문처리

	dp[1][1][0]= 0;
	
	for (int i = 1; i < n; i++) {//길이
		for (int b = 1; b < (1 << n); b++) {//비트
			for (int k = 0; k < n; k++) {//현재위치
				if (dp[i][b][k]!=10) {//방문했는지
					for (auto next : edges[k]) {//다음위치
						if (dp[i][b][k] <= next.second && !((1<<next.first)&b)) {//내가 산 비용보다 크거나 같고 방문한적없음
							answer = i + 1;
							dp[i + 1][b | (1 << next.first)][next.first] = min(next.second, dp[i + 1][b | (1 << next.first)][next.first]);
						}
					}
				}
			}
		}
	}

	cout << answer;
	return 0;
}