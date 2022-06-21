#include <bits/stdc++.h>

using namespace std;

int findset(vector<int>parent,int target){
    while(parent[target]!=-1)target=parent[target];
    return target;
}

void setunion(vector<int>&parent,int a,int b){
    int pa=findset(parent,a);
    int pb=findset(parent,b);
    
    parent[pa]=pb;//b is a parent.
}

int KruskalMST(vector<vector<int>>mat){
    vector<int>disjointset(mat.size(),0);
    int ret=0,treeedge=0;

    for(int i=0;i<disjointset.size();i++)disjointset[i]=-1;
    
    while(treeedge<mat.size()-1){
        int minimum=INT_MAX,v1=-1,v2=-1;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                if(findset(disjointset,i)!=findset(disjointset,j) && mat[i][j]<minimum){
                    minimum=mat[i][j];
                    v1=i;
                    v2=j;
                }
            }
        }

        setunion(disjointset,v1,v2);
        printf("Edge %d %d in MST\n",v1,v2);
        ret+=minimum;
        
        treeedge++;
    }

    printf("MST cost= %d\n",ret);

    return ret;
}

int main(){

    vector<vector<int>> g = {
        {INT_MAX, 2, INT_MAX, 6, INT_MAX},
        {2, INT_MAX, 3, 8, 5},
        {INT_MAX, 3, INT_MAX, INT_MAX, 7},
        {6, 8, INT_MAX, INT_MAX, 9},
        {INT_MAX, 5, 7, 9, INT_MAX},
    },
    b={
        {
        {69,5,69,69,69,3,69},
        {5,69,10,69,1,69,4},
        {69,10,69,5,69,69,8},
        {69,69,5,69,7,69,9},
        {69,1,69,7,69,6,2},
        {3,69,69,69,6,69,69},
        {69,4,8,9,2,69,69}
                        }
    };

    KruskalMST(b);

    return 0;
}