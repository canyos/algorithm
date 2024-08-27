#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>

using namespace std;
int n;
int MAX, MIN=999999999;
queue<pair<int, int>> qu; // {지금 숫자, 몇개 홀수봤는지} 저장

void input() {
	cin >> n;
}

int cntOdd(int num) {
	int temp = 0;
	while (num > 0) {
		temp += (num % 10) % 2;
		num /= 10;
	}
	return temp;
}
int cntLen(int num) {
	int temp = 0;
	while (num > 0) {
		temp++;
		num /= 10;
	}
	return temp;
}

int pow10(int num) {
	int temp = 1;
	while (num > 0) {
		temp *= 10;
		num--;
	}
	return temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	
	qu.push({ n, cntOdd(n) });

	while (!qu.empty()) {
		auto v = qu.front();
		qu.pop();
		int num = v.first, cnt = v.second;
		if (num >= 100) {
			int length = cntLen(num);
			for (int i = 1; i <= length-2; i++) {
				for (int j = 1; j <= length - 2; j++) {
					for (int k = 1; k <= length - 2; k++) {
						if (i + j + k != length)continue;
						int d1, d2, d3;
						d3 = num % pow10(k);
						d2 = num / pow10(k) % pow10(j);
						d1 = num / pow10(k) / pow10(j);
						qu.push({ d1 + d2 + d3 , cnt + cntOdd(d1 + d2 + d3) });
					}
				}
			}
		}
		else if (num >= 10) {
			qu.push({ num / 10 + num % 10,cnt + cntOdd(num / 10 + num % 10)});
		}
		else {
			if (cnt > MAX)MAX = cnt;
			if (cnt < MIN)MIN = cnt;
		}
	}

	cout << MIN << " " << MAX;

	return 0;
}