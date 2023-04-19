#pragma once
#include <list>
#include <vector>
#include <optional>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    // equal
    bool operator==(TreeNode* that) {
        return tree_eq(this, that);
    }
    static bool tree_eq(TreeNode* a, TreeNode* b) {
        if (a == b) {
            return true;
        }

        if (a == nullptr && b == nullptr) {
            return true;
        }

        if (a == nullptr || b == nullptr) {
            return false;
        }

        return tree_eq(a->left, b->left) && tree_eq(a->right, b->right);
    }
};

static inline TreeNode* buildTree(const std::vector<std::optional<int>>& nodes) {
    auto ln = nodes.size();
    TreeNode* root{};
    if (nodes.empty()) {
        return root;
    }

    if (nodes[0].has_value()) {
        root = new TreeNode(nodes[0].value());
    } else {
        return root; // no root
    }

    std::queue<TreeNode*> items;
    items.push(root);

    for (auto i = 1; i < ln; ++i) {
        if (items.empty() || items.front() == nullptr) {
            break;
        }

        TreeNode* item = nullptr;
        if (nodes[i].has_value()) {
            item = new TreeNode(nodes[i].value());
            items.push(item);
        }

        if (i%2 == 1) { // left
            items.front()->left = item;
        } else { // right
            items.front()->right = item;
            items.pop();
        }
    }

    return root;
}

static inline void freeTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
