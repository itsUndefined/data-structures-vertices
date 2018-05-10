#ifndef AVLTREE_H
#define AVLTREE_H


class AVLTree
{
    public:
        AVLTree();
        virtual ~AVLTree();
        void Insert(int a,int b);
        void Delete(int a,int b);
        int Search(int a);


    protected:

    private:
        void rotation_L();
        void rotation_R();
        void rotation_LR();
        void rotation_RL();
        void checkHeight();
        struct Node
        {
            int data;
            struct Node *p_left;
            struct Node *p_right;
            int *root;
        };

};

#endif // AVLTREE_H
