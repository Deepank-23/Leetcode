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
     int  diameter;
    int levels(TreeNode *root){
        if(root== NULL)return 0;
        int left = levels(root->left);
        int right = levels(root->right);
        int level = 1+ max(left,right);
        int mydia = left+right;
        diameter= max(diameter,mydia);
        return level;

    }
    int diameterOfBinaryTree(TreeNode* root) {

        diameter = 0 ;
        levels(root);
        return diameter;
        
    }
};