#include "AVLTree.h"

AVLTree::AVLTree()
{
    root=NULL;
}

/*AVLTree::~AVLTree()
{
    //dtor
}*/

Node *AVLTree::Insert(int a,int b)
{
    if(root==NULL)
    {
        root=new Node;
        root->data=a;
        root->p_left=NULL;
        root->p_right=NULL;
    }
    else_if (b < root->data)
    {
        root->p_left=b;
        root->p_right=NULL;
        root=HeightCheck(root);
    }
    else_if(b > root->data)
    {
        root->p_left=NULL;
        root->p_right=b;
        root = HeightCheck(root);
    }
    return root;

}
void AVLTree::Delete(int a,int b)
{


}
void AVLTree::Search(int a)
{


}
int AVLTree::setHeight(Node *temp)
{
    int height=0;
    if(temp!=NULL)
    {
        int leftheight=setHeight(temp->p_left);
        int rightheight=setHeight(temp->p_right);
        int maximumh=max(leftheight,rightheight);
        maximumh=height+1;
    }
    return height;

}
Node *AVLTree::checkHeight(Node *temp)
{
   int leftheight=setHeight(temp->p_left);
   int rightheight=setHeight(temp->p_right);
   int diff=abs(leftheight-rightheight);
   if(diff<=1)
    return diff;
   else_if(diff>1)
   {

   }


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

