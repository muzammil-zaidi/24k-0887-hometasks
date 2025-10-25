#include<iostream>
#include<string>
using namespace std;

#define MAX 100

struct Order{
    int orderID;
    string itemName;
    int quantity;
};

class OrderQueue{
private:
    Order queue[MAX];
    int front,rear;

public:
    OrderQueue(){
        front=-1;
        rear=-1;
    }

    bool isEmpty(){
        return (front==-1 || front>rear);
    }

    bool isFull(){
        return (rear==MAX-1);
    }

    void addOrder(Order o){
        if(isFull()){
            cout<<" Queue Overflow! Cannot take more orders.\n";
            return;
        }
        if(front==-1){
            front=0;
        }
        queue[++rear]=o;
        cout<<"Order "<<o.orderID<<" ("<<o.itemName<<" x"<<o.quantity<<") added successfully.\n";
    }

    void processOrder(){
        if(isEmpty()){
            cout<<" Queue Underflow! No orders to process.\n";
            return;
        }
        cout<<" Order "<<queue[front].orderID<<" ("<<queue[front].itemName<<" x"<<queue[front].quantity<<") has been processed.\n";
        front++;
    }

    void nextOrder(){
        if(isEmpty()){
            cout<<"No pending orders.\n";
            return;
        }
        cout<<" Next Order -> ID:"<<queue[front].orderID<<" | Item: "<<queue[front].itemName<<" | Quantity: "<<queue[front].quantity<<endl;
    }

    void displayAllOrders(){
        if(isEmpty()){
            cout<<"No orders in queue.\n";
            return;
        }

        cout<<"\n Current Orders in Queue:\n";
        for(int i=front;i<=rear;i++){
            cout<<i-front+1<<". Order ID: "<<queue[i].orderID<<" | Item: "<<queue[i].itemName<<" | Quantity: "<<queue[i].quantity<<endl;
        }
    }
};

int main(){
    OrderQueue restaurantQueue;
    Order o;
    int choice;

    cout<<"\n===  Restaurant Order Management System ===\n";

    do{
        cout<<"\n1. Add New Order";
        cout<<"\n2. Process Order";
        cout<<"\n3. View Next Order";
        cout<<"\n4. Display All Orders";
        cout<<"\n5. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"\nEnter Order ID: ";
                cin>>o.orderID;
                cout<<"Enter Item Name: ";
                cin>>o.itemName;
                cout<<"Enter Quantity: ";
                cin>>o.quantity;
                restaurantQueue.addOrder(o);
                break;

            case 2:
                restaurantQueue.processOrder();
                break;

            case 3:
                restaurantQueue.nextOrder();
                break;

            case 4:
                restaurantQueue.displayAllOrders();
                break;

            case 5:
                cout<<"\nExiting... Thank you for using the system!\n";
                break;

            default:
                cout<<"Invalid choice! Please try again.\n";
        }
    }
    while(choice!=5);

    return 0;
}
