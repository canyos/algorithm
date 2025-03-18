#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <deque>
#include <climits>
#include <stack>

using namespace std;

class Node {
public:
	int left;
	int right;
	int height;
	Node(int left, int right, int height) {
		this->left = left;
		this->right = right;
		this->height = height;
	}
};

bool operator> (const Node& n1, const  Node& n2) {
	if (n1.height == n2.height) {
		if (n1.left == n2.left) {
			return n1.right < n2.right;
		}
		return n1.left < n2.left;
	}
	return n1.height > n2.height;
}
bool operator< (const Node& n1, const  Node& n2) {
	if (n1.height == n2.height) {
		if (n1.left == n2.left) {
			return n1.right > n2.right;
		}
		return n1.left > n2.left;
	}
	return n1.height < n2.height;
}

vector<Node> v;
bool compare(const Node& n1, const Node& n2) {
	if (n1.left == n2.left) {
		if (n1.height == n2.height) {
			return n1.right < n2.right;
		}
		return n1.height > n2.height;
	}
	return n1.left < n2.left;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	int l, h, r;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> h >> r;
		v.push_back(Node(l, r, h));
	}

	sort(v.begin(), v.end(), compare);
	priority_queue<Node> pq;

	int index = 0;
	int end = v[0].right;//현재 높이가 끝나는 지점
	int height = v[0].height;//현재 높이
	cout << v[0].left << " " << height << " ";
	pq.push(v[0]);
	for (int i = 1; i < n; i++) {
		Node cur = v[i];

		if (cur.left > end) {//지금 높이가 끝나는 지점보다 오른쪽에 위치한 빌딩
			while (!pq.empty() && pq.top().right < cur.left) {//end(cur.left)의 위치에 존재하는 빌딩중 가장 큰거 찾기
				if (pq.top().right > end && pq.top().height != height) {
					height = pq.top().height;
					cout << end << " " << height << " ";
					end = pq.top().right;
				}
				pq.pop();
			}
			if (pq.empty()) {//가장 높은 빌딩 없으면 0으로 하고 지금 빌딩으로 이동
				cout << end << " " << 0 << " ";
				end = cur.right;
				height = cur.height;
				cout << cur.left << " " << cur.height << " ";
			}
			else {//가장 높은 빌딩이 있으면 가장 높은 빌딩이랑 지금 빌딩 비교해야함
				if (height > pq.top().height) {//높이가 차이난다면
					cout << end << " " << pq.top().height << " ";
					height = pq.top().height;
					end = pq.top().right;
				}
				else {
					end = pq.top().right;
				}
			}
		}

		else if (cur.left == end) {//제일 높은 건물이 현재건물과 맡닿아있음
			while (!pq.empty() && pq.top().right <= cur.left) {//cur.left기준 존재하는 빌딩중 가장 큰거 찾기
				pq.pop();
			}
			if (pq.empty()) {//힙이 비었음
				if (cur.height != height)
					cout << cur.left << " " << cur.height << " ";
				end = cur.right;
				height = cur.height;
			}
			else if (pq.top().height > cur.height) {//힙에 남아있던게 현재거보단 높음
				if (pq.top().height != height)
					cout << end << " " << pq.top().height << " ";
				end = pq.top().right;
				height = pq.top().height;
			}
			else {//현재 들어온게 힙중에 가장 큼
				if (cur.height != height)
					cout << cur.left << " " << cur.height << " ";
				end = cur.right;
				height = cur.height;
			}
		}

		if (cur.height > height) {//지금 높이가 끝나기 전에 더 높은 빌딩이 들어옴
			height = cur.height;
			end = cur.right;
			cout << cur.left << " " << height << " ";
		}

		pq.push(cur);
	}
	while (!pq.empty()) {
		if (pq.top().height == height) {//높이가 같다면
			end = max(pq.top().right, end);//끝지점만 갱신
			pq.pop();
			continue;
		}
		if (pq.top().right > end) {
			cout << end << " " << pq.top().height << " ";
			end = pq.top().right;
			height = pq.top().height;
		}
		pq.pop();
	}
	cout << end << " " << 0;

	return 0;
}
