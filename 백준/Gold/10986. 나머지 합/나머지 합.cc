#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
int N, M;
int n;
ll sum;
int mod[1001];
ll answer;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> n;
		sum += n;
		
		answer += mod[sum%M];
		mod[sum % M]++;
		if (sum%M == 0)
			answer++;

		//cout << i << " " << answer << endl;;
	}
	cout << answer;


	
	return 0;
}