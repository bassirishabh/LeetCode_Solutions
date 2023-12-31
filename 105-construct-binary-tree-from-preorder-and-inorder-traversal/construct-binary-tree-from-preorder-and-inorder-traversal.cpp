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
    unordered_map<int,int> umap;
    int preorderindex;

    TreeNode* build(vector<int>& preorder,int left,int right){
        if(left<=right){
            int rootvalue=preorder[preorderindex++];
            TreeNode* node=new TreeNode(rootvalue);
            node->left=build(preorder,left,umap[rootvalue]-1);
            node->right=build(preorder,umap[rootvalue]+1,right);
            return node;
        }
        return NULL;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderindex=0;
        for(int i=0;i<inorder.size();i++) umap[inorder[i]]=i;
        return build(preorder,0,preorder.size()-1);
    }
};