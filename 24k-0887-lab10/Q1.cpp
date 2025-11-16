#include<iostream>
using namespace std;

class MinHeap{
public:
    int arr[100];
    int size;

    MinHeap(){
        size=0;
    }

    void insert(int value){
        arr[++size]=value;
        int i=size;

        while(i>1 && arr[i]<arr[i/2]){
            swap(arr[i],arr[i/2]);
            i=i/2;
        }
    }

    void display(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    MinHeap h;

    h.insert(3);
    h.insert(5);
    h.insert(4);
    h.insert(1);

    cout<<"Heap before inserting 2: ";
    h.display();

    h.insert(2);
    cout<<"Heap after inserting 2: ";
    h.display();

    return 0;
}
