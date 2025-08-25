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
unordered_map<int, int> mp;
int num;
int answer;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        mp[num] = max(mp[num - 1] + 1, 1);
        answer = max(answer, mp[num]);
    }
        
    cout << n - answer;

}