#include <unordered_map>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> neighbors;

  Node() {}

  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* node) { return this->clone(node); }

 private:
  unordered_map<int, Node*> seen;
  Node* clone(Node* node) {
    if (node == nullptr) return node;
    if (seen.count(node->val)) return seen[node->val];

    Node* newNode = createNode(node);
    int size = node->neighbors.size();
    for (int i = 0; i < size; i++) {
      newNode->neighbors.push_back(clone(node->neighbors[i]));
    }
    return newNode;
  }
  Node* createNode(Node* node) {
    Node* newNode = new Node();
    newNode->val = node->val;
    seen[node->val] = newNode;
    return newNode;
  }
};