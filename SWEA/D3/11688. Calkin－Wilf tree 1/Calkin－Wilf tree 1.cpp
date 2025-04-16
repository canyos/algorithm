#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <string>

typedef long long ll;
using namespace std;

pair<int,int> recursive(ll n) {
	if (n == 1) {
		return { 1,1 };
	}

	pair<int, int> res = recursive(n / 2);
	int a, b;
	if (n % 2 == 1) 
		a= res.first + res.second ,b= res.second ;
	else 
		a = res.first, b = res.first + res.second;
	
	return { a,b };
}

pair<int, int> uc(pair<int, int>& p) {
	int a = p.first, b = p.second;
	if (a >= b) {
		while (b != 1) {
			int temp = a % b;
			a = b;
			b = temp;
		}
	}
	else {
		while (a != 1) {
			int temp = b % a;
			b = a;
			a = temp;
		}
	}
	return { a,b };
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		string str;
		cin >> str;
		ll temp = 1ll;
		for (char s : str) {
			if (s == 'L')temp *= 2;
			else temp = temp * 2 + 1;
		}

		pair<int, int> res = recursive(temp);
		
		cout << "#" << t<< " " << res.first << " " << res.second << "\n";
	}

	return 0;
}