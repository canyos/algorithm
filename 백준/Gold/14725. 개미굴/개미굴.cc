#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <deque>

using namespace std;

class Node {
public:
	string value;
	Node* parent;

	// 커스텀 비교 연산자를 사용한 set 선언
	struct Compare {
		bool operator()(const Node* lhs, const Node* rhs) const {
			return lhs->value < rhs->value;  // value 기준 오름차순 정렬
		}
	};

	set<Node*, Compare> child;  // 정렬 기준 적용된 set

	Node(string str){
		this->value = str;
		this->parent = nullptr;
		this->child = {};
	}
};

void recursive(Node* node, int depth) {
	if (node->value.length() > 0) {
		for (int i = 0; i < depth; i++)
			cout << "--";
		cout << node->value << '\n';
	}


	for (Node* c : node->child) {
		recursive(c, depth + 1);
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int m;
	string str;

	Node* root = new Node("");
	for (int i = 0; i < n; i++) {
		cin >> m;
		Node* node = root;
		for (int j = 0; j < m; j++) {
			cin >> str;
			
			bool isChild = false;
			for (auto it = node->child.begin(); it != node->child.end();it++) {
				if ((*it)->value == str) {
					node = (*it);
					isChild = true;
					break;
				}
			}
			if (!isChild) {
				Node* newNode = new Node(str);
				node->child.insert(newNode);
				newNode->parent = node;
				node = newNode;
			}
			
		}
	}

	recursive(root, -1);

	return 0;
}
