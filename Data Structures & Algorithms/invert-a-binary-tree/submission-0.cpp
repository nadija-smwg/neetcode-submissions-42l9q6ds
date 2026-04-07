/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {   // 1,2,3,4,5,6,7
        if (!root) return nullptr;
        
        stack<TreeNode*> st;  
        st.push(root);  // 1

        while (!st.empty()) {
            TreeNode* node = st.top();  //1
            st.pop(); 
            swap(node->left, node->right);    // 2,3
            if (node->left) st.push(node->left);  // 2
            if (node->right) st.push(node->right); // 3
        }
        return root;
    }
};
