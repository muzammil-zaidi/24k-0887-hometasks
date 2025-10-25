#include<iostream>
#include<string>
using namespace std;

struct Node{
    string url;
    Node* next;
};

class Stack{
private:
    string arr[100];
    int topIndex;
public:
    Stack(){
        topIndex=-1;
    }

    void push(string val){
        arr[++topIndex]=val;
    }

    string pop(){
        if(topIndex==-1){
            return "";
        }
        return arr[topIndex--];
    }

    string top(){
        if(topIndex==-1){
            return "";
        }
        return arr[topIndex];
    }

    bool empty(){
        return topIndex==-1;
    }

    int size(){
        return topIndex+1;
    }
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList(){
        head=nullptr;
    }

    void addFront(string url){
        Node* newNode=new Node;
        newNode->url=url;
        newNode->next=head;
        head=newNode;
    }

    void removeFront(){
        if(head==nullptr){
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    void display(){
        Node* temp=head;
        cout<<"\n Current Browsing History (Most recent first):\n";
        while(temp!=nullptr){
            cout<<temp->url;
            if(temp->next){
                cout<<" -> ";
            }
            temp=temp->next;
        }
        cout<<"\n";
    }

    string getCurrent(){
        if(head==nullptr){
            return "";
        }
        return head->url;
    }
};

int main(){
    LinkedList l;
    Stack s;

    string sites[]={"Google","Facebook","Twitter","LinkedIn","Instagram"};
    for(int i=0;i<5;i++){
        l.addFront(sites[i]);
        s.push(sites[i]);
    }

    cout<<"\nUser visited 5 websites:";
    l.display();
    cout<<" Current page: "<<l.getCurrent()<<endl;

    cout<<"\n User clicks 'Back' twice...\n";
    for(int i=0;i<2;i++){
        if(!s.empty()){
            cout<<"Going back from: "<<s.pop()<<endl;
            l.removeFront();
        }
    }

    l.display();
    cout<<" Current page after going back twice: "<<l.getCurrent()<<endl;

    return 0;
}
