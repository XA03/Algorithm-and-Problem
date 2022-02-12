#include <bits/stdc++.h>

using namespace std;

int OBST(vector<double>p,vector<double>q,int key){
    
    vector<int>sub(key+1,-1);
    vector<vector<int>>root(key+1,sub);

    vector<double>subdp(q.size(),0);
    vector<vector<double>>dpe(q.size()+1,subdp),
                          dpw(q.size()+1,subdp);



    
    for(int i=1;i<=key+1;i++){
        dpe[i][i-1]=q[i-1];
        dpw[i][i-1]=q[i-1];
    }
    int j;

    for(int l=1;l<=key;l++){
        for(int i=1;i<=key-l+1;i++){
            j=i+l-1;
            dpe[i][j]=INT_MAX;      
            dpw[i][j]=dpw[i][j-1]+p[j-1]+q[j];//幹你娘，我的p是從0開始，所以要從j-1去抓才會對
            for(int r=i;r<=j;r++){
                double temp;
                temp=dpe[i][r-1]+dpe[r+1][j]+dpw[i][j];
                if(temp<dpe[i][j]){
                    dpe[i][j]=temp;
                    root[i][j]=r;
                }
            }
        }
    }

    
    return 87;
}



int main(){

    vector<double>k={0.15,0.1,0.05,0.1,0.2},
                  d={0.05,0.1,0.05,0.05,0.05,0.1};
    cout<<OBST(k,d,k.size());




    return 0;
}