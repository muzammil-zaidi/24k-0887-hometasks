#include<iostream>
using namespace std;

class Box {
private:
    int* volume;

public:
    Box(){
        volume=new int(0);
    }

    Box(int v){
        volume=new int(v);
    }

    Box(const Box& other){
        volume=new int(*other.volume);
    }

    ~Box(){
        delete volume;
    }

    void setVolume(int v){
        *volume=v;
    }

    void display() const{
        cout<<"Volume: "<<*volume<<endl;
    }
};

int main(){
    Box b1;
    cout<<"Box 1 (Default Constructor): ";
    b1.display();

    Box b2(50);
    cout<<"Box 2 (Parameterized Constructor): ";
    b2.display();

    Box b3=b2;
    cout<<"Box 3 (Copied from Box 2): ";
    b3.display();

    b3.setVolume(100);
    cout<<"\nAfter changing Box 3's volume:\n";
    cout<<"Box 2: ";
    b2.display();
    cout<<"Box 3: ";
    b3.display();

    return 0;
}
