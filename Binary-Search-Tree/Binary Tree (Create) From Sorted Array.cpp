#include <bits//stdc++.h>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

// create a new tree from a sorted array
Node* addToBST(Node *root, char arr[], int start, int end) {

    if(end<start) return NULL;
    int mid = (start+end)/2;
    if(root == NULL) {
        root = new Node();
        root->data = arr[mid];
        // printf("%c ", root->data);
        root->left = root->right =NULL;
    }

    root->left = addToBST(root->left, arr, start, mid-1);
    root->right= addToBST(root->right, arr, mid+1, end);
    return root;
}

void InOrder(Node *root)
{
    if(root == NULL) return;

    InOrder(root->left); // visit left subtree
    printf("%c ", root->data); // visit data
    InOrder(root->right); // visit right subtree
}

int main()
{
    Node* root = NULL;
    char Arr[9]
	    = {'A','B','C','D','E','F','G','H','I'};
    root = addToBST(root, Arr, 0, 8);
    InOrder(root);
}
