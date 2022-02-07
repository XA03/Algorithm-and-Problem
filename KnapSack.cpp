#include <bits/stdc++.h>

using namespace std;

struct item{
        int profit;
        int weight;
        double rate;
};

bool cmp(item a,item b){
    return a.rate>b.rate;
}

double Fraction(vector<item>stuff,int limitw){
    double maxprofit=0,maxweight=0,index=0;
    sort(stuff.begin(),stuff.end(),cmp);

    while(maxweight<limitw){
        if(index>=stuff.size())break;
        if(maxweight+stuff[index].weight<=limitw){
            maxprofit+=stuff[index].profit;
            maxweight+=stuff[index].weight;
            index++;
        }
        else{
            maxprofit+=(limitw-maxweight)*stuff[index].rate;
            break;
        }
    }
    return maxprofit;
}

int ZeroOne(vector<item>stuff,int limitw){
    vector<int> subdp(limitw+1, 0);
    vector<vector<int>>dp(stuff.size()+1,subdp);   

    for(int i=0;i<stuff.size();i++){
        for(int j=0;j<=limitw;j++){
            if(j-stuff[i].weight<0)dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=max(dp[i][j],dp[i][j-stuff[i].weight]+stuff[i].profit);
        }   
    }
    
    return dp[stuff.size()][limitw];
}

int main(){
    vector<item>things;
    struct item input;
    int limit;
    for(int i=0;i<3;i++){
        cin>>input.profit>>input.weight;
        input.rate=(double)input.profit/input.weight;
        things.push_back(input);
    }
    cin>>limit;
    cout<<Fraction(things,limit)<<endl;
    cout<<ZeroOne(things,limit);

    return 0;
}