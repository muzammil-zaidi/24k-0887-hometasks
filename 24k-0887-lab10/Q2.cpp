#include<iostream>
using namespace std;

class MaxHeap{
public:
    int arr[100];
    int size;

    MaxHeap(){
        size=0;
    }

    void insert(int value){
        arr[++size]=value;
        int i=size;

        while(i>1 && arr[i]>arr[i/2]){
            swap(arr[i],arr[i/2]);
            i=i/2;
        }
    }

    void removeMax(){
        if(size==0){
            return;
        }

        arr[1]=arr[size];
        size--;

        int i=1;
        while(true){
            int left=2*i;
            int right=2*i+1;
            int largest=i;

            if(left<=size && arr[left]>arr[largest]){
                largest=left;
            }

            if(right<=size && arr[right]>arr[largest]){
                largest=right;
            }

            if(largest==i){
                break;
            }

            swap(arr[i],arr[largest]);
            i=largest;
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
    MaxHeap h;

    h.insert(4);
    h.insert(7);
    h.insert(9);
    h.insert(6);

    cout<<"Heap before inserting 10: ";
    h.display();

    h.insert(10);
    cout<<"Heap after inserting 10: ";
    h.display();

    h.removeMax();
    cout<<"Heap after removing highest severity: ";
    h.display();

    return 0;
}
