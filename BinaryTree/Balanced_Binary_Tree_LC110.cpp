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
   
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftheight = height(root->left);
        int rightheight = height(root->right);
        int  finalans = max(leftheight,rightheight)+ 1;
        return finalans;
    }


    
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        int leftheight = height(root->left);
        int rightheight = height(root->right);
        int diff = abs(leftheight - rightheight);

        bool currNode = (diff <= 1);

        bool leftans = isBalanced(root->left);
        bool rightans = isBalanced(root->right);

        if(currNode && leftans && rightans){
            return true;
        }
        else{
            return false;
        }
    }
};
