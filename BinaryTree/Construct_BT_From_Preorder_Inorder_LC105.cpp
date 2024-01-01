class Solution {
    
    // this function will search in inorder
    int search(vector<int>& inorder,int key,int start,int end){
        for(int i=start;i<=end;i++){
            if(inorder[i]==key)return i;
        }
        return INT_MIN;
    }
    
    TreeNode* getTree(vector<int>& preorder,vector<int>&inorder,int start,int end,int &preIndex){
        
        //base case
        if(start>end)return NULL;
         
        // preorder ka first element root hota hai 
        TreeNode* root= new TreeNode(preorder[preIndex]);
        preIndex++;
        //search call
        if(start==end)return root;
        int rootIndex=search(inorder,root->val,start,end);
        // recursive call for left and right function
        root->left=getTree(preorder,inorder,start,rootIndex-1,preIndex);
        root->right=getTree(preorder,inorder,rootIndex+1,end,preIndex); 
        //returning the root
        return root;
    }
        
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int preIndex=0;
        return getTree(preorder,inorder,0,(int)preorder.size()-1,preIndex);
    }
};
