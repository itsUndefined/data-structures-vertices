#include "AVLTree.h"

AVLTree::AVLTree()
{
    root=NULL;
}

/*AVLTree::~AVLTree()
{
    //dtor
}*/

void AVLTree::Insert(int a,int b)
{
    if(root==NULL)
        root=&a;
    if (b<a)
    {
        p_left->b;
        p_right=NULL;
    }
    if(b>a)
    {
        p_right->b;
        p_left=NULL;
    }
}
void AVLTree::Delete(int a,int b)
{


}
void AVLTree::Search(int a)
{


}
void AVLTree::rotation_L()
{


}
void AVLTree::rotation_R()
{

}
void AVLTree::rotation_LR()
{

}
void AVLTree::rotation_RL()
{

}
void AVLTree::checkHeight()
{


}
