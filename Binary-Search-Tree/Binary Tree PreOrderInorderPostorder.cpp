#include <bits//stdc++.h>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

void PreOrder(Node *root)
{
    if(root == NULL) return;

    printf("%c ", root->data); // visit data
    PreOrder(root->left); // visit left subtree
    PreOrder(root->right); // visit right subtree
}

void InOrder(Node *root)
{
    if(root == NULL) return;

    InOrder(root->left); // visit left subtree
    printf("%c ", root->data); // visit data
    InOrder(root->right); // visit right subtree
}

void PostOrder(Node *root)
{
    if(root == NULL) return;

    PostOrder(root->left); // visit left subtree
    PostOrder(root->right); // visit right subtree
    printf("%c ", root->data); // visit data
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
	//Print Nodes in Preorder.
	cout<<"Preorder: ";
	PreOrder(root);
	cout<<"\n";
	//Print Nodes in Inorder
	cout<<"Inorder: ";
	InOrder(root);
	cout<<"\n";
	//Print Nodes in Postorder
	cout<<"Postorder: ";
	PostOrder(root);
	cout<<"\n";
}
