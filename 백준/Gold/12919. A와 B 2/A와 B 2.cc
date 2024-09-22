#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
string str1, str2;
string str3 = "";
stack<string> st;

bool equalString(string& str1, string& str2) {
	if (str1.length() != str2.length())return false;
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);    

	cin >> str1 >> str2;
	for (int i = str2.length() - 1; i >= 0; i--) {
		str3 += str2[i];
	}

	st.push(str1);
	while (!st.empty()) {
		auto cur = st.top(); st.pop();
		if (equalString(cur,str2)) {
			cout << 1;
			return 0;
		}
		if (cur.length() > str2.length())continue;
		if (str2.find(cur) > str2.length() && str3.find(cur) > str3.length()) continue;

		string temp1 = cur + "A";
		string temp2 = cur + "B";
		reverse(temp2.begin(), temp2.end());
		
		st.push(temp2);
		st.push(temp1);
		
	}
	cout << 0;
	return 0;

}