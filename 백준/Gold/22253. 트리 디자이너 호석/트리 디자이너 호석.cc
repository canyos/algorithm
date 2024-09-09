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

ll result = 0;
int n;
int arr[100001];
bool visited[100001];
queue<int> qu;
vector<int> edge[100001];
vector<int> child[100001];
ll DIV = 1000000007;
int dy[100001][10];

void input() {
	cin >> n;
	int from, to;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n - 1; i++) {
		cin >> from >> to;
		edge[from].push_back(to); //양방향 edge추가
		edge[to].push_back(from);
	}
}

void makeTree() {
	qu.push(1);
	visited[1] = 1;
	while (!qu.empty()) {
		int cur = qu.front(); qu.pop();
		for (int chi : edge[cur]) { 
			if (visited[cur] && !visited[chi]) {//from은 방문하고 to는 방문안함
				qu.push(chi);
				child[cur].push_back(chi);
				visited[chi] = 1;
			}
			else if(visited[chi] && !visited[cur]) {//to만 방문하고 from은 방문안함
				qu.push(cur);
				child[chi].push_back(cur);
				visited[cur] = 1;
			}
		}
		//cout << cur->index << endl;
	}
}

void dfs(int x, int par) {// 정점 x의 부모가 par였고 x- subtree의 dy배열 계산
	//dy[i][j]는 i번정점으로 시작해서 j로 끝나는 수열의 개수

	dy[x][arr[x]] = 1;
	for (int y : child[x]) {
		if (y == par) continue;
		dfs(y, x); //자식들에 대해서 dfs실행

		for (int k = 0; k <= 9; k++) { //x번 정점 불 안키는 경우
			dy[x][k] += dy[y][k];
			dy[x][k] %= DIV;
		}

		for (int k = arr[x]; k <= 9; k++) { //x번 정점 불 켜는 경우
			//나보다 큰 숫자로만 끝나야됨
			dy[x][arr[x]] += dy[y][k];
			dy[x][arr[x]] %= DIV;
		}

	}
}
void pro() {//1번 정점이 root이므로 여기서 시작해서 tree의 구조 파악
	dfs(1, -1);

	for (int i = 0; i <= 9; i ++ ) {
		result += dy[1][i];
		result %= DIV;
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	makeTree();
	pro();
	
		
	cout << result;
	return 0;
}