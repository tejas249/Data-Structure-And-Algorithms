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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // first case empty tree 
        if(root == NULL){
            root = new TreeNode(val);
            return root;
        }

        // insert intp the left one 
      if(root->val > val){
        root->left = insertIntoBST(root->left,val);
      } 

      // insert into the right
      if(root->val < val){
          root->right = insertIntoBST(root->right, val);
      }
      return root;
   }
};
