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
int from;
vector<int> edges[501];
int inCnt[501];
queue<int> qu;
int sum[501];
int cost[501];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        while (true) {
            cin >> from;
            if (from == -1)break;
            inCnt[i]++;
            edges[from].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (inCnt[i] == 0) {
            qu.push(i);
            sum[i] = cost[i];
        }
    }

    while (!qu.empty()) {
        auto cur = qu.front(); qu.pop();
        for (int next : edges[cur]) {
            inCnt[next]--;
            sum[next] = max(sum[next], sum[cur] + cost[next]);
            if (inCnt[next] == 0) {
                qu.push(next);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << sum[i] << endl;
    }

    return 0;
}