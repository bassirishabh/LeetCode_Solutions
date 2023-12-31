/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string answer="";
        if(root==NULL) return answer;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL) answer+="#,";
            else {
                answer+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
            
        }
        cout<<answer;
        return answer;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;

        stringstream s(data);
        string str;
        getline(s,str,',');
        queue<TreeNode*> q;
        int a=stoi(str);
        TreeNode* node=new TreeNode(a);
        q.push(node);

        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#") temp->left=NULL;
            else{
                TreeNode* leftnode=new TreeNode(stoi(str));
                temp->left=leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
            if(str=="#") temp->right=NULL;
            else{
                TreeNode* rightnode=new TreeNode(stoi(str));
                temp->right=rightnode;
                q.push(rightnode);
            }
        }

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));