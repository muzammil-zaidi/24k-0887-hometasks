#include<iostream>
#include<string>
#include<cmath>
using namespace std;

#define MAX 100

class Stack{
private:
    double arr[MAX];
    int topIndex;

public:
    Stack(){
        topIndex=-1;
    }

    void push(double val){
        if(topIndex>=MAX-1){
            cout<<" Stack overflow! Cannot push.\n";
            return;
        }
        arr[++topIndex]=val;
    }

    double pop(){
        if(empty()){
            cout<<" Stack underflow! Invalid expression.\n";
            return 0;
        }
        return arr[topIndex--];
    }

    double top(){
        if(empty()){
            cout<<" Stack empty!\n";
            return 0;
        }
        return arr[topIndex];
    }

    bool empty(){
        return topIndex==-1;
    }
};

bool isOperator(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

double evaluatePostfix(string expr){
    Stack s;

    cout<<"\n Evaluating Expression: "<<expr<<endl;

    for(int i=0;i<expr.length();i++){
        char ch=expr[i];

        if(ch==' ')
            continue;

        if(isdigit(ch)){
            s.push(ch-'0');
        }
        else if(isOperator(ch)){
            double val2=s.pop();
            double val1=s.pop();
            double result=0;

            switch (ch){
                case '+':
                    result=val1+val2;
                    break;
                case '-':
                    result=val1-val2;
                    break;
                case '*':
                    result=val1*val2;
                    break;
                case '/':
                    result=val1/val2;
                    break;
                case '^':
                    result=pow(val1,val2);
                    break;
            }

            s.push(result);
            cout<<"Operation: "<<val1<<" "<<ch<<" "<<val2<<" = "<<result<<endl;
        }
        else{
            cout<<" Invalid character: "<<ch<<endl;
            return 0;
        }
    }

    if(!s.empty())
        return s.top();
    else
        return 0;
}

int main(){
    string expr;
    cout<<"Enter a postfix expression (e.g., 23*54*+9-): ";
    cin>>expr;

    double result=evaluatePostfix(expr);

    cout<<"\nFinal Result = "<<result<<endl;

    return 0;
}
