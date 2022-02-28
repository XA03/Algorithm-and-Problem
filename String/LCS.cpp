#include <bits/stdc++.h>

using namespace std;

int lcslen(string a,string b){
    vector<int>subdp(b.size()+1,0);
    vector<vector<int>>dp(a.size()+1,subdp);
    vector<vector<int>>trace(a.size()+1,subdp);

    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                trace[i][j]=0;
            }
            else if(dp[i-1][j]<dp[i][j-1]){
                dp[i][j]=dp[i][j-1];
                trace[i][j]=1;
            }
            else{
                dp[i][j]=dp[i-1][j];
                trace[i][j]=2;
            }
        }
    };
    int l=dp[a.size()][b.size()],x=a.size(),y=b.size();
    vector<char>lcs(l);
    while(l>0){
        if(trace[x][y]==0){
            l--,lcs[l]=a[x-1];
            x--,y--;
        }
        else if(trace[x][y]==1)y--;
        else if(trace[x][y]==2)x--;
    }
    
    for(int i=0;i<lcs.size();i++)cout<<lcs[i];
    cout<<endl;


    return dp[a.size()][b.size()];
}

int lcslen(vector<int>a,vector<int>b){
    vector<int>subdp(b.size()+1,0);
    vector<vector<int>>dp(a.size()+1,subdp);
    vector<vector<int>>trace(a.size()+1,subdp);

    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                trace[i][j]=0;
            }
            else if(dp[i-1][j]<dp[i][j-1]){
                dp[i][j]=dp[i][j-1];
                trace[i][j]=1;
            }
            else{
                dp[i][j]=dp[i-1][j];
                trace[i][j]=2;
            }
        }
    }

    int l=dp[a.size()][b.size()],x=a.size(),y=b.size();
    vector<int>lcs(l);
    while(l>0){
        if(trace[x][y]==0){
            l--,lcs[l]=a[x-1];
            x--,y--;
        }
        else if(trace[x][y]==1)y--;
        else if(trace[x][y]==2)x--;
    }
    
    for(int i=0;i<lcs.size();i++)cout<<lcs[i]<<" ";
    cout<<endl;

    return dp[a.size()][b.size()];
}

void LIS(string a){
    string sorta=a;
    sort(sorta.begin(),sorta.end());
    lcslen(a,sorta);
}

void LIS(vector<int>a){
    vector<int>sorta=a;
    sort(sorta.begin(),sorta.end());
    lcslen(a,sorta);
}

int lcsslen(string a,string b){
    vector<int>subdp(b.size()+1,0);
    vector<vector<int>>dp(a.size()+1,subdp);

    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1]){ 
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=0;
            }
        }
    }
    int ans=0;
    for(auto i:dp){
        for(auto j:i)ans=max(ans,j);
    }

    return ans;
}
int main(){

    vector<int>arr={66,92,123,31,83,53,48,17,9,57,75};
    //LIS(arr);
    cout<<lcslen("photograph", "tomography")<<endl;
    cout << lcsslen("photograph", "tomography");

    return 0;
}