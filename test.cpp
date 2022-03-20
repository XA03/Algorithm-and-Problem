#include <bits/stdc++.h>

using namespace std;

int main(){

    int parent[]={0,2,3,4,5,6,7,8,9,0};
    
    int i=1;
    while(parent[i]!=i){
        i=parent[i];
        cout<<i<<" ";
    }






    return 0;
}