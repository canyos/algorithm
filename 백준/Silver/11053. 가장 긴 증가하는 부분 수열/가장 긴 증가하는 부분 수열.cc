#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v(1001);
int n;
int arr[1001];
int result;

void input() {
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++)
		cin >> v[i];
}

int main() {
	input();
	result = arr[0] = 1;
	for (int i = 1; i < n; i++) {
		arr[i] = 1;
		for (int j = i-1; j >=0; j--){
			if (v[j] < v[i]) {
				arr[i] = max(arr[j] + 1, arr[i]);
				if (result < arr[i])result = arr[i];
			}
		}
	}
	//for (int i = 0; i < n; i++) {
	//	cout << i << ":" << arr[i] << '\n'; 
	//}
	cout << result;
	return 0;
}