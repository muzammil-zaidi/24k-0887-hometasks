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

    void addItemTail(const string& name,int price){
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

    void deleteFront(){
        if(!head){
            cout<<"Cart is already empty.\n";
            return;
        }
        Node* temp=head;
        head=head->next;
        cout<<"Removed: "<<temp->name<<" – $"<<temp->price<<"\n";
        delete temp;
    }

    void searchByName(const string& item) const{
        Node* temp=head;
        while(temp){
            if(temp->name==item){
                cout<<"Found: "<<temp->name<<" – $"<<temp->price<<"\n";
                return;
            }
            temp=temp->next;
        }
        cout<<item<<" not found in cart.\n";
    }

    void searchByPosition(int pos) const{
        if(pos<=0){
            cout<<"Invalid position.\n";
            return;
        }
        Node* temp=head;
        int index=1;
        while(temp && index<pos){
            temp=temp->next;
            index++;
        }
        if(temp){
            cout<<"Position "<<pos<<": "<<temp->name<<" – $"<<temp->price<<"\n";
        }
        else{
            cout<<"No item at position "<<pos<<".\n";
        }
    }

    void display() const{
        if(!head){
            cout<<"Cart is empty.\n";
            return;
        }
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

    cart.addItemTail("Laptop",1000);
    cart.addItemTail("Phone",700);
    cart.addItemTail("Tablet",400);
    cart.addItemTail("Headphones",150);

    cart.display();
    cart.deleteFront();
    cart.searchByName("Tablet");
    cart.searchByName("Camera");
    cart.searchByPosition(2);
    cart.searchByPosition(10);
    cart.display();

    return 0;
}
