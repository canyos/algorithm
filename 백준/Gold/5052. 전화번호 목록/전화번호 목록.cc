#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

int n, m, t;
string num;
unordered_map<string, bool> mp;

int main()
{

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		mp = {};
		bool sex = false;
		for (int j = 0; j < n; j++) {
			cin >> num;

			mp[num] = true;
		}

		for (auto it = mp.begin(); it != mp.end(); it++) {
			for (int k = 1; k < (*it).first.length(); k++) {
				if (mp[(*it).first.substr(0, k)])
					sex = true;
			}
		}


		if (sex)
			cout << "NO\n" ;
		else
			cout << "YES\n";
	}

	
	return 0;
}