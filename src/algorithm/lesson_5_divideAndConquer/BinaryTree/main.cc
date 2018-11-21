#include <iostream>
#include "binaryTree.h"

using namespace std;

int main()
{
    node *root = new node('a');
    root->left = new node('b');
    root->right = new node('c');
    root->right->left = new node('f');
    root->left->left = new node('d');
    root->left->left->right = new node('g');
    root->left->right = new node('e');

    cout << height(root) << endl;
    cout << ">>>>>>>>>" << endl;
    preOrderTraversal(root);
    cout << ">>>>>>>>>" << endl;
    inOrderTraversal(root);
    cout << ">>>>>>>>>" << endl;
    postOrderTraversal(root);
    return 0;
}