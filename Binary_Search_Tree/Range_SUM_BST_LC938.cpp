
// APPROACH NO 1 


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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        // base case 
        if(!root) return 0;
        int ans = 0;

        bool wasinrange = false;
        
         // cond 1 if node is within range then call recursively left and right 
        if(root->val >= low && root->val <= high){
            wasinrange = true;
            ans+= root->val;
        }
        if(wasinrange){
            ans+= rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
        }

        //cond 2 - val < low then its in right subtree
        if(root->val < low){
            ans += rangeSumBST(root->right, low, high);
        }

        //cond 3 val > high then its in the left subtree 
        else if(root->val > high){
            ans += rangeSumBST(root->left, low, high);
        }
    
    return ans;

    }
};







// APPROACH NO 2 
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
    //Method 2 solution 
    void solve(TreeNode* root, int low, int high, int &sum){
        if(!root) return;
        //LEFT CALL
        solve(root->left, low, high, sum);

        //CHECK IF ITS IN THE RANGE THEN ADD IT 
        if(root->val >= low && root->val <= high){
            sum = sum + root->val;
        }
        //RIGHT CALL 
        solve(root->right, low, high, sum);

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    solve(root,low,high,sum);
    return sum;
    }
};
