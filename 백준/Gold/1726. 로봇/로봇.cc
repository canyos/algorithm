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

#define right 1
#define left 2
#define down 3
#define up 4

int n, m;
int arr[101][101];
int r, c, dir, cost;
int R, C, DIR;
int visited[101][101][5];
int answer;

int turnLeft(int cur) {
    if (cur == right)return up;
    if (cur == up)return left;
    if (cur == left) return down;
    if (cur == down)return right;
}
int turnRight(int cur) {
    if (cur == right)return down;
    if (cur == down)return left;
    if (cur == left)return up;
    if (cur == up)return right;
}


int dr[] = { 0,0,0,1,-1 }, dc[] = { 0,1,-1,0,0 };
bool checkPos(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

queue<tuple<int, int, int, int>> qu;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    cin >> r >> c >> dir;
    cin >> R >> C >> DIR;
    
    r--, c--, R--, C--;

    qu.push({ r,c,dir,1 });
    visited[r][c][dir] = 1;

    while (!qu.empty()) {
        tie(r, c, dir,cost) = qu.front(); qu.pop();
        if (r == R && c == C && dir == DIR) {
            answer = cost;
            break;
        }

        for (int k = 1; k <= 3; k++) {
            int tr = r + dr[dir]*k, tc = c + dc[dir]*k;
            if (!checkPos(tr, tc) || arr[tr][tc] == 1)break;
            if (!visited[tr][tc][dir]) {
                qu.push({ tr,tc,dir,cost+1 });
                visited[tr][tc][dir] = cost+1;
            }
        }

        int nDir = turnLeft(dir);
        if (!visited[r][c][nDir]) {
            qu.push({ r,c,nDir,cost+1 });
            visited[r][c][nDir] = cost+1;
        }

        nDir = turnRight(dir);
        if (!visited[r][c][nDir]) {
            qu.push({ r,c,nDir,cost + 1 });
            visited[r][c][nDir] = cost+1;
        }
    }


    cout << answer-1;
    return 0;
}