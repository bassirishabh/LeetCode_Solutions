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
        int leftsum=max(gain(node->left),0);
        int rightsum=max(gain(node->right),0);

        maxsum=max(maxsum,node->val+leftsum+rightsum);

        return node->val+max(leftsum,rightsum);
    }

    int maxPathSum(TreeNode* root) {
        gain(root);
        return maxsum;
    }
};