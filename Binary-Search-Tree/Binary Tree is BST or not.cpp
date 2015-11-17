#include <bits//stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool isBST(Node *root)
{
    static Node *prev = NULL;

    if(root)
    {
        if(!isBST(root->left))
            return false;
        if(prev != NULL && root->data <= prev->data) {
            return false;
        }

        prev = root;

        return isBST(root->right);
    }
    return true;
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


	if(isBST(root)) printf("Yes\n");
	else printf("No\n");

	return 0;
}
