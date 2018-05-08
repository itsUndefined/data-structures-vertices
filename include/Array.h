#ifndef ARRAY_H
#define ARRAY_H

class Array{
    public:
        Array();
        Array(int nodes);
        virtual ~Array();
        void insertLink(int x, int y);
        void deleteLink(int x, int y);
        int *findNeighbors(int x, int &num);
        int /*bit*/connectedComponents();//BITCONNNEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEECT
        void print(ofstream s);
    protected:
        int **A;//main array
        int *neighbors, *next;//helper arrays for the individual elements
        int len, maximum;//helper variables for the main array, A
        void expand(int id, int x);//x only relevant when id is -1, indicating the expansion of A instead of a sub-table
};

#endif // ARRAY_H
