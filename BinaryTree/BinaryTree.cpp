#include"BinaryTree.h"
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
//自定义的一个异常类
class Inputexception:public exception
{
private:
    const char *str = nullptr;
public:
    Inputexception(const char *str):str(str){}
    const char *what() const noexcept
    {
        return str;
    }
};
//构造函数，通过转调Create 将*data的所有数据生成一个二叉树，其中-1代表空节点
BinaryTree::BinaryTree(const int *data, int len)
{
    m_root = nullptr;
    Create(data, len);
}
//节点的个数
int BinaryTree::size()
{
    return size(m_root);
}
int BinaryTree::size(TreeNode *root)
{
    if(root == nullptr)
        return 0;
    if(root->lc == nullptr && root->rc == nullptr)
        return 1;
    else    
        return size(root->lc) + size(root->rc) + 1;
}
//树的深度
int BinaryTree::depath()
{
    return depath(m_root);
}
int BinaryTree::depath(TreeNode *root)
{
    if(root == nullptr)
        return -1; 
    else
    {
        int lnum = depath(root->lc);
        int rnum = depath(root->rc);
        return lnum > rnum ? lnum+1:rnum+1;
    }
        
}
//最大值
int BinaryTree::max()
{
    return max(m_root);
}
int BinaryTree::max(TreeNode *root)
{
    if(root == nullptr)
        return -1; //错误码
    if(root->lc == nullptr &&root->rc == nullptr)
    {
        return root->value;
    }else{
        if(!root->lc)
        {
            int rmax = max(root->rc);
            return root->value > rmax?root->value:rmax;
        }
        if(!root->rc)
        {
            int lmax = max(root->lc);
            return root->value > lmax?root->value:lmax;
        }
        if(root->lc&&root->rc)
        {
            int lmax = max(root->lc);
            int rmax = max(root->rc);
            return rmax>lmax?(rmax>root->value?rmax:root->value):(lmax>root->value?lmax:root->value);
        }
    }
}
//最小值
int BinaryTree::min()
{
    return min(m_root);
}
int BinaryTree::min(TreeNode *root)
{
    if(root == nullptr)
        return -1; //错误码
    if(root->lc == nullptr &&root->rc == nullptr)
    {
        return root->value;
    }else{
        if(!root->lc)
        {
            int rmax = max(root->rc);
            return root->value < rmax?root->value:rmax;
        }
        if(!root->rc)
        {
            int lmax = max(root->lc);
            return root->value < lmax?root->value:lmax;
        }
        if(root->lc&&root->rc)
        {
            int lmax = max(root->lc);
            int rmax = max(root->rc);
            return rmax<lmax?(rmax<root->value?rmax:root->value):(lmax<root->value?lmax:root->value);
        }
    }
}
//生成树函数
void BinaryTree::Create(const int *data, int len)
{
    if(data == nullptr || len <= 0)
        return;
    queue<TreeNode *> QforTree;
    m_root = new TreeNode(data[0]); //创建根节点
    QforTree.push(m_root);
    int i = 1;
    while(i<len)
    {
        TreeNode * p = QforTree.front(); //取出队列中第一个元素
        if(data[i] != -1)
        {
            p->lc = new TreeNode(data[i]);
            QforTree.push(p->lc);
        }
        ++i;
        if(i<len && data[i]!=-1)
        {
            p->rc = new TreeNode(data[i]);
            QforTree.push(p->rc);
        }
        ++i;
        QforTree.pop();
    }   
}
//删除树每个节点占用的堆空间
void BinaryTree::destory(TreeNode *root)
{
    if(root==nullptr)
        return;
    else{
        destory(root->lc);
        destory(root->rc);
        delete root;
        root = nullptr;
    }
}
//析构函数，使用层序遍历的方法，将二叉树中每个节点的堆内存进行释放
BinaryTree::~BinaryTree()
{
    if(!m_root)  //如果是空树，就直接结束
        return;
    destory(m_root);
}
void BinaryTree::Visit(TreeNode * node)
{
    if(node)
        cout<<node->value<<", ";
}
//先序遍历 recursive, 转调对应的保护函数
void BinaryTree::ProOrderRecursive()
{
    ProOrderRecursive(m_root);
    cout<<endl;
}
void BinaryTree::ProOrderRecursive(TreeNode *root)
{
    if(root)
    {
        Visit(root);
        ProOrderRecursive(root->lc);
        ProOrderRecursive(root->rc);
    }
}
//非递归先序遍历, 转调对应的保护函数
void BinaryTree::PreOrder()
{
    PreOrder(m_root);
    cout<<endl;
}
void BinaryTree::PreOrder(TreeNode *root)
{
    if(!root)
        return;
    stack<TreeNode *> SforTree;
    TreeNode *p = root;
    while(1)
    {
        if(p == nullptr)  //如果节点为空
        {
            if(SforTree.empty()) //尝试从栈中取下一个节点，如果栈为空，就结束
                break;
            else
            {
                p = SforTree.top(); //栈不为空，指向下一个节点
                SforTree.pop();     //栈中减一
            }
        }else
        {
            Visit(p); //不为空，输出当前节点
            if(p->rc) //如果有右节点，右节点入栈
                SforTree.push(p->rc);
            p = p->lc; //指向左节点
        }       
    }
}
//中序遍历recursive, 转调对应的保护函数
void BinaryTree::InOrderRecursive()
{
    InOrderRecursive(m_root);
    cout<<endl;
}
void BinaryTree::InOrderRecursive(TreeNode *root)
{
    if(root)
    {
        InOrderRecursive(root->lc);
        Visit(root);
        InOrderRecursive(root->rc);
    }
}
//中序遍历非递归，转调对应的保护函数
void BinaryTree::InOrder()
{
    InOrder(m_root);
    cout<<endl;
}
void BinaryTree::InOrder(TreeNode *root)
{
    if(!root)
        return;
    stack<TreeNode *> SforTree;
    TreeNode *p = root;
    while(1)
    {
        if(p)
        {
            SforTree.push(p);
            p = p->lc;
        }else
        {
            if(SforTree.empty())
                break;
            p = SforTree.top();
            Visit(p);
            p = p->rc;
            SforTree.pop();
        }
    }
}

