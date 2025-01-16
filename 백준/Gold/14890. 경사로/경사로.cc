#include <iostream>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
using namespace std;

int n, l;
int arr[101][101];
int arr2[101][101];
int answer = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> l;

	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			arr[i][j] = arr2[j][i] = temp;
		}
	}
		
			
	for (int i = 0; i < n; i++) {
		int height = arr[i][0], cnt = 1;
		bool add = true;
		for (int j = 1; j < n; j++) {
			if (arr[i][j] == height) {
				cnt++;
			}
			else if (arr[i][j] == height + 1) {// 1높아진곳으로갈 때
				if (cnt < l) {
					add = false;
					break;
				}
				height++;
				cnt = 1;
			}
			else if (arr[i][j] == height - 1) {
				bool a = true;
				for (int k = j+1; k < j + l; k++) {
					if (arr[i][k] != arr[i][j]) {
						a = false;
						break;
					}
				}
				if (a) {
					height--;
					j += (l - 1);
					cnt = 0;
				}
				else {
					add = false;
					break;
				}
					
			}
			else {
				add = false;
				break;
			}
		}
		if (add)
			answer++;
	}
	
	for (int i = 0; i < n; i++) {
		int height = arr2[i][0], cnt = 1;
		bool add = true;
		for (int j = 1; j < n; j++) {
			if (arr2[i][j] == height) {
				cnt++;
			}
			else if (arr2[i][j] == height + 1) {// 1높아진곳으로갈 때
				if (cnt < l) {
					add = false;
					break;
				}
				height++;
				cnt = 1;
			}
			else if (arr2[i][j] == height - 1) {
				bool a = true;
				for (int k = j + 1; k < j + l; k++) {
					if (arr2[i][k] != arr2[i][j]) {
						a = false;
						break;
					}
				}
				if (a) {
					height--;
					j += (l - 1);
					cnt = 0;
				}
				else {
					add = false;
					break;
				}

			}
			else {
				add = false;
				break;
			}
		}
		if (add)
			answer++;
	}

	cout << answer;
}