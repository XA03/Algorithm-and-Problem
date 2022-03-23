#include <bits/stdc++.h>

using namespace std;

void relaxation(vector<int>&distance,vector<int>&predecessor,int v1,int v2,int v1v2){
    if(distance[v2]>distance[v1]+v1v2){
        distance[v2]=distance[v1]+v1v2;
        predecessor[v2]=v1;
    }
}

bool Bellman_ford(vector<vector<int>>graph,int source=0){
    vector<int>distance(graph.size(),200),//�o�̤����INT_MAX �|Overflow�M���ܦ��@�ӷ��p�ȡA�y������Relaxation�j�p���Y���~�C
               predecessor(graph.size(),-1);
    distance[source]=0;

    int noway=-99;//��ܨS���o��edge

    for(int i=0;i<graph.size()-1;i++){
        for(int j=0;j<graph.size();j++){
            for(int k=0;k<graph.size();k++){
                if(graph[j][k]!=noway && graph[j][k]!=0){
                    relaxation(distance,predecessor,j,k,graph[j][k]);
                }
            }
        }
    }


    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph.size();j++){
            if(graph[i][j]!=noway){
                if(distance[j]>distance[i]+graph[i][j])return false;
            }
        }
    }

    for(int i=0;i<graph.size();i++)cout<<predecessor[i]<<" ";
    cout<<endl;
    for(int i=0;i<graph.size();i++)cout<<distance[i]<<" ";
    cout<<endl;

    return true;
}



int main(){

    vector<vector<int>> g={
        {0,5,-99,-99,-99,-99},
        {-99,0,6,-99,-4,-99,-99},
        {-99,-99,0,-99,-3,-2},
        {-99,-99,4,-99,-99,-99},
        {-4,-99,-99,1,0,6},
        {3,7,-99,-99,-99,-99}
    };
    
    if(Bellman_ford(g,0))cout<<"�S���t��\n";
    else cout<<"���t��\n";

    return 0;
}