//后序递归遍历， 转调对应的保护函数
void BinaryTree::PostOrderRecursive()
{
    PostOrderRecursive(m_root);
    cout<<endl;
}
void BinaryTree::PostOrderRecursive(TreeNode *root)
{
    if(root)
    {
        PostOrderRecursive(root->lc);
        PostOrderRecursive(root->rc);
        Visit(root);
    }
}
//后序遍历非递归， 转调对应的保护函数
void BinaryTree::PostOrder()
{
    PostOrder(m_root);
    cout<<endl;
}
void BinaryTree::PostOrder(TreeNode *root)
{
    if(!root)
        return;
    TreeNode * q[1000]; //自己搭建的一个栈
    TreeNode *p = root;
    int i = 0, flag[1000], b; //flag代表是否访问过
    while(1)
    {
        if(p) //只要节点不为0，就入栈，并设置对应位为0，代表没有访问过
        {
            q[i] = p;
            flag[i++] = 0;
            p = p->lc;
        }else{ //节点为0，就从栈顶取
            if(i == 0) //栈中没有数据，结束
                break;
            b = flag[--i];  //得到是否访问过的标志
            p = q[i];       //得到栈顶
            if(b == 0)      //如果之前没有访问过
            {
                flag[i++] = 1;  //修改表示，本次已经访问
                p = p->rc;      //指向右节点
            }else{
                Visit(p);       //如果之前访问过， 那么对其操作
                p = nullptr;    //设置null, 从而使得下一次操作从栈中取
            }
        }
    }
}
//层序遍历，转调对应的保护函数
void BinaryTree::LayerOrder()
{
    LayerOrder(m_root);
    cout<<endl;
}
void BinaryTree::LayerOrder(TreeNode *root)
{
    if(!root)
        return;
    queue<TreeNode *> QforTree;
    TreeNode *p = root;
    QforTree.push(p);
    while(!QforTree.empty())
    {
        p = QforTree.front();
        Visit(p);
        if(p->lc)
            QforTree.push(p->lc);
        if(p->rc)
            QforTree.push(p->rc);
        QforTree.pop();
    }
}
//叶子节点个数
int BinaryTree::LeafNumber()
{
    return LeafNumber(m_root);
}
int BinaryTree::LeafNumber(TreeNode *root)
{
    if(!root)
        return 0;
    if(root->rc == nullptr && root->lc == nullptr)
        return 1;
    else
        return LeafNumber(root->lc) + LeafNumber(root->rc);
}
//依据先序序列生成二叉树
void BinaryTree::PreCreate(const int *data, int len)
{
    if(data == nullptr || len<0)
        return;
    destory(m_root);
    m_root = _PreCreate(data, len);
}
TreeNode * BinaryTree::_PreCreate(const int *data, int len)
{
    static int i = 0;
    if(i == len)
        return nullptr;
    int value;
    value = data[i++];
    if(value == -1)
        return nullptr;
    TreeNode *root = new TreeNode(value);
    root->lc = _PreCreate(data, len);
    root->rc = _PreCreate(data, len);
    return root;
}
//依据后序序列生成二叉树
void BinaryTree::PostCreate(const int *data, int len)
{
    if(data == nullptr || len<0)
        return;
    destory(m_root);
    m_root = _PostCreate(data, len);
}
TreeNode * BinaryTree::_PostCreate(const int *data, int len)
{
    static int i = len - 1;
    if(i<0)
        return nullptr;
    int value = data[i--];
    if(value == -1)
        return nullptr;
    TreeNode *root = new TreeNode(value);
    root->rc = _PostCreate(data, len);
    root->lc = _PostCreate(data, len);
    return root;
}

