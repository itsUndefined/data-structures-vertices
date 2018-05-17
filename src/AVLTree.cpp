#include "AVLTree.h"
#include <cmath>

AVLTree::AVLTree()
{


}

AVLTree::~AVLTree()
{

}
void AVLTree::Insert(int a)
{
    Insert(a,&head);
}
Node *AVLTree::Insert(int a,Node *p)
{
    if(p==0)
    {
        p=new Node;
        p->value=a;
        p->left_child=0;
        p->right_child=0;

    }
    if (a < p->value)
    {
        p->left_child=Insert(a,p->left_child);
        rebalance(p);
    }
    if (a > p->value)
    {
        p->right_child=Insert(a,p->right_child);
        rebalance(p);

    }
    p->height=Max(setHeight(p->left_child), setHeight(p->right_child)) + 1;
    return p;
}

int AVLTree::setHeight(Node *temp)
{
    if(temp==0)
        return -1;
    return temp->height;
}
int AVLTree::Max(int a,int b)
{
    if(a>b)
        return a;
    if(b>a)
        return b;
    if (a==b)
        return a;
}
Node* AVLTree::rebalance(Node *p)
{
    int balance_factor = std::abs(setHeight(p->left_child - setHeight(p->right_child)));
    if(balance_factor<=1)
        return p;
    if(balance_factor>1)
    {
        if(setHeight(p->left_child)>setHeight(p->right_child))
            rotation_R(p);
        if(setHeight(p->left_child)>setHeight(p->right_child)&&(setHeight(p->left_child->right_child)>setHeight(p->left_child->left_child)))
            rotation_RL(p);
        if(setHeight(p->right_child)>setHeight(p->left_child))
            rotation_L(p);
       if(setHeight(p->left_child) > setHeight(p->right_child) && (setHeight(p->right_child->left_child) > setHeight(p->right_child->right_child)))
            rotation_LR(p);

    }


}
Node *AVLTree::rotation_L(Node *temp)
{
    Node *temp2;
    temp2=temp->right_child;
    temp2->left_child=temp;
    temp2->right_child=temp->right_child;
    return temp2;
}
Node *AVLTree::rotation_R(Node *temp)
{
    Node *temp2;
    temp2=temp->left_child;
    temp2->right_child=temp;
    temp2->left_child=temp->left_child;
    return temp2;
}
Node *AVLTree::rotation_LR(Node *temp)
{






}
Node *AVLTree::rotation_RL(Node *temp)
{


}
