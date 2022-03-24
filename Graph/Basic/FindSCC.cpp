#include <bits/stdc++.h>

using namespace std;


void collapsing(vector<int>&s,int i){   
    int cur=i;
    while(s[cur]!=cur){
        if(s[cur]==-1)break;
        cur=s[cur];
    }
    s[i]=cur;
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


vector<vector<int>>Transpose(vector<vector<int>>graph){
    vector<int>t(graph.size(),0);
    vector<vector<int>>gt(graph.size(),t);

    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph[i].size();j++){
            if(graph[i][j]==1){
                gt[j][i]=1;
            }
        }
    }


    return gt;
}



void DFSvisit(vector<vector<int>>graph,vector<int>&color,vector<int>&predecessor,vector<int>&discover,vector<int>&finish,int vertex,int &time){
    color[vertex]=1;
    discover[vertex]= ++time;
    for(int i=0;i<color.size();i++){
        if(graph[vertex][i]!=0 && graph[vertex][i]!=-99 ){// -99 0表不通  0可表自身
            if(color[i]==0){
                cout<<i<<" ";
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
            cout<<index<<" ";
            DFSvisit(graph,color,predecessor,discover,finish,index,time);
            cout<<endl;
        }
        index=i;
    }   

    vector<vector<int>>gt=Transpose(graph);
    for(int i=0;i<orderfinish.size();i++)orderfinish[i]=i;
    bubblesort(finish,orderfinish);

    for(int i=0;i<graph.size();i++){
        color[i]=0;
        predecessor[i]=-1;
        discover[i]=0;
        finish[i]=0;
    }
    time=0;

    for(int i=0;i<graph.size();i++){
        if(color[orderfinish[i]]==0){
            cout<<orderfinish[i]<<" ";
            DFSvisit(gt,color,predecessor,discover,finish,orderfinish[i],time);
            cout<<endl;            
        }
        orderfinish[i]=i;
    }

    for(int i=0;i<graph.size();i++)collapsing(predecessor,i);

    for(int i=0;i<graph.size();i++){
        if(predecessor[i]<0){
            for(int j=0;j<graph.size();j++){
                if(predecessor[j]==i){
                    cout<<j<<" ";
                }
            }
            cout<<endl;
        }
    }


}


int main(){
    
    vector<vector<int>>g={
    {0,1,0,0,0,0,0,0,0},
    {0,0,1,0,1,0,0,0,0},
    {1,0,0,1,0,1,0,0,0},
    {0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,0,0},
    {0,0,0,0,1,0,1,1,0},
    {0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,1,0,0}
    };

    DFS(g,0);

    return 0;
}