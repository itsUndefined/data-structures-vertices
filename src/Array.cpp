#include "Array.h"

Array::Array(){
    A = new int*[50];
    neighbors = new int[50];
    next = new int[50];
    for(int i=0; i<50; i++){
        A[i] = new int[50];
        neighbors[i]=50;
        next[i]=0;
    }
    len = 0;
    maximum = 50;
}

Array::Array(int nodes){
    A = new int*[nodes];
    neighbors = new int[nodes];
    next = new int[nodes];
    for(int i=0; i<nodes; i++){
        A[i] = new int[nodes];
        neighbors[i]=nodes;
        next[i]=0;
    }
    len = 0;
    maximum = nodes;
}

Array::~Array(){
    delete A;
    delete neighbors;
    delete next;
}

void Array::insertLink(int x, int y){
    bool flag=true;
    int temp;
    if(len >= maximum || x >= maximum){
        expand(-1, x);
    }
    if(y >= maximum){
        expand(-1, y);
    }
    for(int i=0; (i<next[x])&&flag; i++){
        if(A[x][i]==y){
            flag = false;
        }
    }
    if(flag){
        A[x][next[x]]=y;
        for(int i=next[x]; i<0; i--){
            if(A[x][i]<A[x][i-1]){
                temp=A[x][i];
                A[x][i]=A[x][i-1];
                A[x][i-1]=temp;
            }
        }
        next[x]++;
    }
    if(next[x]==0 && len<x){
        len=x;
    }
    if(len<y){
        len=y;
    }
    if(next[x]>=neighbors[x]){
        expand(x, 0);
    }
}

void Array::deleteLink(int x, int y){
    int found=-1;
    if(x<maximum){
        for(int i=0; i<next[x] && found==-1; i++){
            if(A[x][i]==y){
                found=x;
            }
        }
        if(found>=0){
            for(int i=found; i<next[x]-1; i++){
                A[x][i]=A[x][i+1];
            }
            next[x]--;
        }
    }
}

int *Array::findNeighbors(int x, int &num){
    int *r, *temp;
    int temp1;
    bool flag1=false, flag2=false;
    num=next[x];
    r = new int[len];
    for(int i=0; i<num; i++){
        r[i]=A[x][i];
        for(int j=i; j>0; j--){
            if(r[j]<r[j-1]){
                temp1=r[j];
                r[j]=r[j-1];
                r[j-1]=temp1;
            }
        }
    }
    for(int i=0; i<len; i++){//loops through all IDs
        flag1=false;
        flag2=false;
        for(int j=0; j<=x && !flag1; j++){//loops through each ID's neighbors, up to x, trying to find it
            if(A[i][j]==x){
                for(int k=0; k<=i && !flag2; k++){//loops through r's elements to see if the ID is already present
                    if(r[k]==i){
                        flag2=true;
                    }
                }
            }
            if(flag2!=true){//if the ID doesn't already exist in r, a new neighbor of x has been found
                    flag1=true;
            }
        }
        if(flag1){
            r[num]=i;
            for(int j=num; j>0; j--){
            if(r[j]<r[j-1]){
                temp1=r[j];
                r[j]=r[j-1];
                r[j-1]=temp1;
            }
        }
            num++;
        }
    }
    temp = new int[num];
    for(int i=0; i<num; i++){
        temp[i]=r[i];
    }
    delete r;
    r = new int[num];
    for(int i=0; i<num; i++){
        r[i]=temp[i];
    }
    delete temp;
    return r;
}

int Array::connectedComponents(){
    int **CompList;
    int *CompSize;
    bool flag;
    int num=1;
    CompList = new int*[maximum];
    for(int i = 0; i<maximum; i++){
        CompSize[i] = 0;
    }
    CompList[0]=findNeighbors(0, CompSize[0]);
    for(int i=1; i<maximum; i++){//loops through all IDs
        flag=true;
        for(int j=0; j<num && flag; j++){//loops through all already established connected components
            for(int k=0; k<CompSize[j] && flag; k++){//loops through a specific connected component's elements
                if(CompList[j][k]==i){
                    flag=false;
                }
            }
        }
        if(flag){
            CompList[num]=findNeighbors(num, CompSize[num]);
            num++;
        }
    }
    delete CompList;
    delete CompSize;
    return num;
}

void Array::print(ofstream s){
    for(int i=0; i<len; i++){
        s<<i<<' '<<next[i];
        for(int j=0; j<next[i]; j++){
            s<<' '<<A[i][j];
        }
    }
}

void Array::expand(int id, int x){

    int **temp0;
    int *temp1, *temp2;

    if(id==-1 && x>=2*maximum){//if x is higher than double the normal size of the array, the array grows just enough to accommodate it.

        temp0 = new int*[maximum];
        temp1 = new int[maximum];
        temp2 = new int[maximum];//declare temporary arrays to store the data while the main ones are lengthened

        for(int i=0; i<maximum; i++){
            temp0[i] = new int[neighbors[i]];
            temp1[i] = neighbors[i];
            temp2[i] = next[i];
            for(int j=0; j<neighbors[i]; j++){
                temp0[i][j]=A[i][j];
            }
        }//storing data in temp arrays

        delete A;
        A = new int*[x+1];
        delete neighbors;
        neighbors = new int[x+1];
        delete next;
        next = new int[x+1];//lengthening main arrays

        for(int i=0; i<maximum; i++){
            A[i] = new int[50];
            neighbors[i] = temp1[i];
            next[i] = temp2[i];
            for(int j=0; j<neighbors[i]; j++){
                A[i][j]=temp0[i][j];
            }
        }//moving the data back to the main arrays

        delete temp0;
        delete temp1;
        delete temp2;
        maximum = x;//cleaning up

    }else if(id==-1){//if x is lower than double the normal size of the array, the array's size is doubled

        temp0 = new int*[maximum];
        temp1 = new int[maximum];
        temp2 = new int[maximum];

        for(int i=0; i<maximum; i++){
            temp0[i] = new int[neighbors[i]];
            temp1[i] = neighbors[i];
            temp2[i] = next[i];
            for(int j=0; j<neighbors[i]; j++){
                temp0[i][j]=A[i][j];
            }
        }

        delete A;
        A = new int*[2*maximum];
        delete neighbors;
        neighbors = new int[2*maximum];
        delete next;
        next = new int[2*maximum];

        for(int i=0; i<maximum; i++){
            A[i] = new int[50];
            neighbors[i] = temp1[i];
            next[i] = temp2[i];
            for(int j=0; j<neighbors[i]; j++){
                A[i][j]=temp0[i][j];
            }
        }

        delete temp0;
        delete temp1;
        delete temp2;
        maximum = 2*maximum;

    }else if(id>=0 && id<maximum){//if a specific element needs to have its array of neighbors expanded, this code is used

        temp1 = new int[neighbors[id]];

        for(int i=0; i<neighbors[id]; i++){
            temp1[i]=A[id][i];
        }

        delete A[id];
        A[id] = new int[neighbors[id]*2];

        for(int i=0; i<neighbors[id]; i++){
            A[id][i]=temp1[i];
        }

        delete temp1;
        neighbors[id] *= 2;
    }
}
