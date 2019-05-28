#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    int a[12] = {3, 7, 28, 21, 28, 50, 70, 69, 30, 69, 10, 39};
    BST_tree tree;
    for (int i = 0; i < 12; i++)
    {
        tree.inseart(a[i]);
    }
    cout << tree.search(28);
    return 0;
}