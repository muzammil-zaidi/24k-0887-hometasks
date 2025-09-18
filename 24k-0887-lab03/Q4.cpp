#include<iostream>
#include<string>
using namespace std;

class TicketSystem{
private:
    struct Node{
        int id;
        string customer;
        string ride;
        Node* next;
        Node(int i,const string& c,const string& r) : id(i),customer(c),ride(r),next(nullptr){}
    };

    Node* tail;

public:
    TicketSystem() : tail(nullptr){}

    void issueEnd(int id,const string& customer,const string& ride){
        Node* n=new Node(id,customer,ride);
        if(!tail){
            tail=n;
            tail->next=tail;
        }
        else{
            n->next=tail->next;
            tail->next=n;
            tail=n;
        }
    }

    void issueFront(int id,const string& customer,const string& ride){
        Node* n=new Node(id,customer,ride);
        if(!tail){
            tail=n;
            tail->next=tail;
        }
        else{
            n->next=tail->next;
            tail->next=n;
        }
    }

    void cancelByID(int id){
        if(!tail){
            cout<<"No tickets to cancel.\n";
            return;
        }
        Node* curr=tail->next;
        Node* prev=tail;
        do{
            if(curr->id==id){
                if(curr==tail && curr==tail->next){
                    delete curr;
                    tail=nullptr;
                }
                else{
                    prev->next=curr->next;
                    if(curr==tail){
                        tail=prev;
                    }
                    delete curr;
                }
                cout<<"Cancelled ticket ID "<<id<<"\n";
                return;
            }
            prev=curr;
            curr=curr->next;
        }
        while(curr!=tail->next);
        cout<<"Ticket ID "<<id<<" not found.\n";
    }

    void cancelFront(){
        if(!tail){
            cout<<"No tickets to cancel.\n";
            return;
        }
        Node* head=tail->next;
        if(head==tail){
            delete head;
            tail=nullptr;
        }
        else{
            tail->next=head->next;
            delete head;
        }
        cout<<"Front ticket cancelled.\n";
    }

    void searchByID(int id) const{
        if(!tail){
            cout<<"No tickets found.\n";
            return;
        }
        Node* curr=tail->next;
        do{
            if(curr->id==id){
                cout<<"Ticket ID "<<curr->id<<" | Customer: "<<curr->customer<< " | Ride: "<<curr->ride<<"\n";
                return;
            }
            curr=curr->next;
        }
        while(curr!=tail->next);
        cout<<"Ticket ID "<<id<<" not found.\n";
    }

    void displayAll() const{
        if(!tail){
            cout<<"No tickets booked.\n";
            return;
        }
        cout<<"\nAll Tickets (circular order):\n";
        Node* curr=tail->next;
        do{
            cout<<"ID "<<curr->id<<" | Customer: "<<curr->customer<< " | Ride: "<<curr->ride<<"\n";
            curr=curr->next;
        }
        while(curr!=tail->next);
    }

    int countTickets() const{
        if(!tail){
            return 0;
        }
        int count=0;
        Node* curr=tail->next;
        do{
            count++;
            curr=curr->next;
        }
        while(curr!=tail->next);
        return count;
    }

    void nextTicket(int id) const{
        if(!tail){
            cout<<"No tickets available.\n";
            return;
        }
        Node* curr=tail->next;
        do{
            if(curr->id==id){
                Node* nxt=curr->next;
                cout<<"Next Ticket After "<<id<<":\n"<<"ID "<<nxt->id<< " | Customer: "<<nxt->customer<<" | Ride: "<<nxt->ride<<"\n";
                return;
            }
            curr=curr->next;
        }
        while(curr!=tail->next);
        cout<<"Ticket ID "<<id<<" not found.\n";
    }
    
    ~TicketSystem(){
        if(!tail){
            return;
        }
        Node* curr=tail->next;
        Node* nextNode;
        do{
            nextNode=curr->next;
            delete curr;
            curr=nextNode;
        }
        while(curr!=tail->next);
        tail=nullptr;
    }
};

int main(){
    TicketSystem ts;

    ts.issueEnd(1,"Ali","RollerCoaster");
    ts.issueEnd(2,"Sara","FerrisWheel");
    ts.issueFront(3,"VIP-Amir","HauntedHouse");
    ts.issueEnd(4,"Nida","WaterRide");

    ts.displayAll();
    cout<<"Total tickets: "<<ts.countTickets()<<"\n\n";
    ts.searchByID(2);
    ts.nextTicket(2);
    ts.cancelByID(3);
    ts.cancelFront();
    ts.displayAll();
    cout<<"Total tickets: "<<ts.countTickets()<<"\n";

    return 0;
}
