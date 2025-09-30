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

int n, cnt;
int par[51];
priority_queue<tuple<int, int, int>> pq;
char ch;

int toInt(char ch) {
    if ('a' <= ch && ch <= 'z')
        return ch - 'a' + 1;
    else
        return ch - 'A' + 27;
}

int find(int a) {
    if (par[a] == a)
        return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x != y) {
        par[x] = y;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        par[i] = i;
        for (int j = 0; j < n; j++) {
            cin >> ch;
            if(ch != '0')
                pq.push({ -toInt(ch),i,j });
        }
    }

    int cost, a, b, answer=0;
    while (!pq.empty()) {
        tie(cost, a, b) = pq.top(); pq.pop();
        cost = -cost;

        if (find(a) != find(b)) {
            merge(a, b);
            cnt++;
        }
        else {
            answer += cost;
        }
    }

    if (cnt != n - 1)
        cout << -1;
    else
        cout << answer;
    return 0;

}