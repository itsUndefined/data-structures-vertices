#ifndef AVLTREE_H
#define AVLTREE_H

#include <vector>

class AVLTree
{
    public:
        AVLTree();
        ~AVLTree();
        void Insert(int value);
        void Purge();
        int& Search();


    protected:

    private:
        void rotation_L(Node *);
        void rotation_R(Node *);
        void rotation_LR(Node *);
        void rotation_RL(Node *);
        int setHeight(Node *);
        int Max(int a,int b);
        struct Node
        {
            int height;
            struct Node *root;
            struct Node *left_child;
            struct Node *right_child;
            int *neighbors;
        };
        struct Node head;


};

#endif // AVLTREE_H
