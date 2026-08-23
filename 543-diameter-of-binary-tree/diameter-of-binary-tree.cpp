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
    
    int levels(TreeNode *root,map<TreeNode*,int>& dp){
        if(root== NULL)return 0;
        if(dp.count(root))return dp[root];
        int left = levels(root->left,dp);
        int right = levels(root->right,dp);
        int level = 1+ max(left,right);
        dp[root]=level;
        return level;

    }
    int diameter(TreeNode* root,map<TreeNode*,int>& dp){
        if(root== NULL)return 0;
        int left = diameter(root->left,dp);
        int right = diameter(root->right,dp);
        int mydia = levels(root->left,dp)+levels(root->right,dp);
        return max(mydia,max(left,right));
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        map<TreeNode*,int>dp;
        return diameter(root,dp);
       
        
    }
};