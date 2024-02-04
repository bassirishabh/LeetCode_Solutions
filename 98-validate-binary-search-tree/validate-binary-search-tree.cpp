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
    bool valid(TreeNode* root,TreeNode* left,TreeNode* right){
        if(root==NULL) return true;

        if(left!=NULL && root->val<=left->val || (right!=NULL && root->val>=right->val)) return false;
        return valid(root->left,left,root) && valid(root->right,root,right);

    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;

        return valid(root,NULL,NULL);
    }
};