#include<iostream>
#include<string>
using namespace std;

#define MAX 100

struct Patron{
    string name;
    int numBooks;
};

class LibraryQueue{
private:
    Patron queue[MAX];
    int front,rear;

public:
    LibraryQueue(){
        front=-1;
        rear=-1;
    }

    bool isEmpty(){
        return (front==-1 || front>rear);
    }

    bool isFull(){
        return (rear==MAX-1);
    }

    void enqueue(Patron p){
        if(isFull()){
            cout<<"Queue Overflow! Too many patrons waiting.\n";
            return;
        }
        if (front==-1){
            front=0;
        }
        queue[++rear]=p;
        cout<<"Patron "<<p.name<<" added to the queue.\n";
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow! No patrons waiting.\n";
            return;
        }
        cout<<"Patron "<<queue[front].name<<" has completed the transaction and left the queue.\n";
        front++;
    }

    void displayQueue(){
        if(isEmpty()){
            cout<<"No patrons in the queue.\n";
            return;
        }

        cout<<"\nCurrent Queue of Patrons:\n";
        for(int i=front;i<=rear;i++){
            cout<<i-front+1<<". Name: "<<queue[i].name<<" | Books: "<<queue[i].numBooks<<endl;
        }
    }

    void peek(){
        if(isEmpty()){
            cout<<"No patrons to serve.\n";
            return;
        }
       cout<<"Next Patron -> "<<queue[front].name<<" ("<<queue[front].numBooks<<" books)\n";
    }
};

int main(){
    LibraryQueue q;
    int choice;
    Patron p;

    cout<<"\n--- Library Book Transaction System ---\n";

    do{
        cout<<"\n1. Add Patron to Queue";
        cout<<"\n2. Complete Transaction (Remove Patron)";
        cout<<"\n3. Show Next Patron";
        cout<<"\n4. Display All Patrons in Queue";
        cout<<"\n5. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter Patron Name: ";
                cin>>p.name;
                cout<<"Enter Number of Books: ";
                cin>>p.numBooks;
                q.enqueue(p);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                q.displayQueue();
                break;

            case 5:
                cout<<"Exiting... Library system closed.\n";
                break;

            default:
                cout<<"Invalid choice! Please try again.\n";
        }
    }
    while(choice!=5);

    return 0;
}
