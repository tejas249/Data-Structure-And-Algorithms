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
    bool isValidBST(TreeNode* root, long long MinVal, long long MaxVal){
        if(root == NULL) return true;
        if(root->val >= MaxVal || root->val <= MinVal){
            return false;
        }
     return isValidBST(root->left, MinVal, root->val) &&
               isValidBST(root->right, root->val, MaxVal);
    }
    bool isValidBST(TreeNode* root) {
    return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};


SOLUTION NO 2 
    
    
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
    bool solve(TreeNode* root, long long int lowerbound , long long int upperbound){
        //base case
        if(root == NULL){
            return true;
        }

        //conditions
        bool cond1 = (root->val > lowerbound);
        bool cond2 = (root->val < upperbound);

        // left and right ans nikalo
        bool leftans = solve(root->left,lowerbound ,root->val);
        bool rightans = solve(root->right, root->val,upperbound );

        if(cond1 && cond2 && leftans && rightans)
            return true;
        else
            return false;
        

    }
    bool isValidBST(TreeNode* root) {
        long long int lowerbound = -2147483657;
        long long int upperbound = 2147483657;
        bool ans = solve(root, lowerbound, upperbound);
        return ans;
    }
};
    
