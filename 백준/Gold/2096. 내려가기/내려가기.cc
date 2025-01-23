#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

long long n;
long long answer1, answer2;
int arr[100001][3];
int cur0, cur1, cur2;
int next0, next1, next2;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	cur0 = arr[0][0];
	cur1 = arr[0][1];
	cur2 = arr[0][2];

	for (int i = 1; i < n; i++) {
		next0 = max(cur0, cur1) + arr[i][0];
		next1 = max(max(cur0, cur1), cur2) + arr[i][1];
		next2 = max(cur2, cur1) + arr[i][2];

		cur0 = next0;
		cur1 = next1;
		cur2 = next2;
		int a = 0;
	}
	answer1 = max(max(cur0, cur1), cur2);

	cur0 = arr[0][0];
	cur1 = arr[0][1];
	cur2 = arr[0][2];

	for (int i = 1; i < n; i++) {
		next0 = min(cur0, cur1) + arr[i][0];
		next1 = min(min(cur0, cur1), cur2) + arr[i][1];
		next2 = min(cur2, cur1) + arr[i][2];

		cur0 = next0;
		cur1 = next1;
		cur2 = next2;
	}
	answer2 = min(min(cur0, cur1), cur2);
	cout << answer1 << " " << answer2;
	return 0;
}