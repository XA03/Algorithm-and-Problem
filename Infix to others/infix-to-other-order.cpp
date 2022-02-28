#include <bits/stdc++.h>

using namespace std;

bool cmp(char a,char b){
    if((a=='*'||a=='/')&&(b=='+'||b=='-'))return a>b;
    return a<=b;
}



string infix_to_postfix(string infix){
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
                if(cmp(infix[i],s.top()))s.push(infix[i]);
                else{
                    while(cmp(s.top(),infix[i])){
                        ret+=s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    
    return ret;
}


int main(){

    cout<<infix_to_postfix("a+b*c-d");




    return 0;
}