#include <bits/stdc++.h>

using namespace std;

void relaxation(vector<int>&distance,vector<int>&predecessor,int v1,int v2,int v1v2){
    if(distance[v2]>distance[v1]+v1v2){

        distance[v2]=distance[v1]+v1v2;
        predecessor[v2]=v1;
    }
}



void bubblesort(vector<int>&a,vector<int>&b){
    bool end=false;

    for(int i=0;i<a.size()-1 && !end;i++){
        end=true;
            for(int j=0;j<a.size()-i-1;j++){
                if(a[j]<a[j+1]){
                    swap(a[j],a[j+1]);
                    swap(b[j],b[j+1]);
                    end=false;
                }
            }
    }

}

void DFSvisit(vector<vector<int>>graph,vector<int>&color,vector<int>&predecessor,vector<int>&discover,vector<int>&finish,int vertex,int &time){
    color[vertex]=1;
    discover[vertex]= ++time;
    for(int i=0;i<color.size();i++){
        if(graph[vertex][i]!=0 && graph[vertex][i]!=-99){// 這裡是指當路通時的條件 也就是說你的圖上不通的數字也要被納入考量 0代表的是自己(自己跟自己不需DFS)
            if(color[i]==0){
                predecessor[i]=vertex;
                DFSvisit(graph,color,predecessor,discover,finish,i,time);
            }
        }
    }
    color[vertex]=2;
    finish[vertex]=++time;
}


void DAG(vector<vector<int>>graph,int source=0){
    vector<int>color(graph.size(),0),
               predecessor(graph.size(),-1),
               discover(graph.size(),0),
               finish(graph.size(),0),
               orderfinish(graph.size(),0),
               distance(graph.size(),100);
               
    int time=0,index=source,noway=-99;

    for(int i=0;i<graph.size();i++){
        if(color[index]==0){
            DFSvisit(graph,color,predecessor,discover,finish,index,time);
        }
        index=i;
    }

    for(int i=0;i<orderfinish.size();i++){
        predecessor[i]=-1;
        orderfinish[i]=i;
    }
    bubblesort(finish,orderfinish);


    distance[source]=0;
    for(int j=0;j<graph.size();j++){
        for(int k=0;k<graph.size();k++){
            if(graph[orderfinish[j]][k]!=noway && graph[orderfinish[j]][k]!=0)
                relaxation(distance,predecessor,orderfinish[j],k,graph[orderfinish[j]][k]);
        }
    }
}





int main(){

    vector<vector<int>> g=
    {
        {0,3,-2,-99,-99,-99,-99},
        {-99,0,-99,-4,4,-99,-99},
        {-99,-99,0,-99,5,6,-99},
        {-99,-99,-99,0,-99,8,2},
        {-99,-99,-99,-3,0,-99,-2},
        {-99,-99,-99,-99,-99,0,2},
        {-99,-99,-99,-99,-99,-99,0}
    };

    DAG(g,0);




    return 0;
}