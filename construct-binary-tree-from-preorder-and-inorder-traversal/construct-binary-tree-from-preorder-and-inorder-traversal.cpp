class Solution {
public:
    unordered_map<int,int> lookUpForIndex;
    TreeNode* solve(vector<int>&  preorder,vector<int>& inorder,int i ,int j,int& preorderIndex)
    {
        if(i > j || preorderIndex >= preorder.size()) return nullptr;

        int preorderValue =  preorder[preorderIndex];
        TreeNode* root = new TreeNode(preorderValue);

        int inorderIndex = lookUpForIndex[preorderValue];
        preorderIndex++;

        root->left = solve(preorder,inorder, i, inorderIndex - 1, preorderIndex);
        root->right = solve(preorder,inorder, inorderIndex + 1, j, preorderIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i < inorder.size();i++)
            lookUpForIndex[inorder[i]]=i;

        int preorderIndex = 0;
        return solve(preorder, inorder,  0, preorder.size()-1, preorderIndex);
    }
};