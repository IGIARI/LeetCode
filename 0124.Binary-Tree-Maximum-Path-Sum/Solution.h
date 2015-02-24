/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int maxPath;
public:
    int maxPathSum(TreeNode *root) {
        maxPath = root->val;
        longestSubPath(root);
        return maxPath;
    }
    
    int longestSubPath(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == root->right) {
            if (root->val > maxPath) maxPath = root->val;
            return root->val;
        }
        int lSubPath = longestSubPath(root->left);
        int rSubPath = longestSubPath(root->right);
        int path = root->val;
        path += lSubPath > 0 ? lSubPath : 0;
        path += rSubPath > 0 ? rSubPath : 0;
        if (path > maxPath) maxPath = path;
        return max(root->val, root->val + max(lSubPath, rSubPath));
    }
};