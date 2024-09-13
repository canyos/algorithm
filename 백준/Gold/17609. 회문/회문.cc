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
int n;
string strs[31];
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> strs[i];
	}
}
string substr(string& str, int left, int right) {
	string temp = "";
	for (int i = left; i <= right; i++) {
		temp += str[i];
	}
	return temp;
}
int substrPal(string& str) {
	int left = 0, right = str.length() - 1;
	while (left <= right) {
		if (str[left] == str[right]) 
			left++, right--;
	    else
			return 1;
	}
	return 0;
}

int isPalindrome(string& str) {
	int left = 0, right = str.length() - 1;
	while (left <= right) {
		if (str[left] == str[right]) {
			left++; 
			right--;
		}
		else {
			string sub1 = substr(str, left+1, right);//왼쪽 한개 지움
			string sub2 = substr(str, left, right-1); //오른쪽 한개 지움
			//cout << sub1 << " " << substrPal(sub1) << " " << sub2 << " " << substrPal(sub2) << endl;
			if (!substrPal(sub1) || !substrPal(sub2))
				return 1;
			else
				return 2;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	input();
	//string str = "str";
	//cout << str.substr(0, str.length()-1);
	for (int i = 0; i < n; i++) {
		cout << isPalindrome(strs[i]) << '\n';
	}
	return 0;
}