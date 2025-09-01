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
int from, dest;
vector<int> edges[3001];
vector<int> dist(3001, INF);
bool visited[3001];
bool isCycle[3001];
int a;
queue<int> qu;
//1부터 dfs함
//dfs하다가 이미 방문한거(a) 나오면 백트래킹
//a가 다시 나올때까지 계속 사이클 체크하고 백트래킹

void dfs(int cur,int prev) {
    if (visited[cur]) {
        a = cur;
        isCycle[cur] = true;
        return;
    }

    for (auto next : edges[cur]) {
        if (next == prev)continue;

        visited[cur] = true;
        dfs(next,cur);
        if (cur == a) {
            a = 0;
            return;
        }
        if (a != 0) {
            isCycle[cur] = true;
            return;
        }
        
        visited[cur] = false;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> from >> dest;
        edges[from].push_back(dest);
        edges[dest].push_back(from);
    }


    //1부터 3천까지 모든 노드에 대해 bfs해서 체크해도 2초 안나올듯
    dfs(1, 0);

    fill(visited, visited + 3001, false);

    for (int i = 1; i <= 3000; i++) {
        if (isCycle[i]) {
            qu.push(i);
            dist[i] = 0;
            visited[i] = true;

            while (!qu.empty()) {
                int cur = qu.front(); qu.pop();
                for (int next : edges[cur]) {
                    if (!isCycle[next] && !visited[next]) {
                        qu.push(next);
                        dist[next] = dist[cur] + 1;
                        visited[next] = true;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}