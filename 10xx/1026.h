
#pragma once
#include "../tree_node.h"

class Solution {
public:
    static int maxAncestorDiff(TreeNode* root) {
        int result = 0;
        maxAncestorDiffR(root, root->val, root->val, &result);
        return result;
    }

    static void maxAncestorDiffR(TreeNode* ancestor, int min, int max, int* result) {
        if (ancestor == nullptr) {
            return;
        }

        if (ancestor->left != nullptr) {
            int mi = std::min(min, ancestor->left->val), mx = std::max(max, ancestor->left->val);
            *result = std::max({*result, std::abs(ancestor->left->val - mi), std::abs(ancestor->left->val - mx)});
            maxAncestorDiffR(ancestor->left, mi, mx, result);
        }

        if (ancestor->right != nullptr) {
            int mi = std::min(min, ancestor->right->val), mx = std::max(max, ancestor->right->val);
            *result = std::max({*result, std::abs(ancestor->right->val-mi), std::abs(ancestor->right->val-mx)});
            maxAncestorDiffR(ancestor->right, mi, mx, result);
        }
    }
};
