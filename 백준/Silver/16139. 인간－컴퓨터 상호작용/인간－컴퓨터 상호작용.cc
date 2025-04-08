#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <string>

typedef long long ll;
using namespace std;

string str;
int q;
char c;
int s, e;

int arr[200001][26];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> str;
	cin >> q;
	arr[0][str[0] - 'a']++;

	int len = str.length();
	for (int i = 1; i < len; i++) {
		for (int j = 0; j < 26; j++) {
			arr[i][j] = arr[i - 1][j];
		}
		arr[i][str[i] - 'a']++;
	}


	for (int i = 0; i < q; i++) {
		cin >> c >> s >> e;
		if (s == 0)
			cout << arr[e][c - 'a'] << '\n';
		else
			cout << arr[e][c - 'a'] - arr[s - 1][c - 'a'] << '\n';
	}

	return 0;
}