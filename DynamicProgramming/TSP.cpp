#include <bits/stdc++.h>

using namespace std;

int TSP(vector<vector<int>>grid,int start){
    vector<int>points;
    for(int i=0;i<grid.size();i++)if(i!=start)points.push_back(i);
    int ans=INT_MAX;
    
    do{
        int pathweight=0,k=start;
        for(int i=0;i<points.size();i++){
            pathweight+=grid[k][points[i]];
            k=points[i];
        }
        pathweight+=grid[k][start];
        ans=min(ans,pathweight);
    }while(next_permutation(points.begin(),points.end()));
    

    return ans;
}


int main(){
    vector<vector<int>>g={
                        {0,10,15,20},
                        {5,0,9,10},
                        {6,13,0,12},
                        {8,8,9,0}
                        };

    cout<<TSP(g,0);



    return 0;
}