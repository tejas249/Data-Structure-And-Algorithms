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
    void help(TreeNode *root,vector<int> &s)
    {
        if(root == NULL)
        {
            return;
        }
        help(root->left,s);
        s.push_back(root->val);
        help(root->right,s);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>s;
        help(root,s);
        int i=0,j=s.size()-1;
        while(i < j)
        {
            int sum = s[i]+s[j];
            if(sum == k)
            {
                return true;
            }
            else if(sum < k)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return false;
    }
};
