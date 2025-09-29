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

int n;
int arr[501][501];
bool visited[501][501];
int dp[501][501];

int dr[] = { 0,0,-1,1 }, dc[] = { -1,1,0,0 };
bool checkPos(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

int answer;

int dfs(int r, int c, int depth) {
    int ret = depth;

    for (int k = 0; k < 4; k++) {
        int tr = r + dr[k], tc = c + dc[k];
        
        if (!checkPos(tr, tc))continue;
        if (visited[tr][tc])continue;
        if (arr[r][c] >= arr[tr][tc])continue;

        if (dp[tr][tc]) {
            ret = max(ret, depth + dp[tr][tc]);
        }
        else {
            visited[tr][tc] = true;
            ret = max(ret, dfs(tr, tc, depth + 1));
            visited[tr][tc] = false;
        }
    }

    dp[r][c] = ret-depth+1;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = true;
            int ret = dfs(i, j, 1);
            answer = max(answer, ret);
            visited[i][j] = false;
        }
    }
    
    cout << answer;
    return 0;

}