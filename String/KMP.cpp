#include <bits/stdc++.h>

using namespace std;

//�bKnuth Morris Pratt�t��k���A�ݭn�ϥΨ�e�������U��֤�諸���ơC
//�e��G2�r��A�MB�A�䤤 A=BS (S�����N�D�Ŧr��) �� B�OA���e��
//�Ҥl�GA=Hello �Ч�XA���e�󶰦X�A S={H,He,Hel,Hell}
//���]�O�P�˪��D�z�A�ӤW�� A����󶰦X�� S={o,lo,llo,ello}

//���իe���O���^�ƫ�A���۴���KMP�����n���@���[�� �̪����@�e���(Partial Match Table)
//PMT�����ƬO��@�Ӧr��S�����e��󶰦X��X�� ���L�̨䤤�۵��B�̪����e���
//�Ҥl�G A=abcabc �o�̫e�󶰦X={a,ab,abc,abca,abcab} ��󶰦X={c,bc,abc,cabc,bcabc} �ҥH�L�̬۵��B�̪��������O abc 
//PMT�ݭn���O��X�L�̦b���Pk��e��Mk���󪺦@�P���סC�ݭnPMT���z�ѬO���F�إXNext Table

//Next Table��²��A�NPMT���C�ӭ�Shift Right �@��Y�i (�Ĥ@���-1)
//����o�̪��@�~�������O���F��֧ڭ̦b�r����ɪ��L�Ħ��� (�]���o�Ǥ�����M�O�L�Ī�)

// https://blog.csdn.net/v_july_v/article/details/7041827 �ѦҤ峹

void getNext(string pat,vector<int>&next){
    int patlen=pat.size(),k=-1,j=0;
    next[0]=-1;

    while(j<patlen-1){
        if(k==-1||pat[j]==pat[k]){
            k++;
            j++;
            next[j]=k;
        }
        else{
            k=next[k];
        }
    }

}

int kmp(string text,string pat){

    vector<int>next(pat.size(),0);
    getNext(pat,next);
    int i=0,j=0,textlen=text.size(),patlen=pat.size();
    while(i<textlen&&j<patlen){
        if(j==-1||text[i]==pat[j]){
            i++,j++;
        }
        else{
            j=next[j];
        }
    }
    if(j==patlen)return i-j;
    return -1;
}

int anotherkmp(string a,string b){
    int fail[999]={-1};
    int i=0,j=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]==b[j]){
            i++,j++;
        }
        else if(j==0){
            i++;
        }
        else{
            j=fail[j-1]+1;
        }
    }
    if(j==b.size())return i-j;
    return -1;
}


int main(){
   
    string str="abcdabd",b="abd";
    vector<int>t(b.size(),0);
    
    cout<<anotherkmp(str,b);




    return 0;
}