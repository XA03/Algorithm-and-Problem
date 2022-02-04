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

int Fraction(vector<item>stuff,int limitw){
    sort(stuff.begin(),stuff.end(),cmp);
    
    for(int i=0;i<stuff.size();i++)cout<<stuff[i].rate<<endl;

    return 0;
}

int ZeroOne(){
    return 0;
}

int main(){
    vector<item>things;
    struct item input;
    for(int i=0;i<3;i++){
        cin>>input.profit>>input.weight;
        input.rate=input.profit/input.weight;
        things.push_back(input);
    }
    Fraction(things,10);

    return 0;
}