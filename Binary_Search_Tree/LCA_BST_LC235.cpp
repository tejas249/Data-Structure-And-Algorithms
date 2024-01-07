/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL){
            return NULL;
        }

        //left subtree recusive , p and q on left side
        if(p->val < root->val && q->val < root->val){
           return  lowestCommonAncestor(root->left,p,q);
        }

        //right subtree recursive , p and q on the right side 
        else if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        //when p and q on diffrent sides
        else{
            return root;
        }
      return root;
    }
};
