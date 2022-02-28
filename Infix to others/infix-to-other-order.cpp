#include <bits/stdc++.h>

using namespace std;

int pri(char a){
    if(a=='+'||a=='-')return 1;
    else if(a=='*'||a=='/')return 2;
    else if(a=='^')return 3;
    
    return 0;
}



string convert(string infix){
    string ret;
    stack<char>s;
    for(int i=0;i<infix.size();i++){
        if(isalpha(infix[i]))ret+=infix[i];
        else{   
            if(infix[i]==')'){
                while(s.top()!='('){
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
    
    return ret;
}


int main(){

    cout<<convert("a+b*c-d");




    return 0;
}