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

class Edge {
public:
	int a;
	int b;
	int c;
	Edge(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

bool operator <(const Edge& e1, const Edge& e2) {
	return e1.c < e2.c;
}

int n,m;
vector<int> aa;
vector<Edge>edge;
unordered_map<ll, bool> visited;
ll answerll;
int answer = -1;
vector<int> arr;

ll makell() {
	ll temp = 0;
	for (int i = 0; i < n; i++) {
		temp = temp * 100 + arr[i];
	}
	return temp;
}

void swap(int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);//초기값
		aa.push_back(num);//정렬용
	}
		
	cin >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge.push_back(Edge(a,b,c));//엣지 개수
	}

	sort(edge.begin(), edge.end());//cost기준 정렬

	sort(aa.begin(), aa.end()); // 정답만들기
	for (int i = 0; i < n; i++) {
		answerll = answerll * 100 + aa[i];
	}

	priority_queue<pair<int,ll>> pq;//다익스트라 pq(cost, string)
	pq.push({ 0, makell() });

	while (!pq.empty()) { //8!*(n*m) = 40000*10*8 = 3,200,000
		auto cur = pq.top(); pq.pop();
		int cost = -cur.first; ll num = cur.second;
		if (visited[num])continue;
		visited[num] = true;

		if (num == answerll) {
			answer = cost;
			break;
		}

		for (ll i = 0, mod = 100, div = 1; i < n; i++,mod*=100,div*=100) {
			arr[n - 1 - i] = num % mod / div;
		}

		for (int i = 0; i < m; i++) {
			int ii = edge[i].a, jj = edge[i].b, c = edge[i].c;
			swap(ii - 1, jj - 1);
			ll next = makell();
			if (!visited[next]) 
				pq.push({ -(cost + c), next });
			
			swap(ii - 1, jj - 1);
		}
	}

	cout << answer;

	return 0;
}
//1,010,101,010,101,010