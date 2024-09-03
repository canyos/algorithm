#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

class Node {
public:
	string name;
	Node* parent;
	vector<Node*> son;
	int depth;
	Node(string name) {
		this->name = name;
		this->parent = nullptr;
		this->son = { };
		this->depth = 0;
	}
};

class Edge {
public:
	Node* parent;
	Node* son;
	Edge(Node* son, Node* parent) {
		this->parent = parent;
		this->son = son;
	}
};

int N,M;
string X, Y;
vector<Node*> nodes;
vector<Edge*> edges;
map<string, Node*>mp;

bool compare(Node* x, Node* y) {
	return x->name < y->name;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X;
		Node* temp = new Node(X);
		nodes.push_back(temp);
		mp[X] = temp;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> X >> Y;
		edges.push_back(new Edge((mp[X]), (mp[Y])));
		mp[X]->depth++;
	}
}

queue<Node*>qu;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	for (auto it : edges) {
		Node* par = it->parent;
		Node* son = it->son;

		if (par->depth == son->depth - 1) {
			par->son.push_back(son);
			son->parent = par;
		}
	}
	vector<string> ancestors;
	for (auto it : nodes) {
		if (it->parent == nullptr) {
			ancestors.push_back(it->name);
		}
	}
	sort(ancestors.begin(), ancestors.end());
	cout << ancestors.size() << '\n';
	for (auto it : ancestors)
		cout << it << " ";
	cout << '\n';

	sort(nodes.begin(), nodes.end(), compare);
	for (auto it : nodes) {
		sort(it->son.begin(), it->son.end(), compare);
	}

	for (auto it : nodes) {
		cout << it->name << " " << it->son.size() << " " ;
		for(auto it2 : it->son)
			cout << it2->name << " ";
		cout << '\n';
	}

	return 0;
}