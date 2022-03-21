#include <bits/stdc++.h>

using namespace std;

void DFSvisit(vector<int>&color,vector<int>&predecessor,vector<int>&discover,vector<int>&finish,int vertex,int &time){
    color[vertex]=1;
    discover[vertex]= ++time;
    for(int i=0;i<color.size();i++){
        if(color[i]==0){
            predecessor[i]=vertex;
            DFSvisit(color,predecessor,discover,finish,i,time);
        }
    }
    color[vertex]=2;
    finish[vertex]=++time;
}


void DFS(vector<vector<int>>graph,int source=0){
    vector<int>color(graph.size(),0),
               predecessor(graph.size(),-1),
               discover(graph.size(),0),
               finish(graph.size(),0);
    int time=0,index=source;

    for(int i=0;i<graph.size();i++){
        if(color[index]==0){
            DFSvisit(color,predecessor,discover,finish,index,time);
        }
        index=i;
    }
    

    for(int i=0;i<color.size();i++)cout<<predecessor[i]<<" ";
    cout<<endl;
    for(int i=0;i<color.size();i++)cout<<discover[i]<<" ";
    cout<<endl;
    for(int i=0;i<color.size();i++)cout<<finish[i]<<" ";




}


int main(){

    vector<vector<int>> g = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                             {4, 0, 8, 0, 0, 0, 0, 11, 0},
                             {0, 8, 0, 7, 0, 4, 0, 0, 2},
                             {0, 0, 7, 0, 9, 14, 0, 0, 0},
                             {0, 0, 0, 9, 0, 10, 0, 0, 0},
                             {0, 0, 4, 14, 10, 0, 2, 0, 0},
                             {0, 0, 0, 0, 0, 2, 0, 1, 6},
                             {8, 11, 0, 0, 0, 0, 1, 0, 7},
                             {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    DFS(g,0);

    return 0;
}