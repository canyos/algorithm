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
int arr[100001];
int sum[100001];
ll dp[5];
int cnt0, base;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
        if (sum[i] == 0) cnt0++;
    }
    if (sum[n] == 0) {
        if (cnt0 < 4) cout << "0";
        else cout<<  1ll*(cnt0 - 1) * (cnt0 - 2) * (cnt0 - 3) / 6;
        return 0;
    }
    if (sum[n] % 4) {
        cout << "0";
        return 0;
    }
    base = sum[n] / 4;

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        if (sum[i] % base) continue;
        int j = sum[i] / base;
        if (j == 0 || j > 3) continue;
        dp[j] += dp[j - 1];
    }
    cout << dp[3];
}