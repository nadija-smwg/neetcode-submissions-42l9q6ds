class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        int maxDepth = 0;

        while (!st.empty()) {
            auto [node, depth] = st.top();
            st.pop();

            maxDepth = max(maxDepth, depth);

            if (node->left) st.push({node->left, depth + 1});
            if (node->right) st.push({node->right, depth + 1});
        }

        return maxDepth;
    }
};