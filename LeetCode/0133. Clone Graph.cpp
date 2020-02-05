// Time  : 4 ms (99.70%)
// Memory: 11.9 MB (100.00%)

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> mp;
        return node == nullptr ? nullptr : helper(mp, node);
    }

    Node* helper(unordered_map<int, Node*>& mp, Node* node) {
        Node* p = new Node(node->val);
        mp.emplace(node->val, p);
        unordered_map<int, Node*>::iterator it;
        for (int i = 0; i < node->neighbors.size(); i++) {
            it = mp.find(node->neighbors[i]->val);
            if (it == mp.end()) {
                p->neighbors.push_back(helper(mp, node->neighbors[i]));
            } else {
                p->neighbors.push_back(it->second);
            }
        }
        return p;
    }
};
