#include<iostream>
#include<string>
using namespace std;

class ShoppingCart{
private:
    struct Node{
        int id;
        string name;
        int price;
        Node* prev;
        Node* next;
        Node(int i,const string& n,int p) : id(i), name(n),price(p),prev(nullptr),next(nullptr){}
    };

    Node* head;
    Node* tail;

public:
    ShoppingCart() : head(nullptr),tail(nullptr){}

    void insertEnd(int id,const string& name,int price){
        Node* newNode=new Node(id,name, price);
        if(!tail){
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }

    void insertFront(int id,const string& name,int price){
        Node* newNode=new Node(id,name,price);
        if(!head){
            head=tail=newNode;
            return;
        }
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }

    void removeFront(){
        if(!head){
            cout<<"Cart is empty.\n";
            return;
        }
        Node* temp=head;
        cout<<"Removed (front): "<<temp->name<<" – $"<<temp->price<<"\n";
        head=head->next;
        if(head){
            head->prev=nullptr;
        }
        else{
            tail=nullptr;
        }
        delete temp;
    }

    void removeEnd(){
        if(!tail){
            cout<<"Cart is empty.\n";
            return;
        }
        Node* temp=tail;
        cout<<"Removed (end): "<<temp->name<<" – $"<<temp->price<<"\n";
        tail=tail->prev;
        if(tail){
            tail->next=nullptr;
        }
        else{
            head=nullptr;
        }
        delete temp;
    }

    void searchByID(int id) const{
        Node* temp=head;
        while(temp){
            if(temp->id==id){
                cout<<"Found: ID "<<temp->id<<" | "<<temp->name<<" – $"<<temp->price<<"\n";
                return;
            }
            temp=temp->next;
        }
        cout<<"Item with ID "<<id<<" not found.\n";
    }

    void updatePrice(int id,int newPrice){
        Node* temp=head;
        while(temp){
            if(temp->id==id){
                cout<<"Updated "<<temp->name<<" price from $"<<temp->price<<" to $"<<newPrice<<"\n";
                temp->price=newPrice;
                return;
            }
            temp=temp->next;
        }
        cout<<"Item with ID "<<id<<" not found.\n";
    }

    void displayForward() const{
        if(!head){
            cout<<"Cart is empty.\n";
            return;
        }
        cout<<"\nCart (Front → End):\n";
        for(Node* t=head;t;t=t->next){
            cout<<"ID "<<t->id<<" | "<<t->name<<" – $"<<t->price<<"\n";
        }
    }

    void displayBackward() const{
        if (!tail){
            cout<<"Cart is empty.\n";
            return;
        }
        cout<<"\nCart (End → Front):\n";
        for(Node* t=tail;t;t=t->prev){
            cout<<"ID "<<t->id<<" | "<<t->name<<" – $"<<t->price<< "\n";
        }
    }

    int countItems() const{
        int count=0;
        for(Node* t=head;t;t=t->next){
            count++;
        }
        return count;
    }

    void mostExpensive() const{
        if(!head){
            cout<<"Cart is empty.\n";
            return;
        }
        Node* maxNode=head;
        for(Node* t=head->next;t;t=t->next){
            if(t->price > maxNode->price){
                maxNode=t;
            }
        }

        cout<<"\nMost Expensive Item:\n"<<"ID "<<maxNode->id<<" | "<<maxNode->name<<" – $"<<maxNode->price<<"\n";
    }

    ~ShoppingCart(){
        while(head){
            Node* temp=head;
            head=head->next;
            delete temp;
        }
        tail=nullptr;
    }
};

int main(){
    ShoppingCart cart;

    cart.insertEnd(101,"Laptop",1000);
    cart.insertEnd(102,"Phone",700);
    cart.insertFront(103,"Urgent-Headphones",150);
    cart.insertEnd(104,"Tablet",400);

    cart.displayForward();
    cart.displayBackward();
    cart.removeFront();
    cart.removeEnd();
    cart.searchByID(102);
    cart.updatePrice(102, 750);
    cart.displayForward();
    
    cout<<"\nTotal items in cart: "<<cart.countItems()<<"\n";
    cart.mostExpensive();

    return 0;
}
