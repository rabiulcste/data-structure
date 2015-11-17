#include <bits//stdc++.h>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

// Converting a BST into an Array
void BSTtoArray(Node *root, char A[])
{
    static int pos = 0;
    if(root == NULL) return;

    BSTtoArray(root->left, A);
    A[pos++] = root->data;
    BSTtoArray(root->right, A);

}

int treeSize(Node* root) {
    if(root == NULL) return 0;
    else
        return treeSize(root->left) + treeSize(root->right) + 1;
}

Node* Insert(Node *root, char data)
{
    if(root == NULL) {
        root = new Node();
        root->data = data;
        root->left = root->right =NULL;
    }
    else if(data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);

    return root;
}

int main()
{
    /*Code To Test the logic
	  Creating an example tree
                M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
	Node* root = NULL;
	root = Insert(root,'M'); root = Insert(root,'B');
	root = Insert(root,'Q'); root = Insert(root,'Z');
	root = Insert(root,'A'); root = Insert(root,'C');

    int treeSZ = treeSize(root);
    char *A = new char[treeSZ];
    BSTtoArray(root, A);
	cout << "New Array : ";
	for(int i = 0; i < treeSZ; i++)
        cout << A[i] << " ";
	cout << endl;

}
