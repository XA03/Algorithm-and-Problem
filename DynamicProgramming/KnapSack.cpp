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
        for(int j=1;j<=limitw;j++){
            if(j-stuff[i].weight<0){
                printf("dp[%d][%d]=dp[%d][%d]\n",i+1,j,i,j);
                dp[i+1][j]=dp[i][j];
            }
            else{
                printf("dp[%d][%d]=max(dp[%d][%d],dp[%d][%d]+%d)\n",i+1,j,i,j,i,j-stuff[i].weight,stuff[i].profit);
                dp[i+1][j]=max(dp[i][j],dp[i][j-stuff[i].weight]+stuff[i].profit);
            }

            cout<<"w= "<<j<<endl;

            for(auto i:dp){
                for(auto j:i)cout<<j<<" ";
                cout<<endl;
            }
            cout<<"\n\n";
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