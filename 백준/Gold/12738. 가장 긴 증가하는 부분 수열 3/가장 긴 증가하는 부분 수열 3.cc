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
int arr[1'000'001];
vector<int> v;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int num = arr[i];
        auto it = lower_bound(v.begin(), v.end(), num);
        if (it == v.end()) {
            v.push_back(num);
        }
        else {
            *it = num;
        }
    }

    cout << v.size();
    return 0;
}