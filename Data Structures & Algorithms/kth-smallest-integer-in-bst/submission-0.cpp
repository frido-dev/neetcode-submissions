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
    vector<int> inOrder(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> st;

        st.push(root);

        while(!st.empty()) {
            TreeNode* tp = st.top();
            if (tp->left == NULL) {
                st.pop();
                res.push_back(tp->val);

                if (tp->right) {
                    st.push(tp->right);
                }
            }

            if (tp->left) {
                st.push(tp->left);
                tp->left = NULL;
            }           
        }

        return res;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res = inOrder(root);

        return res[k-1];
    }
};
