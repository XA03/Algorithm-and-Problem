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

int ZeroOne(){
    return 0;
}

int main(){
    vector<item>things;
    struct item input;
    for(int i=0;i<3;i++){
        cin>>input.profit>>input.weight;
        input.rate=(double)input.profit/input.weight;
        things.push_back(input);
    }
    cout<<Fraction(things,8);

    return 0;
}