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
    int maxsum=INT_MIN;

    int gain(TreeNode* node){
        if(node==NULL) return 0;
        int left=max(gain(node->left),0);
        int right=max(gain(node->right),0);

        maxsum=max(maxsum,left+right+node->val);

        return node->val+max(left,right);

    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        gain(root);
        return maxsum;
    }
};