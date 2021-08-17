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
    int goodNodesHelper(TreeNode* root, int msf){
        
        if(!root){
            return 0;
        }
        
        int temp = 0;
        
        int leftGoodNodes = goodNodesHelper(root->left, max(msf,root->val));
        int rightGoodNodes = goodNodesHelper(root->right, max(msf,root->val));
        
        if(root->val >= msf) temp++;
        
        return temp + leftGoodNodes + rightGoodNodes;
        
    }
    
    int goodNodes(TreeNode* root) {
        return goodNodesHelper(root, INT_MIN);
    }
};