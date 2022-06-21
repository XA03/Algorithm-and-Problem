#include <bits/stdc++.h>

using namespace std;

int findset(vector<int>parent,int target){
    while(parent[target]!=target)target=parent[target];
    return target;
}

void setunion(vector<int>&parent,int a,int b){
    int pa=findset(parent,a);
    int pb=findset(parent,b);
    
    parent[pa]=pb;
}

int KruskalMST(vector<vector<int>>mat){
    vector<int>disjointset(mat.size(),0);
    int ret=0,treeedge=0;

    for(int i=0;i<disjointset.size();i++)disjointset[i]=i;
    
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
        printf("Edge %d %d ³Q¥[¤JMST\n",v1,v2);
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
    };

    KruskalMST(g);

    return 0;
}