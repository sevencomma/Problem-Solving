#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Node {
public:
    int data; // x value
    Node* left;
    Node* right;

    Node(int val) {
        data = val;

        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    Node* root;

    Node* insertNode(Node* node, int key) {
        if (!node) {
            return new Node(key);
        }
        if (key < node->data) {
            node->left = insertNode(node->left, key);
        }
        else {
            node->right = insertNode(node->right, key);
        }

        return node;
    }

    BST() : root(nullptr) {}

    void insert(int key) {
        root = insertNode(root, key);
    }

    void preorder(Node* root, vector<int> &repository) {
        if (root == nullptr)
            return;

        repository.push_back(root->data);

        preorder(root->left, repository);
        preorder(root->right, repository);
    }

    void postorder(Node* root, vector<int> &repository) {
        if (root == nullptr)
            return;

        postorder(root->left, repository); 
        postorder(root->right, repository);

        repository.push_back(root->data);
    }

};

bool compare(const vector<int> a, const vector<int> b) {
    if (a.back() == b.back())
        return a.front() < b.front();
    return a.back() > b.back();
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);

    map<int, int> x_index_matching;

    for (int i = 0; i < nodeinfo.size(); i++) {
        x_index_matching[nodeinfo[i].front()] = i + 1;
    }

    sort(nodeinfo.begin(), nodeinfo.end(), compare);

    BST tree;

    for (int i = 0; i < nodeinfo.size(); i++) {
        tree.insert(nodeinfo[i].front());
    }

    tree.preorder(tree.root, answer[0]);
    tree.postorder(tree.root, answer[1]);

    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            answer[i][j] = x_index_matching[answer[i][j]];
        }
    }

    return answer;
}