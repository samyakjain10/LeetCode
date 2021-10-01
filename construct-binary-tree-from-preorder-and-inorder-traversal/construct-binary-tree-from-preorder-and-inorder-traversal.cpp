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
    unordered_map<int,int> mp;
    TreeNode *create(int lidx, int ridx, int lpre, int rpre, vector<int> inorder, vector<int> preorder)
    {
        if(lidx > ridx) return NULL;
        TreeNode *root = new TreeNode(preorder[lpre]);
        int brpoint = mp[preorder[lpre]];
        root->left = create(lidx, brpoint-1, lpre+1, lpre+(brpoint-lidx), inorder, preorder);
        root->right = create(brpoint+1, ridx, lpre+(brpoint-lidx)+1, rpre, inorder, preorder);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]]=i;
        int inorder_size = inorder.size(), preorder_size = preorder.size();
        return create(0, inorder_size-1, 0, preorder_size-1, inorder, preorder);
    }
};