#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string>
#include <cstring>
#include <bitset>
#include <vector>
#include <map>
#define endl "\n"
using namespace std;
typedef long long ll;
const ll INF = 1e9;

int n, m, k;
char arr[101][101];
int answer;
string str;
int len;
int dp[101][101][100];

int dr[] = { 0,0,-1,1 }, dc[] = { -1,1,0,0 };
bool checkPos(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

int dfs(int r, int c, int idx) {
    if (dp[r][c][idx] != -1)return dp[r][c][idx];
    if (idx >= len)return 1;

    dp[r][c][idx] = 0;

    for (int dir = 0; dir < 4; dir++) {
        for (int a = 1; a <= k; a++) {
            int tr = r + dr[dir] * a, tc = c + dc[dir] * a;
            if (checkPos(tr,tc) && arr[tr][tc] == str[idx]) {
                dp[r][c][idx] += dfs(tr, tc, idx + 1);
            }
        }
    }
    return dp[r][c][idx];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    cin >> str;
    len = str.length();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l <= len; l++) {
                dp[i][j][l] = -1;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (str[0] == arr[i][j]) {
                answer+=dfs(i, j, 1);
            }
        }
    }

    cout << answer;
    return 0;
}