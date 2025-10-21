#include<iostream>
#include<string>
using namespace std;

#define MAX 100

struct Call{
    string name;
    string number;
    int duration;
};

class CallStack{
private:
    Call calls[MAX];
    int topIndex;

public:
    CallStack(){
        topIndex=-1;
    }

    void push(Call c){
        if(topIndex>=MAX-1){
            cout<<"\n Call history is full! Cannot add more.\n";
            return;
        }
        calls[++topIndex]=c;
        cout<<"\nNew call added successfully!\n";
        display();
    }

    void pop(){
        if(empty()){
            cout<<"\n No calls to delete.\n";
            return;
        }
        cout<<"\n️ Deleted Call:\n";
        displayCall(calls[topIndex]);
        topIndex--;
        display();
    }

    void top(){
        if(empty()){
            cout<<"\n No recent call available.\n";
            return;
        }
        cout<<"\n Most Recent Call:\n";
        displayCall(calls[topIndex]);
    }

    bool empty(){
        return topIndex==-1;
    }

    void displayCall(Call c){
        cout<<"Name: "<<c.name<<" | Number: "<<c.number<<" | Duration: "<<c.duration<<" mins\n";
    }

    void display(){
        if(empty()){
            cout<<"\n No call history available.\n";
            return;
        }

        cout<<"\n Current Call History (most recent first):\n";
        for(int i=topIndex;i>=0;i--){
            displayCall(calls[i]);
        }
        cout<<"----------------------------------------\n";
    }
};

int main(){
    CallStack history;
    int choice;

    do{
        cout<<"\n========= CALL HISTORY SYSTEM =========\n";
        cout<<"1. Add New Call (push)\n";
        cout<<"2. Delete Most Recent Call (pop)\n";
        cout<<"3. Show Most Recent Call (top)\n";
        cout<<"4. Check if History is Empty\n";
        cout<<"5. Display Full Call History\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();

        switch(choice){
        case 1:{
            Call newCall;
            cout<<"Enter Caller Name: ";
            getline(cin,newCall.name);
            cout<<"Enter Phone Number: ";
            getline(cin,newCall.number);
            cout<<"Enter Call Duration (in mins): ";
            cin>>newCall.duration;

            history.push(newCall);
            break;
        }
        case 2:
            history.pop();
            break;
        case 3:
            history.top();
            break;
        case 4:
            if(history.empty())
                cout<<"\n Call history is empty.\n";
            else
                cout<<"\nCall history is not empty.\n";
            break;
        case 5:
            history.display();
            break;
        case 0:
            cout<<"\n Exiting program. Goodbye!\n";
            break;
        default:
            cout<<"\nInvalid choice! Try again.\n";
        }
    }
    while(choice!=0);

    return 0;
}
