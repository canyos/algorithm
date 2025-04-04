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

int arr[16][16];
int n;
int sr, sc;
int gr, gc;
class Node {
public:
	int r;
	int c;
	int cost;
	Node(int r, int c, int cost) {
		this->r = r;
		this->c = c;
		this->cost = cost;
	}
};

bool operator<(const Node& n1, const Node& n2) {
	return n1.cost > n2.cost;
}

bool checkPos(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < n;
}
int dr[] = { 0,0,1,-1 }, dc[] = { -1,1,0,0 };
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];

		cin >> sr >> sc;
		cin >> gr >> gc;

		bool visited[16][16] = { 0 };
		priority_queue<Node> pq;
		int answer = -1;
		pq.push(Node(sr, sc, 0));
		while (!pq.empty()) {
			Node cur = pq.top(); pq.pop();
			int r = cur.r, c = cur.c, cost = cur.cost;
			if (visited[r][c])continue;
			visited[r][c] = true;
			if (r == gr && c == gc) {
				answer = cur.cost;
				break;
			}
			for (int k = 0; k < 4; k++) {
				int tr = r + dr[k], tc = c + dc[k];
				if (checkPos(tr, tc)&& !visited[tr][tc] && arr[tr][tc] != 1) {
					if (arr[tr][tc] == 0) {
						pq.push(Node(tr, tc, cost + 1));
					}
					if (arr[tr][tc] == 2) {
						for (int i = 1; i <= 3; i++) {
							if ((cost + i ) % 3 == 0) {
								pq.push(Node(tr, tc, cost + i));
							}
						}
					}
				}
			}
		}
		cout << "#" << t<< " " << answer << "\n";
	}
	return 0;
}