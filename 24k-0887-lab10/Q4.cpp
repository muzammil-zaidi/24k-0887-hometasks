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

    void removeMin(){
        if(size==0){
            return;
        }

        arr[1]=arr[size];
        size--;

        int i=1;
        while(true){
            int left=2*i;
            int right=2*i+1;
            int smallest=i;

            if(left<=size && arr[left]<arr[smallest]){
                smallest=left;
            }
            if(right<=size && arr[right]<arr[smallest]){
                smallest=right;
            }

            if(smallest==i){
                break;
            }

            swap(arr[i],arr[smallest]);
            i=smallest;
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

    h.insert(100);
    h.insert(50);
    h.insert(75);
    h.insert(60);
    cout<<"Heap after initial orders: ";
    h.display();

    h.insert(55);
    cout<<"Heap after inserting 55: ";
    h.display();

    h.removeMin();
    cout<<"Heap after removing lowest price: ";
    h.display();

    return 0;
}
