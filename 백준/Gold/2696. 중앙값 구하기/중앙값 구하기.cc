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

int tc;
ll n, num;
int cnt;
priority_queue<ll> minHeap;
priority_queue<ll> maxHeap;
vector<ll> answer;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> tc;
    for (int t = 0; t < tc; t++) {
        cin >> n;

        cnt = 0;
        maxHeap = {};
        minHeap = {};
        answer = {};

        for (int i = 1; i <= n; i++) {
            cin >> num;
            if (i % 2)
                minHeap.push(-num);
            else
                maxHeap.push(num);

            while (!maxHeap.empty() && -minHeap.top() < maxHeap.top()) {
                int minNum = minHeap.top(); minHeap.pop();
                int maxNum = maxHeap.top(); maxHeap.pop();
                maxHeap.push(-minNum);
                minHeap.push(-maxNum);
            }

            if (i % 2) {
                answer.push_back(-minHeap.top());
            }
            
        }
        cout << n / 2 + n % 2 << endl;
        for (auto it : answer) {
            cnt++;
            cout << it << " ";
            if (cnt % 10 ==0 )
                cout << endl;
        }
        cout << endl;
    }
}