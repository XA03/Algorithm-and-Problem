#include <bits/stdc++.h>

using namespace std;

int MakeChange(vector<int>denomination,int money){
    if(money==0)return 0;
    vector<int>dp(money+1,0);
    for(int i=0;i<denomination.size();i++)dp[denomination[i]]=1;
    
    for(int i=1;i<=money;i++){
        int mini=money;
        for(int j=0;j<denomination.size();j++){
            if(i>=denomination[j])mini=min(dp[i-denomination[j]]+1,mini);
        }
        dp[i]=mini;
    }

    return dp[money];
}

int main(){

    vector<int>deno={1,4,6};
    int money;
    cin>>money;
    cout<<MakeChange(deno,money);




    return 0;
}