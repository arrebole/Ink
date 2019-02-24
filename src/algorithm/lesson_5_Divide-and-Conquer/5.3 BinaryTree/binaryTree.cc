#include <stdio.h>
#include "binaryTree.h"

int height(node *t)
{
    if (t == nullptr)
        return -1;
    else
        return max(height(t->left), height(t->right)) + 1;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

// 前序遍历
void preOrderTraversal(node *root)
{
    if (root != nullptr)
    {
        printf("%c\n", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// 中序遍历
void inOrderTraversal(node *root)
{
    if (root != nullptr)
    {
        inOrderTraversal(root->left);
        printf("%c\n", root->data);
        inOrderTraversal(root->right);
    }
}

// 后序遍历
void postOrderTraversal(node *root)
{
    if (root != nullptr)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%c\n", root->data);
    }
}