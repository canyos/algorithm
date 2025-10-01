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

int n, answer=INF;
int arr[601];
vector<tuple<int, int, int>> v;

bool isNotDup(pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.first == p2.first) return false;
    if (p1.first == p2.second) return false;
    if (p1.second == p2.first) return false;
    if (p1.second == p2.second) return false;
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
        
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            v.push_back({ arr[i] + arr[j], i, j });
        }
    }
    sort(v.begin(), v.end());

    int sum1, a1, b1, sum2, a2, b2;
    for (int i = 0; i + 1 < v.size(); i++) {
        tie(sum1, a1, b1) = v[i];;
        tie(sum2, a2, b2) = v[i + 1];
        if (a1 != a2 && a1 != b2 && b1 != a2 && b1 != b2) {
            answer = min(answer, abs(sum2 - sum1));
        }
    }


    cout << answer;
    return 0;

}