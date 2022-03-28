#include <bits/stdc++.h>

using namespace std;

void AddEdge(vector<vector<int>>&graph,int s,int t,int capacity){
    graph[s][t]=capacity;
}

bool DFSfindpath(vector<vector<int>>graph,vector<int>&predecessor,int source,int termination){
    stack<int>s;
    vector<bool>visited(graph.size(),false);
    for(int i=0;i<graph.size();i++)predecessor[i]=-1;
    
    s.push(source);
    visited[source]=true;

    while(!s.empty()){
        int cur=s.top();
        s.pop();
        for(int i=0;i<graph.size();i++){
            if(graph[cur][i]!=0 && visited[i]==false){
                s.push(i);
                visited[i]=true;
                predecessor[i]=cur;
            }
        }
    }
    
    return visited[termination]==true;
}

int FindMinCapacity(vector<vector<int>>graph,vector<int>predecessor,int termination){
    int min=INT_MAX;

    for(int index=termination;predecessor[index]!=-1;index=predecessor[index]){
        if(graph[predecessor[index]][index]!=0 && graph[predecessor[index]][index]<min){
            min=graph[predecessor[index]][index];
        }
    }
    return min;
}

int Ford_Fulkerson(vector<vector<int>>graph,int source,int termination){
    int maxflow=0;
    vector<int>predecessor(graph.size(),-1);
    vector<vector<int>>residual=graph;

    while(DFSfindpath(residual,predecessor,source,termination)){
        int flow=FindMinCapacity(residual,predecessor,termination);
        maxflow+=flow;
        
        for(int i=termination;i!=source;i=predecessor[i]){
            int pre=predecessor[i];
            residual[pre][i]-=flow;
            residual[i][pre]+=flow;
        }
    }

    printf("MaxFlow = %d",maxflow);

    return maxflow;
}

int main(){

    //we define edge(x,y)=0 if edge isn't exist in directed weighted graph.
    vector<int>t(6,0);
    vector<vector<int>>g(6,t);

    AddEdge(g,0, 1, 9);
    AddEdge(g,0, 3, 9);
    AddEdge(g,1, 2, 3);
    AddEdge(g,1, 3, 8);
    AddEdge(g,2, 4, 2);
    AddEdge(g,2, 5, 9);
    AddEdge(g,3, 2, 7);
    AddEdge(g,3, 4, 7);
    AddEdge(g,4, 2, 4);
    AddEdge(g,4, 5, 8);

    Ford_Fulkerson(g,0,5);

    return 0;
}