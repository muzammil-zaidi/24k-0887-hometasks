#include<iostream>
#include<string>
using namespace std;

struct Order{
    int orderID;
    string customerName;
    double totalPrice;
};

int partition(Order arr[],int low,int high){
    double pivot=arr[high].totalPrice;
    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j].totalPrice<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(Order arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

void displayOrders(Order arr[],int n){
    cout<<"-------------------------------------------------------------\n";
    cout<<"Order ID\tCustomer Name\tTotal Price\n";
    cout<<"-------------------------------------------------------------\n";
    for(int i=0;i<n;i++){
        cout<<arr[i].orderID<<"\t\t\t"<<arr[i].customerName<<"\t\t\t"<<arr[i].totalPrice<<endl;
    }
    cout<<"-------------------------------------------------------------\n";
}

int main(){
    int n;
    cout<<"Enter number of orders: ";
    cin>>n;

    Order* orders=new Order[n];

    cout<<"\nEnter details of each order:\n";
    for(int i=0;i<n;i++){
        cout<<"\nOrder "<<i+1<<" ID: ";
        cin>>orders[i].orderID;
        cout<<"Customer Name: ";
        cin.ignore();
        getline(cin,orders[i].customerName);
        cout<<"Total Price: ";
        cin>>orders[i].totalPrice;
    }

    cout<<"\nOriginal Orders:\n";
    displayOrders(orders,n);

    cout<<"\nOrders Sorted by Total Price (Ascending):\n";
    quickSort(orders,0,n-1);

    displayOrders(orders,n);

    delete[] orders;
    return 0;
}
