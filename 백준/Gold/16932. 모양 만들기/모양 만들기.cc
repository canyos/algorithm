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

int n, m;
int arr[1001][1001];
int blockNum[1001][1001];
queue<pair<int, int>> qu;
int answer;
bool visited[1001][1001];
bool blockVisited[500001];
int sz[500001];
int dr[] = { 0,0,-1,1 }, dc[] = { -1,1,0,0 };
int r, c, idx;
bool checkPos(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockNum[i][j])continue;
            if (arr[i][j] == 1) {
                idx++;
                int cnt = 1;
                qu.push({ i,j });
                blockNum[i][j] = idx;
                visited[i][j] = true;

                while (!qu.empty()) {
                    tie(r,c) = qu.front(); qu.pop();
                    for (int k = 0; k < 4; k++) {
                        int tr = r + dr[k], tc = c + dc[k];
                        if (checkPos(tr, tc) && !visited[tr][tc] && arr[tr][tc]==1) {
                            qu.push({ tr,tc });
                            visited[tr][tc] = true;
                            blockNum[tr][tc] = idx;
                            cnt++;
                        }
                    }
                }
                sz[idx] = cnt;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                int sum = 1;
                for (int k = 0; k < 4; k++) {
                    int tr = i + dr[k], tc = j + dc[k];
                    if (!checkPos(tr, tc))continue;
                    int num = blockNum[tr][tc];

                    if (num && !blockVisited[num]) {
                        sum += sz[num];
                        blockVisited[num] = true;
                    }
                }
                answer = max(answer, sum);
                for (int k = 0; k < 4; k++) {
                    int tr = i + dr[k], tc = j + dc[k];
                    if (!checkPos(tr, tc))continue;
                    int num = blockNum[tr][tc];
                    blockVisited[num] = false;;
                }
            }
        }
    }

    cout << answer;

    return 0;
}