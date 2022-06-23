#include <bits/stdc++.h>

using namespace std;

int minDistance(vector<int>distance,vector<bool>SpanningSet){
    int minimum=INT_MAX,min_index;

    for(int v=0;v<SpanningSet.size();v++){
        if(SpanningSet[v]==false && distance[v]<= minimum){
            minimum=distance[v];
            min_index=v;
        }
    }
    return min_index;
}


void dijkstra(vector<vector<int>>graph,int source){
    vector<int>distance(graph.size(),INT_MAX);
    vector<bool>SpanningSet(graph.size(),false);

    distance[source]=0;

    for(int i=0;i<graph.size()-2;i++){
        int pick=minDistance(distance,SpanningSet);
    
        SpanningSet[pick]=true;

        for(int v=0;v<graph.size();v++){
            
            if(!SpanningSet[v] && graph[pick][v] && distance[pick]!=INT_MAX && distance[pick] + graph[pick][v] < distance[v]){
                distance[v] = distance[pick] + graph[pick][v];
            }
        }
    }    
    for(int i=0;i<distance.size();i++)cout<<distance[i]<<" ";

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
                             {0, 0, 2, 0, 0, 0, 6, 7, 0}},
    x={
        {0,0,0,0,0,0,0,0},
        {300,0,0,0,0,0,0,0},
        {1000,800,0,0,0,0,0,0},
        {0,0,1200,0,0,0,0,0,0},
        {0,0,0,1500,0,250,0,0},
        {0,0,0,1000,0,0,900,1400},
        {0,0,0,0,0,0,0,1000},
        {1700,0,0,0,0,0,0,0}
    };




    dijkstra(x,4);

    return 0;
}