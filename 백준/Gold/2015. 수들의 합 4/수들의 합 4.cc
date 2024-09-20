#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
int n, k;
ll arr[200001];
map<ll, ll> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	ll cnt = 0;
	ll temp = 0, sum=0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		sum += temp;
		arr[i] = sum;
		if (arr[i] == k) cnt++;
	}


	for (int i = 0; i < n; i++) {
		cnt += mp[arr[i] - k];
		mp[arr[i]]++;
	}
	cout << cnt;
}