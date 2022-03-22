#include <bits/stdc++.h>

using namespace std;

void collapsing(vector<int>&s,int i){
    
    int cur=i;

    while(s[cur]!=cur)cur=s[cur];
    
    s[i]=cur;
}


int main(){

   vector<int>v={5,4,3,2,1};

   priority_queue<int>pq{v.begin(),v.end()};
   priority_queue<int,vector<int>,greater<int> >minheap{v.begin(),v.end()};

   vector<int>s={0,0,1,2,3,4,5};

   for(int i=0;i<s.size();i++){
       collapsing(s,i);
       cout<<s[i]<<" ";
   }

   cout<<minheap.top();

    return 0;
}