#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <string>
#include <set>
#include <unordered_map>

using namespace std;

bool visited[51];
vector<vector<int>> person(51);
vector<vector<int>> party(51);
bool trueParty[51];

int n, m;
int trueCnt;//진실을 아는 사람 수
queue<int> qu; //진실을 아는 사람 
int partyCnt;//파티에 참가하는 사람 수

int main()
{

	cin >> n >> m;
	cin >> trueCnt;
	int temp;
	for (int i = 1; i <= trueCnt; i++) {
		cin >> temp;
		visited[temp] = true;
		qu.push(temp);
	}

	
	for (int i = 1; i <= m; i++) {//파티번호
		cin >> partyCnt;
		for (int j = 0; j < partyCnt; j++) {//참가하는 사람 수 
			cin >> temp;
			person[temp].push_back(i);
			party[i].push_back(temp);
		}
	}

	while (!qu.empty()) {
		int cur = qu.front(); qu.pop();//진실을 아는 사람
		visited[cur] = true;
		for (auto par : person[cur]) {//그 사람이 참여한 모든 파티에 대해
			trueParty[par] = true;
			for (auto per : party[par]) {//한 파티에 대해 참여한 모든 사람에 대해
				if (!visited[per])
					qu.push(per);
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= m; i++) {
		if (!trueParty[i])
			answer++;
	}
	cout << answer;

	return 0;
}