#include <bits/stdc++.h>

using namespace std;

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
        if(graph[vertex][i]!=0 && graph[vertex][i]!=-99){ 
            if(color[i]==0){
                cout<<i<<endl;
                predecessor[i]=vertex;
                DFSvisit(graph,color,predecessor,discover,finish,i,time);
            }
        }
    }
    color[vertex]=2;
    finish[vertex]=++time;
}


void DFS(vector<vector<int>>graph,int source=0){
    vector<int>color(graph.size(),0),
               predecessor(graph.size(),-1),
               discover(graph.size(),0),
               finish(graph.size(),0),
               orderfinish(graph.size(),0);
    int time=0,index=source;

    for(int i=0;i<graph.size();i++){
        if(color[index]==0){
            cout<<index<<endl;
            DFSvisit(graph,color,predecessor,discover,finish,index,time);
        }
        index=i;
    }
  
    for(int i=0;i<finish.size();i++)cout<<finish[i]<<" ";
    cout<<endl;

    for(int i=0;i<orderfinish.size();i++)orderfinish[i]=i;
    bubblesort(finish,orderfinish);
    cout<<endl;
    for(int i=0;i<orderfinish.size();i++)cout<<orderfinish[i]<<" ";

}




int main(){

    vector<vector<int>> g={
        {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,1,1,0,1,1,0,0},
        {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    },
    g2=
    {
        {0,3,-2,-99,-99,-99,-99},
        {-99,0,-99,-4,4,-99,-99},
        {-99,-99,0,-99,5,6,-99},
        {-99,-99,-99,0,-99,8,2},
        {-99,-99,-99,-3,0,-99,-2},
        {-99,-99,-99,-99,-99,0,2},
        {-99,-99,-99,-99,-99,-99,0}
    };

    //DFS(g,0);

    DFS(g2,0);



    return 0;
}