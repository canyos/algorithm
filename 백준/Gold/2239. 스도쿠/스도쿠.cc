#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

int arr[10][10];
bool isEnd = false;
void recursive(int r, int c) {
	if (isEnd)return;
	if (r == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j];
			}
			cout << '\n';
		}
		isEnd = true;
		return;
	}

	if (arr[r][c] != 0) {//이미 값이 적혀 있음
		if (c < 8)
			recursive(r, c + 1);
		else
			recursive(r + 1, 0);
		return;
	}

	for (int i = 1; i <= 9; i++) {
		bool exist = false;
		for (int rr = r / 3 * 3; rr < (r / 3 +1) *3 ; rr++) {
			for (int cc = c / 3 * 3; cc < (c / 3 + 1) * 3; cc++) {
				if (arr[rr][cc] == i) {
					exist = true;
					break;
				}
			}
			if (exist) break;
		}
		if (exist)continue;
		for (int k = 0; k < 9; k++) {
			if (arr[r][k] == i || arr[k][c] == i) {
				exist = true;
			}
			if (exist)	break;
		}
		if (exist)continue;
		
		if (r == 2 && c == 0) {
			int a = 0;
		}
		arr[r][c] = i;
		if (c < 8)
			recursive(r, c + 1);
		else
			recursive(r + 1, 0);
		arr[r][c] = 0;
	}
}

int main()
{
	string str;
	for (int i = 0; i < 9; i++) {
		cin >> str;
		for (int j = 0; j < 9; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	recursive(0, 0);
	
	

	return 0;
}