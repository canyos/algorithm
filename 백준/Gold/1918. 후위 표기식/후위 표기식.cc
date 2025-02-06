#pragma warning(disable: 4996)

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <queue>
#include <unordered_map>
#include <stack>
#include <unordered_set>
using namespace std;

string str;

void input()
{
	cin >> str;
}

string recursive(string str) {
	deque<string>dq;
	string answer = "";
	for (int i = 0; i < str.length(); i++) {
		string cur = "";
		cur += str[i];
		bool flag = false;
		if (!dq.empty() && dq.back() == "(") {
			int cnt1 = 1, cnt2 = 0;
			dq.pop_back();
			int idx=i;
			string temp = "";
			while (true) {
				if (str[idx] == '(')cnt1++;
				if (str[idx] == ')')cnt2++;
				if (cnt1 == cnt2)break;
				temp += str[idx++];
			}
			dq.push_back(recursive(temp));
			i = idx;
			flag = true;
		}
		if (flag && dq.size()>=3) {
			string third = dq.back(); dq.pop_back();
			string second = dq.back(); dq.pop_back();
			string first = dq.back(); dq.pop_back();
			if (second == "*" || second == "/")
				dq.push_back(first + third + second);
			else {
				dq.push_back(first);
				dq.push_back(second);
				dq.push_back(third);
			}
		}
		else if (!dq.empty() && cur != "(" && (dq.back() == "*" || dq.back() == "/")) {
			string y = dq.back(); dq.pop_back();//연산자
			string p = dq.back(); dq.pop_back();//피연산자

			dq.push_back(p + cur + y);
		}
		else if(!flag){
			dq.push_back(cur);
		}
	}

	while (dq.size() != 1) {
		string first = dq.front(); dq.pop_front();
		string second = dq.front(); dq.pop_front();
		string third = dq.front(); dq.pop_front();

		dq.push_front(first + third + second);
	}
	return dq.front();
}

int main() {
	cin.tie(NULL); //입출력 묶음 해제
	ios_base::sync_with_stdio(false);

	input();

	cout << recursive(str);

	return 0;
}