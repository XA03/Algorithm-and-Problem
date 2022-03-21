#include <bits/stdc++.h>

using namespace std;

int main(){

   vector<int>v={5,4,3,2,1};

   priority_queue<int>pq{v.begin(),v.end()};
   priority_queue<int,vector<int>,greater<int> >minheap{v.begin(),v.end()};

   cout<<minheap.top();

    return 0;
}