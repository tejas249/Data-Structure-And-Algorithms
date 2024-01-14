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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;

        // ans.push_back((double)root->val)
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty())
        {
            int size=qt.size();
            double sum=0;
            for(int i=0;i<size;i++)
            {
               TreeNode* temp=qt.front();
               qt.pop();
               sum=sum+double(temp->val);

               if(temp->left)
               {
                   qt.push(temp->left);
               }
               if(temp->right)
               {
                   qt.push(temp->right);
               }
            }
            ans.push_back(sum/size);
        }

        return ans;
        
    }
};
