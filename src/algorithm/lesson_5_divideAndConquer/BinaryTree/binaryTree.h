
struct node
{
    char data;
    node *left;
    node *right;
    node(char ch) : data(ch)
    {
        this->left = nullptr;
        this->right = nullptr;
    };

};

// 计算树的高度
int height(node *t);
int max(int a, int b);

// 先序遍历
void preOrderTraversal(node *root);
// 中序遍历
void inOrderTraversal(node *root);
// 后序遍历
void postOrderTraversal(node *root);