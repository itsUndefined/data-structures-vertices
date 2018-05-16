#include "AVLTree.h"

AVLTree::AVLTree()
{
    root=NULL;
}

AVLTree::~AVLTree()
{
    //dtor
}
void Insert(int a)
{
    root=Insert(int a,root)
}
Node *AVLTree::Insert(int a,Node *p)
{
    if(p==NULL)
    {
        p=new Node;
        p->value=a;
        p->left_child=NULL;
        p->right_child=NULL;

    }
    if (a < p->data)
    {
        p->left_child=Insert(a,p->left_child)
        //ROTATIONS

    }
    if (a > p->data)
    {
        p->right_child=Insert(a,p->right_child)
        //ROTATIONS
    }
    p->height=Max(setHeight(p->left_child), setHeight(p->right_child)) + 1
    return p;
}

int AVLTree::setHeight(Node *temp)
{
    if(temp=NULL)
        return -1;
    return temp->height;
}
int AVLTree::Max(int a,int b)
{
    if(a>b)
        return a;
    if(b>a)
        return b;
    if (a=b)
        return a;
}

Node *AVLTree::rotation_L(Node *temp)
{
    Node *temp1;
    temp1=temp->left_child;
    temp1->left_child=temp->right_child;
    temp1->right_child=temp->root;
    return temp1;

}
Node *AVLTree::rotation_R(Node *temp)
{
    Node *temp2;
    temp2=temp->right_child;
    temp2->right_child=temp->left_child;
    temp2->left_child=temp->root;
    return temp2;
}
Node *AVLTree::rotation_LR(Node *temp)
{
    Node *temp1;
    temp1=temp->left_child;
    temp1->left_child=temp->right_child;
    temp1->right_child=temp->root;
    rotation_R(temp1);

}
Node *AVLTree::rotation_RL(Node *temp)
{
    Node *temp2;
    temp2=temp->right_child;
    temp2->right_child=temp->left_child;
    temp2->left_child=temp->root;
    rotation_L(temp2);

}
/* void AVLTree::Purge(int a,int b)
{






}
int& AVLTree::Search(int a)
{











}*/
