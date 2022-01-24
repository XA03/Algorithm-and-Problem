#include <bits/stdc++.h>

using namespace std;

void Hanoi(int n,char start,char middle,char end){
    if(n==1)cout<<"move disc "<<n<<" from "<<start<<" to "<<end<<endl; //如果只有一個圈要移動就直接移去目標就好了
    else{
        Hanoi(n-1,start,end,middle);//把n-1個移去中繼點
        cout<<"move disc "<<n<<" from "<<start<<" to "<<end<<endl;//把最大的那個移去目標地
        Hanoi(n-1,middle,start,end);//把n-1個在中繼點的盤子搬過去目標地
    }
}

// TC Proof
// T(n)=2*T(n-1)+1 , T(1)=1
// T(n-1)=2*T(n-2)+1
// T(n-2)=2*T(n-3)+1
// T(n)=2 * [2*T(n-2)] + 2+1
// T(n)=2*2 *[2*T(n-3)] + 4+2+1
// T(n)=2^(n-1) * T(1) + [2^(n-1)+2^(n-2)+2^(n-3)+...+2^0]
// T(n)=2^(n-1)+2^(n-1)-1
// T(n)=2^n-1 #

// So TC=O(2^n)  
int main(){

    Hanoi(2,'A','B','C');



    return 0;
}