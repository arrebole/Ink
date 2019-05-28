/**
 * 二叉查找树：Binary Search Tree
 * 
*/
#include <iostream>
using namespace std;
//-------------二叉树节点-------------------------------

struct BST_node
{
    int data;
    BST_node *left;
    BST_node *right;

    BST_node(int _data);
    ~BST_node();
};

BST_node::BST_node(int _data)
{
    data = _data;
    left = nullptr;
    right = nullptr;
}

BST_node::~BST_node()
{
    delete left;
    delete right;
}

//---------------二叉查找树------------------------------

class BST_tree
{
  protected:
    // 根节点
    struct BST_node *root;

  public:
    // 构造和析构
    BST_tree();
    ~BST_tree();

    // 二叉查找树添加节点
    // item：需要添加的节点数据，t：插入位置，默认传入根节点自动匹配插入位置
    struct BST_node *inseart(int item);
    // 二叉查找树查找
    int search(int key);
};

// 构造函数
BST_tree::BST_tree()
{
    this->root = nullptr;
}

// 释放内存
BST_tree::~BST_tree()
{
    delete root;
}

// 二叉查找树的插入
struct BST_node *BST_tree::inseart(int item)
{
    BST_node *local = this->root;
    // 不存在根节点时 将数据创建为根节点
    if (this->root == nullptr)
    {
        this->root = new BST_node(item);
        local = this->root;
        return local;
    }
    // 迭代寻找合适的节点插入数据
    while (true)
    {
        // 如果节点适合则插入
        if (local->left == nullptr && item <= local->data)
        {
            local->left = new BST_node(item);
            local = local->left;
            return local;
        }
        if (local->right == nullptr && item >= local->data)
        {
            local->right = new BST_node(item);
            local = local->right;
            return local;
        }
        // 如果节点不适合则切换
        if (local->left != nullptr && item <= local->data)
        {
            local = local->left;
        }
        else if (local->right != nullptr && item >= local->data)
        {
            local = local->right;
        }
    }
    return local;
}

// 二叉查找树的查找
int BST_tree::search(int key)
{
    // 将当前节点指向根节点
    BST_node *local = this->root;
    while (local != nullptr)
    {
        // 匹配成功则返回数据
        if (key == local->data)
        {
            return local->data;
        }

        // 不匹配则左右切换
        if (key >= local->data)
        {
            local = local->right;
        }
        else if (key <= local->data)
        {
            local = local->left;
        }
    }
    return local->data;
}

