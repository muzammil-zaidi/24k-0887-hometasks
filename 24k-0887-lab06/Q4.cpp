#include<iostream>
#include<string>
using namespace std;

#define MAX 100

class Stack{
private:
    char arr[MAX];
    int topIndex;

public:
    Stack(){
        topIndex=-1;
    }

    void push(char c){
        if(topIndex>=MAX-1){
            cout<<"Stack Overflow!\n";
            return;
        }
        arr[++topIndex]=c;
    }

    char pop(){
        if(topIndex==-1){
            cout<<"Stack Underflow!\n";
            return '\0';
        }
        return arr[topIndex--];
    }

    char top(){
        if(topIndex==-1)
            return '\0';
        return arr[topIndex];
    }

    bool empty(){
        return topIndex==-1;
    }
};

bool isOperator(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPostfix(string infix){
    Stack s;
    string postfix="";

    for(int i=0;i<infix.length();i++){
        char ch=infix[i];

        if(ch==' '){
            continue;
        }

        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || isdigit(ch)){
            postfix+=ch;
        }

        else if(ch=='('){
            s.push(ch);
        }

        else if(ch==')'){
            while (!s.empty() && s.top()!='('){
                postfix+=s.pop();
            }
            s.pop();
        }

        else if(isOperator(ch)){
            while (!s.empty() && precedence(s.top())>=precedence(ch)){
                if(ch=='^' && s.top()=='^'){
                    break;
                }
                postfix+=s.pop();
            }
            s.push(ch);
        }
    }

    while(!s.empty()){
        postfix+=s.pop();
    }

    return postfix;
}

int main(){
    string infix;
    cout<<"Enter infix expression: ";
    getline(cin,infix);

    string postfix=infixToPostfix(infix);
    cout<<"Postfix Expression: "<<postfix<<endl;

    return 0;
}