//依据先序和中序生成二叉树
void BinaryTree::PreInCreate(int *pre, int *in, int len)
{
    if(pre == nullptr || in == nullptr || len <= 0)
        return;
    TreeNode *_m_root = m_root;
    try{
        m_root = _PreInCreate(pre, pre+len-1, in, in+len-1);
    }catch(const exception &e)
    {
        cout<<e.what();
        return;
    }
    destory(_m_root);
    
}
TreeNode * BinaryTree::_PreInCreate(
    int *startPre, 
    int *endPre, 
    int *startIn, 
    int *endIn)
{
//前序遍历的第一个元素是根节点的值
    int rootValue = startPre[0];
    TreeNode *root = new TreeNode(rootValue);

    if(startPre == endPre) //如果先序遍历序列只有一个元素了
    {
        if(startIn == endIn && *startPre == *startIn)
        {  //如果同时中序也只有一个元素，而且和先序的唯一元素相等，此时就是一个
           //单独的节点
            return root;
        }else{
            // throw std::exception("Invalid Input");
            delete root;
            throw Inputexception("input valid");
        }
    }

    //中序遍历序列中找到根节点，那么左边就是左子树的节点set
    //右边就是右子树的节点set
    int *rootIn = startIn;
    while(rootIn <= endIn && *rootIn != rootValue)
        ++rootIn;
    
    //如果找到最后了，也没有发现和根相同的那么序列本身是错误的
    if(rootIn == endIn && *rootIn != rootValue)
        throw Inputexception("input valid");

    int leftLength = rootIn - startIn; //得到左子树的长度
    int *leftPreEnd = startPre + leftLength;//得到左子树的先序遍历序列下标
    if(leftLength > 0)
    {
        root->lc = _PreInCreate(startPre + 1, leftPreEnd,
                                startIn, rootIn-1);
    }
    if(leftLength < endPre - startPre) //右子树还有节点
    {
        root->rc = _PreInCreate(leftPreEnd+1, endPre,
                                rootIn+1, endIn);
    }
    return root;
}

//依据后序中序生成二叉树
void BinaryTree::PostInCreate(int *post, int *in, int len)
{
    if(post == nullptr || in == nullptr || len <0)
        return;
    TreeNode *_m_root = m_root;
    try{
        m_root = _PostInCreate(post, post+len-1, in, in+len-1);
    }catch(const exception &e)
    {
        cout<<e.what();
        return;
    }
    destory(_m_root);
}

TreeNode * BinaryTree::_PostInCreate(
    int *startPost,
    int *endPost,
    int *startIn,
    int *endIn)
{
    //得到根节点，后续节点的最后一个元素
    int rootvalue = *endPost;
    TreeNode *root = new TreeNode(rootvalue);
    if(startPost == endPost)
    {
        if(startIn == endIn && *startIn == *startPost)
        {
            return root;
        }else{
            delete root;
            throw Inputexception("input valid");
        }
    }

    //找出中序序列中的根节点
    int *rootIn = startIn;
    while(rootIn <= endIn && *rootIn != rootvalue)
        ++rootIn;
    if(rootIn == endIn && *rootIn!=rootvalue)
        throw Inputexception("input valid"); //抛出异常
    
    int LeftLength = rootIn - startIn;
    int *LeftPostEnd = startPost + LeftLength - 1;
    if(LeftLength > 0)
    {
        root->lc = _PostInCreate(startPost, LeftPostEnd, startIn, rootIn-1);
    }   

    if(LeftLength < endPost - startPost)
    {
        root->rc = _PostInCreate(LeftPostEnd+1, endPost - 1,rootIn+1, endIn);
    }
    return root;
}