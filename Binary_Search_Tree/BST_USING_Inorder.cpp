Node* BSTusingInorder(int inorder[],int s, int e){
    // base case 
    if(s > e){
        return NULL;
    }
    // solve  1 case 
    int mid = ((s+e)/2);
    int element = inorder[mid];
    //create a root element
    Node* root = new Node(element);
    
    // recursive call left subtree
    root->left = BSTusingInorder(inorder,s,mid-1);
    //recursive call for the right subtreee 
    root->right = BSTusingInorder(inorder,mid+1, e);
    
    return root;
}
