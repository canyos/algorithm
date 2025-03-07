#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <deque>

using namespace std;

int vote[100001];
int cnt;
int visited[100001];
//-1 사이클아님 0 탐색 안함 1지금 탐색중 2 사이클판정
int recursive(int cur) {
	int next = vote[cur];

	if (next == cur) {//나를 가르키는 사이클
		cnt--;
		visited[cur] = 2;
		return -1;
	}

	if (visited[next] == 1) {//다음 노드부터 사이클 발생함
		cnt--;
		visited[cur] = 2;
		return next;
	}

	visited[cur] = 1;//현재 노드 탐색중 표시

	//다음노드가 이미 사이클이 아니거나 사이클이라고 판정한 경우 사이클 발견할 수 없음
	if (visited[next] == -1 || visited[next] == 2) {
		visited[cur] = -1;
		return -1;
	}
		
	
	int res = recursive(next);//사이클 루트노드 번호 반환, 사이클 없으면 -1

	if (res != -1) {//사이클 발견했음
		cnt--;
		visited[cur] = 2;
	}
	else {//사이클 발견 못했음
		visited[cur] = -1;
	}

	if (res == cur) //사이클의 루트임
		return -1;
	else
		return res;
	
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n;
		cin >> n;

		cnt = n;
		fill(visited, visited + 100001, false);
		for (int i = 1; i <= n; i++) {
			cin >> vote[i];
		}

		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0) {//탐색안한 노드만 탐색
				recursive(i);
			}
		}

		cout << cnt << "\n";
	}


	return 0;
}
