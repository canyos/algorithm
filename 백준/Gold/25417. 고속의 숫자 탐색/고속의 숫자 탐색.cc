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

int arr[5][5];
int R, C;
int answer = -1;
int visited[5][5];

int dr[] = { 0,0,-1,1 }, dc[] = { -1,1,0,0 };
bool checkPos(int r, int c) {
    return r >= 0 && r < 5 && c >= 0 && c < 5;
}

queue<tuple<int, int, int>> qu;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
            visited[i][j] = INF;
        }
            

    cin >> R >> C;

    qu.push({ R,C,0 });
    visited[R][C] = true;

    int r, c, cost;
    while (!qu.empty()) {
        tie(r, c, cost) = qu.front(); qu.pop();

        if (arr[r][c] == 1) {
            answer = cost;
            break;
        }
        if (r == 2 && c == 1 && cost == 2) {
            int a = 0;
        }

        for (int k = 0; k < 4; k++) {
            int tr = r + dr[k], tc = c + dc[k];
            if (checkPos(tr,tc)&& visited[tr][tc]>cost+1 && arr[tr][tc]!=-1) {
                qu.push({ tr,tc,cost + 1 });
                visited[tr][tc] = cost+1;
            }
        }

        for (int k = 0; k < 4; k++) {
            int rr = r+dr[k], cc = c+dc[k];
            while (checkPos(rr, cc) && (arr[rr][cc] ==0 || arr[rr][cc]==1)) {
                rr += dr[k], cc += dc[k];
            }
            if (!checkPos(rr, cc)|| arr[rr][cc]==-1)
                rr -= dr[k], cc -= dc[k];

            if (visited[rr][cc] > cost + 1 && arr[rr][cc] != -1) {
                qu.push({ rr,cc,cost + 1 });
                visited[rr][cc] = cost+1;
            }
        }
    }

    cout << answer;
}