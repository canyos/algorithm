#include <iostream>
#include <vector>
#include <string>
#include <queue>
//#include <stack>
#include <algorithm>
//#include <map>
using namespace std;

typedef long long ll;
bool graph[52][52] = { false };
vector<pair<char, char>> result;

char intToChar(int i) {
    if (i < 26) return 'A' + i;
    return 'a' + (i - 26);
}

int charToInt(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);    

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char start, end;
        string dummy;
        cin >> start >> dummy >> end;
        graph[charToInt(start)][charToInt(end)] = true;
    }

    for (int k = 0; k < 52; k++)
        for (int i = 0; i < 52; i++)
            for (int j = 0; j < 52; j++)
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = true;

    for (int i = 0; i < 52; i++)
        for (int j = 0; j < 52; j++)
            if (i != j && graph[i][j])
                result.push_back({ intToChar(i), intToChar(j) });

    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (auto& p : result)
        cout << p.first << " => " << p.second << '\n';

}