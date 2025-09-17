#include<iostream>
#include<string>
using namespace std;

class ShoppingCart{
private:
    struct Node{
        string name;
        int price;
        Node* next;
        Node(string n,int p) : name(n),price(p),next(nullptr){}
    };

    Node* head;

public:
    ShoppingCart() : head(nullptr){}

    void addFront(const string& name,int price){
        Node* newNode=new Node(name,price);
        newNode->next=head;
        head=newNode;
    }

    void addEnd(const string& name,int price){
        Node* newNode=new Node(name,price);
        if(!head){
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    void insertAfter(const string& afterItem,const string& name, int price){
        Node* temp=head;
        while(temp && temp->name!=afterItem){
            temp=temp->next;
        }
        if(temp){
            Node* newNode=new Node(name,price);
            newNode->next=temp->next;
            temp->next=newNode;
        }
        else{
            cout<<afterItem<<" not found.\n";
        }
    }

    void searchItem(const string& item) const{
        Node* temp=head;
        while(temp){
            if(temp->name==item){
                cout<<item<<" exists. Price: $"<<temp->price<<"\n";
                return;
            }
            temp=temp->next;
        }
        cout<<item<<" not found.\n";
    }

    void display() const{
        cout<<"\nShopping Cart Items:\n";
        Node* temp=head;
        while(temp){
            cout<<temp->name<<" – $"<<temp->price<<"\n";
            temp=temp->next;
        }
    }

    ~ShoppingCart(){
        while(head){
            Node* temp=head;
            head=head->next;
            delete temp;
        }
    }
};

int main(){
    ShoppingCart cart;

    cart.addEnd("Laptop",1000);
    cart.addEnd("Phone",700);
    cart.addEnd("Tablet",400);
    cart.addEnd("Headphones",150);

    cart.addFront("Smartwatch",200);
    cart.addEnd("Keyboard",80);
    cart.insertAfter("Phone","Monitor",300);
    cart.searchItem("Tablet");
    cart.display();

    return 0;
}
