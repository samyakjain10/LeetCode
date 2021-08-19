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
    
private:
    
    int totalSum(TreeNode* root){
        
        if(!root) return 0;
        
        int lSum = totalSum(root->left);
        int rSum = totalSum(root->right);
        
        return root->val + lSum + rSum;
        
    }
    
    int maxProdHelper(TreeNode* root, int total, long long &maxProd){
        
        if(!root) return 0;
        
        int lSum = maxProdHelper(root->left, total, maxProd);
        int rSum = maxProdHelper(root->right, total, maxProd);
        
        int subtreeSum = root->val + lSum + rSum;
        
        maxProd = max(maxProd, (long long)(subtreeSum%1000000007)*((total-subtreeSum)%1000000007));
        
        return subtreeSum;
        
    }

    
public:
    
    int maxProduct(TreeNode* root) {
        
        int total = totalSum(root);
        long long maxProd = INT_MIN;
        
        int x = maxProdHelper(root,total,maxProd);
        
        return maxProd%1000000007;
    }
};