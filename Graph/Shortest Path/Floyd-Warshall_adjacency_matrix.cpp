#include <bits/stdc++.h>

using namespace std;

void Floyd_Warshall(vector<vector<int>>graph){
    vector<int>t(graph.size(),0);
    vector<vector<int>>predecessor(graph.size(),t),
                       distance(graph.size(),t);
    int noway=200;
    
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph.size();j++){
            distance[i][j]=graph[i][j];
            if(graph[i][j]!=200 && graph[i][j]!=0){
                predecessor[i][j]=i;
            }
            else{
                predecessor[i][j]=-1;
            }
        }
    }
    
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph.size();j++){
            for(int k=0;k<graph.size();k++){
                if(distance[j][k]>distance[j][i]+distance[i][k] && distance[j][i]!=200){
                    distance[j][k]=distance[j][i]+distance[i][k];
                    predecessor[j][k]=predecessor[i][k];
                }
            }
        }
    }

    for(auto i:distance){
        for(auto j:i)cout<<j<<" ";
        cout<<endl;
    }

    cout<<endl;

    for(auto i:predecessor){
        for(auto j:i)cout<<j<<" ";
        cout<<endl;
    }

}


int main(){

    vector<vector<int>>g={
        {0,2,6,8},
        {200,0,-2,3},
        {4,200,0,1},
        {200,200,200,0}
    };

    Floyd_Warshall(g);

    return 0;
}