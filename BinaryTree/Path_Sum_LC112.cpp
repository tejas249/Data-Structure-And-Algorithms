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
    bool hasPathSum(TreeNode* root, int targetSum, int sum){
      
      //base case 
      if(root == NULL){
          return false;
      }
      //calculate the sum
      sum = sum + root->val;

      //check leaf node and compare it with the target 
      if(root->left == NULL && root->right == NULL){
          if(sum == targetSum){
              return true;
          }
          else{
              return false;
          }
      }
      // recursive call to traverse
      bool leftans = hasPathSum(root->left, targetSum, sum);
      bool rightans = hasPathSum(root->right, targetSum, sum);
      return leftans||rightans;
}
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = hasPathSum( root, targetSum, sum);
        return ans;
    }
};
