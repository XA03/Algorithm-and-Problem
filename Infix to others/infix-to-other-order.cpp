#include <bits/stdc++.h>

using namespace std;

int pri(char a){
    if(a=='+'||a=='-')return 1;
    else if(a=='*'||a=='/')return 2;
    else if(a=='^')return 3;
    
    return 0;
}



string infix_to_postfix(string infix){
    string ret;
    stack<char>s;
    for(int i=0;i<infix.size();i++){
        if(isalpha(infix[i]))ret+=infix[i];
        else{   
            if(infix[i]==')'){      //遇到括號代表還有另一個可配對的括號，把括號中的內容先印出
                while(s.top()!='('){
                    ret+=s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty()&&pri(infix[i])<=pri(s.top())){     //如果stack是空的會直接error，因為s.top()根本沒東西可以比較
                    ret+=s.top();
                    s.pop();
                }//while條件代表若前面碰到的operator是要先算的就得先印出符號，不然到最後一次輸出的時候順序會不對
                s.push(infix[i]);
            }
        }
        
    }

    while(!s.empty()){//一定會有operator沒辦法出來，因為最後一次碰到的operator沒有遇到下一次要比較的時刻
        ret+=s.top();
        s.pop();
    }
    
    return ret;
}

string infix_to_prefix(string infix){
    string ret;
    stack<char>s;
    for(int i=infix.size()-1;i>=0;i--){
        if(isalpha(infix[i]))ret+=infix[i];
        else{   
            if(infix[i]=='('){
                while(s.top()!=')'){
                    ret+=s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty()&&pri(infix[i])<=pri(s.top())){     
                    ret+=s.top();  
                    s.pop();
                }
                s.push(infix[i]);
            }
        }
    }

    while(!s.empty()){
        ret+=s.top();
        s.pop();
    }
    reverse(ret.begin(),ret.end());


    return ret;
}



int main(){

    cout<<infix_to_postfix("a+b*c-d")<<endl;
    cout<<infix_to_prefix("a+b*c-d");




    return 0;
}