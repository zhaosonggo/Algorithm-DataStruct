#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
// #include<iostream>
    // ~TreeNode()  //用来测试释放情况的
    // {
    //     std::cout<<"#";
    // }
class TreeNode
{
friend class BinaryTree; //友元，用来操作节点
protected:
    int value;
    TreeNode *lc;
    TreeNode *rc;
    TreeNode(int va):value(va), lc(nullptr), rc(nullptr){}
};
//-1代表空节点
class BinaryTree
{
typedef void (*optForTree)(TreeNode *);  //定义操作的函数指针，用于后期的方便，此处没有用上
private:
    TreeNode * m_root;
public:
    BinaryTree(const int *data, int len); //构造函数
    void PreOrder(); //先序非递归遍历整个树
    void ProOrderRecursive(); //先序递归遍历整个树
    void InOrder(); //中序非递归遍历整个树
    void InOrderRecursive(); //中序递归遍历整个树
    void PostOrder(); //后序非递归遍历
    void PostOrderRecursive(); //后序递归遍历
    void LayerOrder(); //层序遍历
    int LeafNumber(); //得到整棵树叶子节点的个数
    int size(); //得到整颗树节点的个数
    int depath(); //得到整棵树的深度
    int max(); //得到整棵树的最大值节点
    int min(); //得到整棵树的最小值节点
    void PreCreate(const int *data, int len); //依据先序序列生成二叉树
    void PostCreate(const int *data, int len); //依据后序序列生成二叉树
    void PreInCreate(int *pre, int *in, int len);//依据先序中序生成二叉树
    void PostInCreate(int *post, int *in, int len);//依据后序中序生成二叉树
    ~BinaryTree();
protected:
    void Create(const int *data, int len); //创建二叉树, 将*data转化成二叉树
    TreeNode * _PreCreate(const int *data, int len);//依据先序序列生成二叉树
    TreeNode * _PostCreate(const int *data, int len);//依据后序序列生成二叉树
    TreeNode * _PreInCreate(int *startPre,int *endPre,int *startIn,int *endIn);//依据先序中序生成二叉树
    TreeNode * _PostInCreate(int *startPost,int *endPost,int *startIn,int *endIn);//依据先序中序生成二叉树
    void PreOrder(TreeNode *root); //先序非递归遍历指定节点为根的二叉树  
    void ProOrderRecursive(TreeNode *root); //先序递归遍历整个树
    void InOrder(TreeNode *root); //中序非递归遍历整个树
    void InOrderRecursive(TreeNode *root); //中序递归遍历整个树
    void PostOrder(TreeNode *root); //后序非递归遍历
    void PostOrderRecursive(TreeNode *root); //后序递归遍历
    void LayerOrder(TreeNode *root);//层序遍历
    void Visit(TreeNode *node); //访问对应的节点
    int LeafNumber(TreeNode *root);//叶子节点个数
    int size(TreeNode *root); //节点的个数
    int depath(TreeNode *root); //得到树的深度
    int max(TreeNode *root); //得到最大值节点
    int min(TreeNode *root); //得到最小值节点
    void destory(TreeNode *root); //删除整个树
};

#endif