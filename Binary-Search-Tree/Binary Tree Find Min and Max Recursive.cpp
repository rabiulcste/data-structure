#include <bits//stdc++.h>

using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, int data) {
    if(root == NULL) { // empty tree
        root = GetNewNode(data);
    }

    else if(data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

int FindMin(BstNode* root)
{
    if(root == NULL)
    {
        cout<<"Error: Tree is Empty"<<endl;
        return -1;
    }
    else if(root->left == NULL) {
        return root->data;
    }

    // Search in left subtree
    return FindMin(root->left);
}

int FindMax(BstNode* root)
{
    if(root == NULL)
    {
        cout<<"Error: Tree is Empty"<<endl;
        return -1;
    }
    else if(root->right == NULL){
        return root->data;
    }
    return FindMax(root->right);
}


int main()
{
    BstNode* root = NULL;

    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    int mini = FindMin(root);
    int maxi = FindMax(root);
    cout << "Minimum value is " << mini << endl;
    cout << "Maximum value is " << maxi << endl;

    return 0;
}
