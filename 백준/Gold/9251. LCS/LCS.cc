#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int arr[1001][1001];
string str1, str2;
int result;

void input() {
	cin >> str1 >> str2;
}

int main() {
	input();
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < str1.length(); i++) {
		for (int j = 0; j < str2.length(); j++) {
			if (str1[i] == str2[j]) arr[i + 1][j + 1] = arr[i][j] + 1;
			else arr[i + 1][j + 1] = max(arr[i + 1][j], arr[i][j + 1]);
		}
		
	}

	cout << arr[str1.length()][str2.length()];
	return 0;
}