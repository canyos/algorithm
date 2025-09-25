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

int T, k;
int dp[501][501];
int file[501];
int sum[501];
int answer, num;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> k;
        //for (int i = 1; i < 501; i++)
        //    for (int j = i; j < 501; j++)
        //        dp[i][j] = INF;

        for (int i = 1; i <= k; i++) {
            cin >> file[i];
  
            sum[i] = sum[i-1] + file[i];
        }
        
        for (int sz = 1; sz <= k; sz++) {
            for (int i = 1; i <= k - sz ; i++) {
                int j = i + sz;

                dp[i][j] = INF;
                for (int a = i; a < j; a++) {
                    dp[i][j] = min(dp[i][j], dp[i][a] + dp[a + 1][j] + sum[j] - sum[i - 1]);
                }
            }
        }
        
        cout << dp[1][k] << endl;
    }

    return 0;

}