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




// SOLUTION NO 2
// store the inorder in the vector and compare two element for finding the diffrence
 vector<int> v;
     void inorder(TreeNode* root){
         if(root == NULL){
             return;
         }
         inorder(root->left);
         v.push_back(root->val);
         inorder(root->right);
     }
    int minDiffInBST(TreeNode* root) {
       inorder(root);
       int ans = INT_MAX;
       int n = v.size();
       for(int i=1; i<n; i++){
           ans = min(ans, v[i] - v[i-1]);
       }
       return ans;
    }
