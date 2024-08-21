#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int arr[51];
int N;
int result;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

int main() {
	input();
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < N; i++) {
		int temp = 0;
		double last = -99999999999.0;
		for (int j = i - 1; j >= 0; j--) {
			double d = 1.0 * (arr[i] - arr[j]) / (j - i);
			if (d > last) {
				last = d;
				temp++;
			}
		}
		// << temp << endl;
		last = -999999999999.0;
		for (int j = i + 1; j < N; j++) {
			double d = 1.0 * (arr[j] - arr[i]) / (j - i);
			if (d > last) {
				last = d;
				temp++;
			}
		}
		//cout << temp << endl;
		result = max(result, temp);
	}
	cout << result;
	return 0;
}