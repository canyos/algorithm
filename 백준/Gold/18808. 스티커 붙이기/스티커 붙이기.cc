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
int arr[41][41];//전체지도
pair<int, int> sz[101][4];//스티커 크기
int sticker[101][4][11][11];//스티커
int R, C;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> R >> C;

        sz[i][0] = sz[i][2] = { R,C };
        sz[i][1] = sz[i][3] = { C,R };

        for (int a = 0; a < R; a++) {
            for (int b = 0; b < C; b++) {
                cin >> sticker[i][0][a][b];  // 0번째: 원본
            }
        }

        // 90도 회전
        for (int a = 0; a < C; a++) {
            for (int b = 0; b < R; b++) {
                sticker[i][1][a][b] = sticker[i][0][R - 1 - b][a];
            }
        }

        // 180도 회전
        for (int a = 0; a < R; a++) {
            for (int b = 0; b < C; b++) {
                sticker[i][2][a][b] = sticker[i][0][R - 1 - a][C - 1 - b];
            }
        }

        // 270도 회전
        for (int a = 0; a < C; a++) {
            for (int b = 0; b < R; b++) {
                sticker[i][3][a][b] = sticker[i][0][b][C - 1 - a];
            }
        }
    }

    for (int idx = 0; idx < k; idx++) {
        bool isEnableSticker = false;

        for (int rotate = 0; rotate < 4; rotate++) {
            tie(R, C) = sz[idx][rotate];

            for (int i = 0; i <= n-R; i++) {
                for (int j = 0; j <= m-C; j++) {

                    bool isPossible = true;
                    for (int r = 0; r < R; r++) {
                        for (int c = 0; c < C; c++) {
                            if (sticker[idx][rotate][r][c] && arr[i + r][j + c]) {
                                isPossible = false;
                                break;
                            }
                        }
                        if (!isPossible)break;
                    }

                    //가능하다면 맵에 저장
                    if (isPossible) {
                        for (int r = 0; r < R; r++) {
                            for (int c = 0; c < C; c++) {
                                arr[i + r][j + c] = arr[i + r][j + c] | sticker[idx][rotate][r][c];
                            }
                        }
                        isEnableSticker = true;
                    }
                    if (isEnableSticker)break;
                }
                if (isEnableSticker)break;
            }
            if (isEnableSticker)break;
        }        
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j]) cnt++;
        }
    }

    cout << cnt;
    return 0;
}