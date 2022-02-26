#include <bits/stdc++.h>

using namespace std;

vector<int> gennext(string s){
    vector<int>ret={0};
    for(int i=0;i<s.size()-1;i++){
        string prefix=s.substr(0,i+1),suffix=s.substr(s.size()-i-1,s.size());
        cout<<prefix<<" "<<suffix<<endl;    
    }
    return {};
}


int main(){



    return 0;
}