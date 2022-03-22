#include <bits/stdc++.h>

using namespace std;

void BFS(vector<vector<int>>graph,int source=0){

    vector<int>color(graph.size(),0),
               predecessor(graph.size(),-1);

    queue<int>vertex;
    int index=source;
    
    for(int i=0;i<graph.size();i++){
        if(color[index]==0){
            color[index]=1;
            predecessor[index]=-1;
            vertex.push(index);

            while(!vertex.empty()){
                int now=vertex.front();
                for(int j=0;j<graph.size();j++){
                    if(graph[now][j]!=0){
                        if(color[j]==0){
                            color[j]=1;
                            predecessor[j]=now;
                            vertex.push(j);
                        }
                    }
                }
                vertex.pop();
                color[now]=2;
            }
        }
        index=i;
    }

    for(int i=0;i<predecessor.size();i++){

        cout<<predecessor[i]<<" ";
    }


}





int main()
{

    vector<vector<int>> g = {
        {0, 5, 0, 0, 0, 3, 0},
        {5, 0, 10, 0, 1, 0, 0},
        {0, 10, 0, 5, 0, 0, 8},
        {0, 0, 5, 0, 7, 0, 9},
        {0, 1, 0, 7, 0, 6, 2},
        {3, 0, 0, 0, 6, 0, 0},
        {0, 4, 8, 9, 2, 0, 0}};

    BFS(g,0);

 
 
    return 0;
}