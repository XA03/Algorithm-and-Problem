#include <bits/stdc++.h>

using namespace std;






void prt(vector<vector<int>>s,int i,int j){
    //print result.
    if(i==j)cout<<i;
    else{
        cout<<"(";
        prt(s,i,s[i][j]);
        prt(s,s[i][j]+1,j);
        cout<<")";
    }
}

int Matrixchainr(vector<vector<int>>&dpm,vector<vector<int>>&s,vector<int>p,int i,int j){
    if(i==j){
        dpm[i][j]=0;
        return dpm[i][j];
    }
    dpm[i][j]=INT_MAX;
    for(int k=i;k<j;k++){
      int temp=Matrixchainr(dpm,s,p,i,k)+Matrixchainr(dpm,s,p,k+1,j)+p[i-1]*p[k]*p[j];
      if(temp<dpm[i][j]){
          dpm[i][j]=temp;
          s[i][j]=k;
      }
    }
    return dpm[i][j];
}


void Matrixchain(vector<int>p){

    //iteration version

    vector<int>subdp(p.size(),0);
    vector<vector<int>>dpm(p.size(),subdp),
                       s=dpm;
    int n=p.size()-1;
    for(int i=1;i<=n;i++)dpm[i][i]=0;   //自己跟自己沒得乘

    for(int len=2;len<=n;len++){        //chain的長度 
        for(int i=1;i<=n-len+1;i++){    //chain的起點
            int j=i+len-1;              //chain的尾巴
            dpm[i][j]=INT_MAX;          //還沒算出來前預設最大
            for(int k=i;k<j;k++){       //找最佳分隔點k
                int temp;
                temp=dpm[i][k]+dpm[k+1][j]+p[i-1]*p[k]*p[j];
                if(dpm[i][j]>temp){     //如果這個分法可以比現有分法的乘法數少就替代他並標記k的位置和乘法數
                    dpm[i][j]=temp;
                    s[i][j]=k;
                }
            }
        }
    }

    for(auto i:dpm){
        for(auto j:i)cout<<j<<" ";
        cout<<endl;
    }

    cout<<endl;

    for(auto i:s){
        for(auto j:i)cout<<j<<" ";
        cout<<endl;
    }


    prt(s,1,n);
}



int main(){

    vector<int>p={12,5,10,2,5,4};
    vector<int>sub(p.size(),0);
    vector<vector<int>>dpm(p.size(),sub),s=dpm;

    /*Matrixchainr(dpm,s,p,1,p.size()-1);
    prt(s,1,5);
    */
    Matrixchain(p);


    return 0;
}