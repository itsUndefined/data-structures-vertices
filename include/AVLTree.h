#ifndef AVLTREE_H
#define AVLTREE_H


class AVLTree
{
    public:
        AVLTree();
        virtual ~AVLTree();
        void Insert(int a,int b);
        void Purge(int a,int b);
        int Search(int a);


    protected:

    private:
        void rotation_L(Node *);
        void rotation_R(Node *);
        void rotation_LR(Node *);
        void rotation_RL(Node *);
        void checkHeight(Node *);
        int setHeight(Node *);
        struct Node
        {
            int data;
            struct Node *p_left;
            struct Node *p_right;
            int *root;
        };

};

#endif // AVLTREE_H
