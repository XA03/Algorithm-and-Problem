#include <bits/stdc++.h>

using namespace std;

int Minweighted(vector<int>&cost,vector<bool>&visit){
    int minimum=INT_MAX,index=0;

    for(int i=0;i<cost.size();i++){
        if(visit[i]==false && cost[i]<minimum){
            minimum=cost[i];
            index=i;
        }
    }
    return index;
}

void PrimMST(vector<vector<int>>graph,int source=0){
    vector<int>cost(graph.size(),INT_MAX),predecessor(graph.size(),-1),successor(graph.size(),-1);
    vector<bool>visit(graph.size(),false);

    cost[source]=0;
    
    for(int i=0;i<graph.size();i++){
        int next=Minweighted(cost,visit);
        visit[next]=true;
        for(int j=0;j<graph.size();j++){
            if(visit[j]==false && graph[next][j]!=0 && graph[next][j]<cost[j]){
                predecessor[j]=next;
                cost[j]=graph[next][j];
            }
        }

        cout<<next<<endl;
        for(int i=0;i<graph.size();i++)cout<<cost[i]<<" ";
        cout<<endl;
        for(int i=0;i<graph.size();i++)cout<<visit[i]<<" ";
        cout<<endl;
    }
    
}


int main(){

    vector<vector<int>>g={
        {0,5,0,0,0,3,0},
        {5,0,10,0,1,0,0},
        {0,10,0,5,0,0,8},
        {0,0,5,0,7,0,9},
        {0,1,0,7,0,6,2},
        {3,0,0,0,6,0,0},
        {0,4,8,9,2,0,0}
                        };

    PrimMST(g,2);








    return 0;
}