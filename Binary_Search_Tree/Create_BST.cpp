#include <iostream>
#include<queue>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int value){
    this->data = value;
    this->left= NULL;
    this->right = NULL;
   }
};  
  
   Node* insertintoBST(Node* root, int data){
    //first node creation 
     if(root == NULL){
      root = new Node(data);
      return root;
     }
     //other than the first node 
     if(data > root->data){
      root->right = insertintoBST( root->right, data);
      }
    else{
      root->left = insertintoBST( root->left, data);
     }
     return root;
   }

   void levelorder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
      int temp = q.front();
      q.pop();
      if(temp == NULL){
        cout<<endl;
        if(q.empty()){
          q.push(NULL);
        }
      }
      else{
        cout<<" " <<temp->data<<endl;
        if(temp->left != NULL){
          q.push(temp->left);
        }
        if(temp->right != NULL){
          q.push(temp->right);
        }

      }
    }
   }

  void createBST(Node* & root){
  cout<<"Enter data: " <<endl;
  int data;
  cin>>data;

  while(data != -1){
    insertintoBST(data,root);
    cout<<"Enter data: " <<endl;
    cin>>data;
  }
  return root;
}

int main() {
  Node* root = NULL;
   createBST(root);
   levelorder(root)



  
  return 0;
}
