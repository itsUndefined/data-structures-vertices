#ifndef AVLTREE_H
#define AVLTREE_H

struct Node
        {
            int height;
            int value;
            struct Node *left_child;
            struct Node *right_child;
        };
class AVLTree
{
    public:
        AVLTree();
        ~AVLTree();
        void Insert(int value);
        Node*Insert(int a,Node *p);
        void Purge();
        int& Search();


    protected:

    private:
        Node* rotation_L(Node *);
        Node* rotation_R(Node *);
        Node* rotation_LR(Node *);
        Node* rotation_RL(Node *);
        int setHeight(Node *);
        int Max(int a,int b);
        struct Node head;


};

#endif // AVLTREE_H
