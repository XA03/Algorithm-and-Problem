#include <bits/stdc++.h>

using namespace std;

//Knuth Morris Pratt簍衡猭い惠璶ㄏノ玡后ㄓ腊搭ぶゑ癸Ω计
//玡后2﹃A㎝Bㄤい A=BS (Sヴ種獶﹃) 嘿 B琌A玡后
//ㄒA=Hello 叫тA玡后栋 S={H,He,Hel,Hell}
//后琌妓笵瞶┯ㄒ A后栋 S={o,lo,llo,ello}

//フ玡后琌或ㄆ钡帝矗KMPい璶芠├ 程そ玡后(Partial Match Table)
//PMT暗ㄆ琌р﹃Sい玡后栋ъㄓ тㄤい单程玡后
//ㄒ A=abcabc 硂柑玡后栋={a,ab,abc,abca,abcab} 后栋={c,bc,abc,cabc,bcabc} ┮单程场だ琌 abc 
//PMT惠璶琌тぃk玡后㎝k后惠璶PMT瞶パ琌Next Table

//Next Table虏虫盢PMT–Shift Right  (材干-1)
//ǐ硂柑穨场常琌搭ぶи﹃ゑ癸礚Ω计 (硂ㄇゑ耕ゲ礛琌礚)

// https://blog.csdn.net/v_july_v/article/details/7041827 把σゅ彻

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