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
int maxsum;
    
    int pathsum(TreeNode* root){
        if(root==NULL)return 0;
        int right= pathsum(root->right);
        int left = pathsum(root->left);
        int sum= root->val;
        if(right>0)sum+=right;
        if(left>0)sum+=left;
        maxsum = max(sum,maxsum);
        return root->val + max(0,max(right,left));
    }
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        pathsum(root);
        return maxsum;
    }
};