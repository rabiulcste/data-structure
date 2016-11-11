/*  In a given binary tree, The low­est com­mon ances­tor
    of two nodes n1 and n2 will be a node X
    such that node X will be the low­est
    node who has n1 and n2 as its descendants.

    Appraoch:
    1. Start will the root.
    2. If root>n1 and root>n2 then low­est com­mon ances­tor will be in left subtree.
    3. If root<n1 and root<n2 then low­est com­mon ances­tor will be in right subtree.
    4. If Step 2 and Step 3 is false then we are at the root
       which is low­est com­mon ances­tor, return it.
*/

#include <stdio.h>
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* left, *right;
}*p = NULL;

struct node *lca(struct node* root, int n1, int n2)
{
    if (root == NULL)
	return NULL;

    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);

    return root;
}
struct node* newNode(int data)
{
    p = new node;
    p->data = data;
    p->left = p->right = NULL;
    return(p);
}
int main()
{
    struct node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    struct node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
}
