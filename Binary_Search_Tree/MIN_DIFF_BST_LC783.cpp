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
   TreeNode* prev = NULL;
   void solve(TreeNode* root, int &ans){
        // traverse the left one 
       if(root->left){
       solve(root->left, ans);
       }

       // if prev not null then ans or abs diff compare karo and replace the ans 
       if(prev != NULL){
           ans = min(ans, abs(prev->val - root->val));
       }
       prev = root;
       // traverse the right part of the tree
       if(root->right){
       solve(root->right, ans);
       }
   }
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        solve(root,ans);
        return ans;
    }
};
