#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
bool digit[10][7] = {
	{1,1,1,1,1,1,0},
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};

int n, k, p, x;
int result;
int transition[10][10];//1번째 숫자가 2번째 숫자로 변형하는데 필요한 반전 개수

void input() {
	cin >> n >> k >> p >> x;
}


void cntDiff() {
	for (int i = 0; i <= 8; i++) {
		for (int j = i; j <= 9; j++) {
			int cnt = 0;
			for (int k = 0; k < 7; k++) {
				cnt += (digit[i][k] != digit[j][k]);//다른거 개수셈
			}
			transition[i][j] = cnt;
			transition[j][i] = cnt;
		}
	}
}
int len(int n) {
	int cnt = 0;
	while (n > 0) {
		cnt++;
		n /= 10;
	}
	return cnt;
}

vector<int> number;
void cntMake(int num) {
	if (x == num)return;
	vector<int> curr = {};
	int cnt = 0;
	while (num > 0) {
		curr.push_back(num % 10);
		num /= 10;
		cnt++;
	}
	for (int i = 0; i < k-cnt; i++)
		curr.push_back(0);
	reverse(curr.begin(), curr.end());

	/*for (auto it : curr)
		cout << it;
	cout << endl;
*/
	cnt = 0;
	for (int i = 0; i < number.size(); i++) {
		//cout << number[i] << " " << curr[i] << " " <<transition[number[i]][curr[i]] << endl;
		cnt += transition[number[i]][curr[i]];
	}
	/*for (auto it : curr)
		cout << it;
	cout << " " << cnt << endl;*/
	if (cnt <= p) {
		
		result++;
	}
}

void process() {
	int padding = k-len(x);
	int temp = x;
	while (temp > 0) {
		number.push_back(temp % 10);
		temp /= 10;
	}
	for (int i = 0; i < padding; i++)
		number.push_back(0);

	reverse(number.begin(), number.end());
	
	for (int i = 1; i <= n; i++) {
		cntMake(i);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	cntDiff();

	process();
	/*for (auto it : st) {
		cout << it << " ";
	}*/
	/*for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << transition[i][j] << " ";
		}
		cout << endl;
	}*/
		
	cout << result;
	return 0;
}