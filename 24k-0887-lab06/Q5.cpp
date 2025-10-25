#include<iostream>
#include<cmath>
#include<string>
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
            cout<<"Stack overflow!\n";
            return;
        }
        arr[++topIndex]=val;
    }

    double pop(){
        if(topIndex==-1){
            cout<<"Stack underflow!\n";
            return 0;
        }
        return arr[topIndex--];
    }

    double top(){
        if(topIndex==-1)
            return 0;
        return arr[topIndex];
    }

    bool empty(){
        return (topIndex==-1);
    }

    int size(){
        return topIndex+1;
    }
};

bool isOperator(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

double applyOperation(double a,double b,char op){
    switch(op){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        case '^':
            return pow(a,b);
        default:
            return 0;
    }
}

double evaluatePrefix(string expr){
    Stack s;

    cout<<"\nEvaluating Prefix Expression: " <<expr<<endl;

    for(int i=expr.length()-1;i>=0;i--){
        char ch=expr[i];

        if(ch==' ')
            continue;

        if(isdigit(ch)){
            s.push(ch-'0');
        }
        else if(isOperator(ch)){
            if(s.size()<2){
                cout<<"Invalid Expression!\n";
                return 0;
            }
            double op1=s.pop();
            double op2=s.pop();

            double result=applyOperation(op1,op2,ch);
            cout<<"Operation: "<<ch<<" "<<op1<<" "<<op2<<" = "<<result<<endl;

            s.push(result);
        }
        else{
            cout<<"Invalid Character: "<<ch<<endl;
            return 0;
        }
    }

    if(!s.empty())
        return s.top();
    else{
        return 0;
    }
}

int main(){
    string expr;
    cout<<"Enter a prefix expression (e.g., -+23549): ";
    cin>>expr;

    double result=evaluatePrefix(expr);
    cout<<"\nFinal Result = "<<result<<endl;

    return 0;
}
