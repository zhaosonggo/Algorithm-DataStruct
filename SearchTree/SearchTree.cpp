#include"SearchTree.h"
#include<iostream>
#include<math.h>
using namespace std;

SearchTree::SearchTree(int *data, int len):m_root(nullptr)
{
    for(int i = 0;i<len;i++)
    {
        TreeNode *p = Insert(data[i]);
        //测试一下平衡的效果
        // // cout<<"\n{"<<depath(m_root)<<", "<<depath(m_root->lchild)<<", "<<depath(m_root->rchild)<<"}";
        balance(p);  //二叉树平衡
        // // cout<<" {"<<depath(m_root)<<", "<<depath(m_root->lchild)<<", "<<depath(m_root->rchild)<<"}\n";
        // PreOrder();
    }
        
}
void SearchTree::destory(TreeNode *root)
{
    if(root==nullptr)
        return;
    else{
        destory(root->lchild);
        destory(root->rchild);
        delete root;
        root = nullptr;
    }
}

SearchTree::~SearchTree()
{
    if(!m_root)  //如果是空树，就直接结束
        return;
    destory(m_root);
}
void SearchTree::Visit(TreeNode *node)
{
    cout<<node->value<<", ";
}
//小于的排左，大于的排右边
TreeNode * SearchTree::InsertRecusive(TreeNode *&root, int value)
{
    if(!root)
    {
        root = new TreeNode(value);
        return root;
    }
    if(value < root->value)
    {
        root->lchild = InsertRecusive(root->lchild, value);
        root->lchild->parent = root;
    }else{
        root->rchild = InsertRecusive(root->rchild, value);
        root->rchild->parent = root;
    }   
    return root;  
}
TreeNode *SearchTree::Insert(int value)  //会返回插入的节点的指针
{
    if(m_root == nullptr)
    {
        m_root = new TreeNode(value);
        return m_root;
    }    
    TreeNode *p, *q= m_root;
    while(1)
    {
        if(value < q->value)
        {
            if(q->lchild == nullptr)
            {
                p = new TreeNode(value);
                q->lchild = p;
                p->parent = q;
                return p;
            }
            q = q->lchild;             
        }   
        if(value > q->value)
        {
            if(q->rchild == nullptr)
            {
                p = new TreeNode(value);
                q->rchild = p;
                p->parent = q;
                return p;
            }
            q = q->rchild;            
        }          
    }
}
void SearchTree::InOrder()
{
    InOrder(m_root);
    cout<<endl;
}

void SearchTree::InOrder(TreeNode *root)
{
    if(root)
    {
        InOrder(root->lchild);
        Visit(root);
        InOrder(root->rchild);
    }
}

void SearchTree::PreOrder()
{
    PreOrder(m_root);
    cout<<endl;
}

void SearchTree::PreOrder(TreeNode *root)
{
    if(root)
    {
        Visit(root);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

TreeNode *SearchTree::Search(int value)
{
    return Search(value, m_root);
}

TreeNode *SearchTree::Search(int value, TreeNode *root)
{
    if(root == nullptr)
        return nullptr;
    if(value == root->value)
        return root;
    if(value < root->value)
        return Search(value, root->lchild);
    else
        return Search(value, root->rchild);
}


int SearchTree::depath()
{
    return depath(m_root);
}

int SearchTree::depath(TreeNode *root)
{
    if(root == nullptr)
        return 0;
    int ld = depath(root->lchild);
    int rd = depath(root->rchild);
    return ld > rd? ld+1:rd+1;
}

void SearchTree::leftRotate()
{
    cout<<endl<<"<---"<<m_root<<" | ";
    cout<<m_root->rchild<<" | ";
    m_root = leftRotate(m_root);
    cout<<m_root<<" | "<<endl;
}
//左旋操作
TreeNode * SearchTree::leftRotate(TreeNode * root)
{
    if(root == nullptr)
        return nullptr;
    TreeNode * rc = root->rchild;
    TreeNode * parent = root->parent;
    if(rc == nullptr)  //待旋转节点没有右孩子， 就不能左旋
        return root;
    TreeNode *rlc = rc->lchild;
    if(parent)  //如果存在父节点， 说明不是根节点，就要进行与根节点的一系列操作
    {
        if(parent->lchild == root)
            parent->lchild = rc;
        else
            parent->rchild = rc;
    }
    rc->parent = parent;
    if(rlc)  //如果右节点的左节点存在
        rlc->parent = root;
    root->rchild = rlc;
    rc->lchild = root;
    root->parent = rc;
    return rc;
}

void SearchTree::rightRotate()
{
    cout<<endl<<"--->"<<m_root<<" | ";
    cout<<m_root->lchild<<" | ";
    m_root = rightRotate(m_root);
    cout<<m_root<<" | \n";
}

TreeNode * SearchTree::rightRotate(TreeNode * root)
{
    if(root == nullptr)
        return nullptr;
    TreeNode * lc = root->lchild;
    TreeNode *parent = root->parent;
    if(lc == nullptr) //如果该节点没有左孩子，不可以进行右旋转
        return root;
    TreeNode *lrc = lc->rchild; //左节点的右孩子
    if(parent)  //如果父节点存在，就需要做一些父节点的操作啦
    {
        if(parent->lchild == root)
            parent->lchild = lc;
        else
            parent->rchild = lc;
    }
    lc->parent = parent;  //左节点的父节点设置为parent
    if(lrc)
        lrc->parent = root;
    root->lchild = lrc;
    lc->rchild = root;
    root->parent = lc;
    return lc;
}

void SearchTree::balance(TreeNode * node)
{
    if(!m_root) return;
    if(abs(depath(m_root->lchild) - depath(m_root->rchild)) <= 1) return; //代表插入没有影响
    //下面的代表该节点的插入影响了树的平衡
    TreeNode *q, *p = node->parent;
    while(abs(depath(p->lchild) - depath(p->rchild)) <= 1) //找到第一个受影响的节点，进行调整
    {
        q = p;
        p = p->parent;
    }   
    //左左， 直接右旋转
    if(q == p->lchild && node == node->parent->lchild)
    {
        if(p == m_root)  //为了对m_root实现更新
            m_root = rightRotate(p);
        else
            rightRotate(p);
        return;
    }   
    //左右， 先左后右
    if(q == p->lchild && node == node->parent->rchild)
    {
        leftRotate(node->parent);
        if(p == m_root)
            m_root = rightRotate(p);
        else
            rightRotate(p);
        return;
    }
    //右右
    if(q == p->rchild && node == node->parent->rchild)
    {
        if(p == m_root)
            m_root = leftRotate(p);
        else
            leftRotate(p);
        return;
    }   
    //右左
    if(q == p->rchild && node == node->parent->lchild)
    {
        rightRotate(node->parent);
        if(p == m_root)
            m_root = leftRotate(p);
        else
            leftRotate(p);
        return;
    }
}