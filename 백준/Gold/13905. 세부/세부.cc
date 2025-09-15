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

int n, m, s, e, answer;
vector<pair<int,int>> edges[100001];
int dist[100001];
priority_queue<pair<int, int>> pq;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> s >> e;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edges[a].push_back({ b,c });
        edges[b].push_back({ a,c });
    }
    
    pq.push({ INF, s });
    //fill(dist, dist + 100001, INF);

    int value, cur, value2, next;
    while (!pq.empty()) {
        tie(value, cur) = pq.top(); pq.pop();

        for (auto edge : edges[cur]) {
            tie(next, value2) = edge;

            int nextValue = min(value, value2);
            if (nextValue > dist[next]) {
                pq.push({ nextValue , next });
                dist[next] = nextValue;
            }
        }
    }

    cout << dist[e];
    return 0;
}