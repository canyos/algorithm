#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <tuple>
#include <string>
#include <cstring>
#include <bitset>
#include <vector>
#include <map>
#define endl "\n"
using namespace std;
typedef long long ll;
const int INF = 1e9;

int n, k;
vector<int> v;
char cmd;
int pos, value, I, J;
ll tree[444444];

ll makeTree(int left, int right, int pos) {
	if (left == right) {
		tree[pos] = v[left];
		return tree[pos];
	}

	int mid = (left + right) / 2;
	ll l = makeTree(left, mid, pos * 2);
	ll r = makeTree(mid + 1, right, pos * 2 + 1);
	tree[pos] = l * r;
	return tree[pos];
}

void update(
	int left, int right, //배열 범위
	int pos,//트리 범위  
	int i, int value) {//업데이트할 배열 index, 값
	
	if (right < i || i<left) return;
	if (left == right) {
		tree[pos] = value;
		return;
	}

	ll mid = (left + right) / 2;
	update(left, mid, pos * 2, i, value);
	update(mid + 1, right, pos * 2 + 1, i, value);
	tree[pos] = tree[pos * 2] * tree[pos * 2 + 1];
}

ll getProduct(int left, int right,//pos가 포함하는 범위
	int pos, int I, int J) {//내가 구할 범위
	if (right < I || left > J)return 1;
	if (I  <= left && right  <= J)return tree[pos];
	if (left == right) return tree[pos];

	int mid = (left + right) / 2;
	ll p1 = getProduct(left, mid, pos * 2, I, J);
	ll p2 = getProduct(mid + 1, right, pos * 2 + 1, I, J);
	return  p1 * p2;	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n >> k){
		v.resize(n);
		int num;
		for (int i = 0; i < n; i++) {
			cin >> num;
			if (num > 0)num = 1;
			if (num < 0)num = -1;
			v[i] = num;
		}			
		
		makeTree(0, n-1, 1);

		string ret = "";
		for (int i = 0; i < k; i++) {
			cin >> cmd;
			if (cmd == 'C') {
				cin >> pos >> value;
				if (value > 0)value = 1;
				if (value < 0)value = -1;
				update(0, n-1, 1, pos-1, value);
			}
			else {
				cin >> I >> J;
				ll res = getProduct(0, n-1, 1, I-1,J-1);
				if (res > 0)
					ret += "+";
				else if (res < 0)
					ret += "-";
				else
					ret += "0";
			}
		}
		cout <<ret<< endl;
	} 
	return 0;
}