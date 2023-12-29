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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        //pushing the roots in the queue
        if(root){
            q.push(root);
        }
        
        //this will be performed until there is a element in the queue
        while(!q.empty()){
             //q mai jitne element honge utni level size hogi
            int level_size = q.size();
            //vector level creation
            vector<int> level;
            //this will run until level size will not become zero or until its not empty
            while(level_size-- > 0){
                //front element ko acess kiya or uski value store ki and child add kiye
                TreeNode* cur = q.front(); 
                q.pop();
                level.push_back(cur->val);
                //addition of the childs
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            
            ans.push_back(level);
        }
        
        return ans;
    }
};
