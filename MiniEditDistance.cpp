#include <bits/stdc++.h>

using namespace std;

int miniEdit(string a,string b){
    
    vector<int>subdp(b.size()+1,0);
    vector<vector<int>>dp(a.size()+1,subdp),
                       trace(a.size()+1,subdp);
    int x,y,z,temp;

    for(int i=0;i<=a.size();i++){
        dp[i][0]=i;
        trace[i][0]=1;
    }
    for(int j=0;j<=b.size();j++){
        dp[0][j]=j;
        trace[0][j]=2;
    }

    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            x=dp[i-1][j]+1;
            y=dp[i][j-1]+1;
            if(a[i-1]!=b[j-1])z=dp[i-1][j-1]+1;
            else z=dp[i-1][j-1];
            
            
            
            temp=min(x,y);
            temp=min(temp,z);
            
            cout<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<" "<<z<<endl;


            if(temp==x)trace[i][j]=1;
            else if(temp==y)trace[i][j]=2;
            else if(temp==z)trace[i][j]=0;

            dp[i][j]=temp;
        }
    }
    
    
    for(auto i:dp){
        for(auto j:i)cout<<j;
        cout<<endl;
    }
    cout<<endl;
    
    
    
    
    return dp[a.size()][b.size()];
}



int main(){

    cout<<miniEdit("acbabca","babcbac");


    return 0;
}