//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution{

public:
    int floor(Node* root, int input) {
        // Code here
         int floor = -1;
    
    while (root)
    {
        // If the input is already available in BST, return that.
        if (root->data == input)
            return input;

        // If the input is greater than root, we mark floor to be root and move to 
        // right subtree where it may be further closer to the input value
        else if (root->data < input)
        {
            floor = root->data;
            root = root->right;
        }

        // the floor value must be in the left subtree.
        else
        {
            root = root->left;
        }
    }

    //Return computed floor value.
    return floor;
    }
};

//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends
