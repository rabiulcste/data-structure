#include <bits//stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    Node *left, *right;
} Node;

Node *newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data  = data;
    node->left  = node->right = NULL;
    return(node);
}

Node *LCA(Node *root, int p, int q) {
    if (!root) return NULL;
    if (root->data == p || root->data == q) return root;
    // get LCA of p and q in left subtree
    Node *L = LCA(root->left, p, q);
    // get LCA of p and q in right subtree
    Node *R = LCA(root->right, p, q);
    // if any of p or q is in left subtree and other in right : root is LCA
    if (L && R) return root;
    return L ? L : R;  // either one of p,q is on one side OR p,q is not in L&R subtrees
}


int main()
{
    Node *root               = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 22, n2 = 14;
    // int l = 0, r =0;
    struct Node *t = LCA(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    getchar();
    return 0;
}
