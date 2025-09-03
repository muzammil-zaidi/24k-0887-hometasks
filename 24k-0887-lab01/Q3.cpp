#include<iostream>
using namespace std;

class Exam{
private:
    int* marks;
    int size;

public:
    Exam(int s, int arr[]){
        size=s;
        marks=new int[size];
        for(int i=0;i<size;i++){
            marks[i]=arr[i];
        }
    }

    ~Exam(){
        delete[] marks;
    }

    void setMark(int index,int value){
        if(index>=0 && index<size){
            marks[index]=value;
        }
    }

    void display() const{
        cout<<"Marks: ";
        for(int i=0;i<size;i++){
            cout<<marks[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int m1[]={85,90,78};
    Exam e1(3,m1);
    cout<<"Original Exam Object (e1): ";
    e1.display();

    Exam e2=e1;
    cout<<"Copied Exam Object (e2): ";
    e2.display();

    e2.setMark(1,50);
    cout<<"\nAfter modifying e2's marks:\n";
    cout<<"e1: ";
    e1.display();
    cout<<"e2: ";
    e2.display();

    return 0;
}
