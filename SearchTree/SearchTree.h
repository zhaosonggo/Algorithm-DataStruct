#ifndef __SEARCHTREE_H__
#define __SEARCHTREE_H__

class TreeNode
{
friend class SearchTree;
public:
    int getValue()
    {
        return value;
    }
protected:
    int value;
    TreeNode *lchild;
    TreeNode *rchild;
    TreeNode *parent;
    TreeNode(int value):value(value){lchild=rchild=parent=nullptr;}
};

class SearchTree
{
private:
    TreeNode *m_root;
public:
    SearchTree(){m_root=nullptr;}
    SearchTree(int *data, int len);
    TreeNode *  InsertRecusive(TreeNode *&root, int value);
    TreeNode *Insert(int value);
    void InOrder(); //中序遍历算法
    void PreOrder(); //中序遍历算法
    TreeNode * Search(int value); //查找对应的值，返回对应的指针
    int depath();
    //---------------------------------
    void leftRotate();  //这两个旋转测试用，只用来旋转根节点
    void rightRotate();
    //---------------------------------
    ~SearchTree();
protected:
    void InOrder(TreeNode *root);
    void PreOrder(TreeNode *root);
    void Visit(TreeNode *node);
    void destory(TreeNode *root);
    void balance(TreeNode * node);  //平衡二叉树
    int depath(TreeNode *root);
    TreeNode * leftRotate(TreeNode *root); //左旋操作
    TreeNode * rightRotate(TreeNode *root); //右旋操作
    TreeNode *Search(int value, TreeNode *root);
};
#endif