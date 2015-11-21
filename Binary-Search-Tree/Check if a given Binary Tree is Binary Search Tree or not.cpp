#include <bits//stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool isBST(Node *root, int mini, int maxi)
{

    if(root== NULL) return true;

    if(root->data <= mini || root->data > maxi){
        return false;
    }

    return isBST(root->left, mini, root->data) && isBST(root->right, root->data, maxi);
}

Node* newNode(int data) {
  struct Node* node = new Node();
  node->data = data;
  node->left = node->right = NULL;

  return(node);
}

int main()
{
    struct Node *root = newNode(4);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);


	if(isBST(root, -99999, 99999)) printf("Yes\n");
	else printf("No\n");

	return 0;
}
