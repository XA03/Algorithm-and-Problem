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


void Matrixchain(vector<int>p){
    vector<int>subdp(p.size(),0);
    vector<vector<int>>dpm(p.size(),subdp),
                       s=dpm;
    int n=p.size()-1;
    for(int i=1;i<=n;i++)dpm[i][i]=0;   //�ۤv��ۤv�S�o��

    for(int len=2;len<=n;len++){        //chain������ 
        for(int i=1;i<=n-len+1;i++){    //chain���_�I
            int j=i+len-1;              //chain������
            dpm[i][j]=INT_MAX;          //�٨S��X�ӫe�w�]�̤j
            for(int k=i;k<j;k++){       //��̨Τ��j�Ik
                int temp;
                temp=dpm[i][k]+dpm[k+1][j]+p[i-1]*p[k]*p[j];
                if(dpm[i][j]>temp){     //�p�G�o�Ӥ��k�i�H��{�����k�����k�ƤִN���N�L�üаOk����m�M���k��
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

    prt(s,1,n);
}



int main(){

    vector<int>p={2,4,3,2,5,1}; 
    Matrixchain(p);


    return 0;
}