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
    vector<int> rightSideView(TreeNode* root) {
        // last values in the level order trversal for each level

        queue<TreeNode*> q;
        vector<int> res;
        
        if (!root) return res;

        q.push(root);

        while(!q.empty()) {
            int level = q.size();

            while(level) {
                auto node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                if (level == 1) {
                    res.push_back(node->val);
                }
                level--;
            }
        }

        return res;
    }
};
