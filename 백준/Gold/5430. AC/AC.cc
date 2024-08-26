#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
int T;
int result;


void process() {
	string p;
	int n;
	string strArr;
	deque<int>v;
	cin >> p >> n >> strArr;
	int temp = 0;
	if (n != 0) {
		for (int i = 1; strArr[i] != NULL; i++) {
			if (strArr[i] >= '0' && strArr[i] <= '9')temp = temp * 10 + strArr[i] - '0';
			else {
				v.push_back(temp);
				temp = 0;
			}
		}
	}
	

	bool isReverse = 0;
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == 'R') {
			isReverse = !isReverse;
		}
		else {
			if (v.size()==0) { cout << "error\n"; return; }
			if (isReverse)v.pop_back();
			else v.pop_front();
		}
	}

	cout << '[';
	int vsize = v.size();
	if (vsize == 0) {
		cout << "]\n";
	}
	else {
		if (isReverse == 0) {
			for (int i = 0; i < vsize - 1; i++) {
				cout << v[i] << ",";
			}
			cout << v[vsize - 1] << ']' << '\n';
		}
		else {
			for (int i = vsize - 1; i > 0; i--) {
				cout << v[i] << ",";
			}
			cout << v[0] << ']' << '\n';
		}
	}
	
	
	
}
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> T;
	for (int i = 0; i < T; i++) {
		process();
	}

	return 0;
}