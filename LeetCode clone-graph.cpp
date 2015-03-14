// LeetCode clone-graph
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

// Definition for undirected graph.
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == nullptr)
			return nullptr;

		map <int, UndirectedGraphNode* > old_addr;
		map <int, UndirectedGraphNode* > new_addr;
		queue <int> q;
		set <int> visited, touched;
		UndirectedGraphNode * rootnode = NULL, *currentnode = NULL, *nextnode = NULL;
		UndirectedGraphNode * old_currentnode = NULL, *old_nextnode = NULL;

		int root = node->label;
		int current = -1;
		int next = -1;

		old_addr[root] = node;
		rootnode = new UndirectedGraphNode(root);
		new_addr[root] = rootnode;

		q.push(node->label);
		touched.insert(root);

		while (!q.empty()) {
			current = q.front();
			q.pop();
			old_currentnode = old_addr[current];
			currentnode = new_addr[current];

			for (int it = 0; it < old_currentnode->neighbors.size(); ++it) {
				next = (old_currentnode->neighbors[it])->label;
				if (touched.find(next) == touched.end()) {
					old_nextnode = (old_currentnode->neighbors[it]);
					old_addr[next] = old_nextnode;
					nextnode = new UndirectedGraphNode(next);
					new_addr[next] = nextnode;

					q.push(next);
					touched.insert(next);
				}
				(currentnode->neighbors).push_back(new_addr[next]);
			}
			visited.insert(current);
		}
		return rootnode;
	}
};

int main() {
	UndirectedGraphNode * node0 = new UndirectedGraphNode(0);
	UndirectedGraphNode * node1 = new UndirectedGraphNode(1);
	UndirectedGraphNode * node2 = new UndirectedGraphNode(2);
	node0->neighbors.push_back(node1);
	node0->neighbors.push_back(node2);
	node1->neighbors.push_back(node0);
	node2->neighbors.push_back(node0);
	node1->neighbors.push_back(node2);
	node2->neighbors.push_back(node1);
	node2->neighbors.push_back(node2);
	UndirectedGraphNode * node = (Solution()).cloneGraph(node0);
	return 0;
}