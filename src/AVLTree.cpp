#include "AVLTree.h"


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
        //Right Rotations
        //Otan exoume thema me deksi paidi aristerou ypodentrou
        //kanoume RL rotation
    }
    if (a > p->value)
    {
        p->right_child=Insert(a,p->right_child);
       //Left Rotations
       //Otan exoume thema me aristero paidi deksiou ypodentrou
       //kanoume LR Rotations

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

Node *AVLTree::rotation_L(Node *temp)
{

}
Node *AVLTree::rotation_R(Node *temp)
{

}
Node *AVLTree::rotation_LR(Node *temp)
{


}
Node *AVLTree::rotation_RL(Node *temp)
{


}
/* void AVLTree::Purge(int a,int b)
{






}
int& AVLTree::Search(int a)
{











}*/
