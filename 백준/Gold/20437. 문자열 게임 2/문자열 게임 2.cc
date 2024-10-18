#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
int T, K;
string W;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		int m = 10001, M = -1;
		cin >> W >> K;
		vector<int>arr[26];
		for (int i = 0; i < W.length();i++) {
			arr[W[i] - 'a'].push_back(i);
			int sz = arr[W[i] - 'a'].size();
			if (sz >= K) {
				m = min(m, arr[W[i] - 'a'][sz - 1] - arr[W[i] - 'a'][sz - K]);
				M = max(M, arr[W[i] - 'a'][sz - 1] - arr[W[i] - 'a'][sz - K]);
			}
		}
		if (m == 10001) 
			cout << -1 << '\n';
		
		else 
			cout << m+1 << " " << M+1 << '\n';
	}

	
	return 0;
}