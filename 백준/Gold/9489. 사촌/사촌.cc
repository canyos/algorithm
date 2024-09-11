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
int arr[1005];//입력
int depth[1005];//depth에 몇개의 노드가 있는지
vector<int> node[1000005];//i번째 자식에 누가있는지
int par[1000005];
queue<int>qu;
int n, k;
int parNodeNum ; //k의 부모의 숫자
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	while (1) {
		
		cin >> n >> k;
		if (n == 0 && k == 0) break;
		for (int i = 0; i < 1005; i++) {
			node[arr[i]] = {};
			par[arr[i]] = 0;
			arr[i] = 0;
			depth[i] = 0;
		}
		while (!qu.empty()) { qu.pop(); }


		for (int i = 0; i < n; i++)
			cin >> arr[i];

		depth[0] = 1;

		qu.push( arr[0]);//초기값
		int cur = 1; // 1번부터 시작

		while (cur < n && !qu.empty()) { //cur이 n보다 작은 경우 계속함
			int parNum = qu.front(); qu.pop();
			//cout << parNum << ":" << parDepth << endl;

			if (arr[cur - 1] + 1 != arr[cur]) {//처음엔 무조건 부모가 다르므로 넣어줌
				node[parNum].push_back(arr[cur]);
				par[arr[cur]] = parNum;
				qu.push(arr[cur++]);
			}

			while (cur < n && arr[cur - 1] + 1 == arr[cur]) {//이전 숫자와 연속되어있다면 같은 부모이므로 계속 넣어줌
				node[parNum].push_back(arr[cur]);
				par[arr[cur]] = parNum;
				qu.push( arr[cur++]);
			}
		}
		/*for (int i = 0; i < n; i++) {
			if (node[i].size() > 0) {
				cout << i << ": ";
				for (int j : node[i]) {
					cout << j << " ";
				}
				cout << endl;
			}
		}*/
		int sumCousin = 0;
		//cout << "par[k] : " << par[k] << endl;
		//cout << "par[par[k]] : " << par[par[k]] << endl;

		if (par[k] != 0 && par[par[k]] != 0) {
			for (int child : node[par[par[k]]]) {//부모의 부모의 자식들마다
				if (child != par[k]) //부모가 아니라면
					sumCousin += (int)node[child].size(); //자식 수(사촌)를 더함
			}
		}
		
		cout << sumCousin << '\n';
	}
	return 0;
}