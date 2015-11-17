#include <bits//stdc++.h>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

// Using InOrder Concept. Just Reverse
void ReverseOrder(Node *root)
{
    if(root == NULL) return;

    ReverseOrder(root->right); // visit left subtree
    printf("%c ", root->data); // visit data
    ReverseOrder(root->left); // visit right subtree
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

	cout<<"ReverseOrder: ";
	ReverseOrder(root);
	cout<<"\n";

}
