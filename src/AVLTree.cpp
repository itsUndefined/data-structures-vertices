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
void AVLTree::Purge(int a,int b)
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
   if(diff>1)
   {
       if(rightheight>leftheight)
       {
           rotation_L(temp);
           if

       }
       if (leftheight>rightheight)
       {
           rotation_R(temp);
           if

       }


   }


}
Node *AVLTree::rotation_L(Node *temp)
{
    Node *temp1;
    temp1=temp->p_left; //p_right
    temp1->p_left=temp->p_right; //temp
    temp1->p_right=temp; //p_left
    return temp1;

}
Node *AVLTree::rotation_R(Node *temp)
{
    Node *temp2;
    temp2=temp->p_right; //p_left
    temp2->p_right=temp->p_left; //temp
    temp2->p_left=temp; //p_right
    return temp2;
}
Node *AVLTree::rotation_LR(Node *temp)
{
    Node *temp1;
    temp1=temp->p_left;
    temp1->p_left=temp->p_right;
    temp1->p_right=temp;
    rotation_R(temp1);

}
Node *AVLTree::rotation_RL(Node *temp)
{
    Node *temp2;
    temp2=temp->p_right;
    temp2->p_right=temp->p_left;
    temp2->p_left=temp;
    rotation_L(temp2);

}

