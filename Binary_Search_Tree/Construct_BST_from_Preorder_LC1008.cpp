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
    TreeNode* build(vector<int> &A, int &i, int bound){
      //base case 
        if(i == A.size() || A[i] > bound){
            return NULL;
        }
      // root bana liya 
        TreeNode* root = new TreeNode(A[i++]);
      //left call recursion
        root->left = build(A, i, root->val);
      //right call recursion 
        root->right = build(A, i, bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }
};
