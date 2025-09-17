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
char str[200001];
int answer;
int start[200001];//올바르면 왼쪽 어디인지
int dp[200001];//idx까지의 길이

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n ;
    for (int i = 0; i < n; i++)
        cin >> str[i];

    for (int i = 1; i < n; i++) {
        if (str[i] == ')') {
            if (str[i - 1] == '(') {
                //바로 닫힘 
                start[i] = i - 1;
                dp[i] = 2;
                
                //i-2랑 연결
                if (i - 2 >= 0 && dp[i - 2] > 0) {
                    start[i] = start[i - 2];
                    dp[i] = dp[i - 2] + 2;
                }
            }
            else {
                //앞에거 포함해서 되는지 체크해야함
                int checkIdx = start[i - 1] - 1;
                if (checkIdx >= 0 && str[checkIdx] == '(') {
                    start[i] = checkIdx;
                    dp[i] = dp[i - 1] + 2;

                    if (checkIdx - 1 >= 0 && dp[checkIdx-1] > 0) {
                        start[i] = start[checkIdx - 1];
                        dp[i] = dp[i] +dp[checkIdx-1];
                    }
                }
            }
            answer = max(answer, dp[i]);
        }
    }


    cout << answer;
    return 0;

}
/*
10
(()(())())
*/