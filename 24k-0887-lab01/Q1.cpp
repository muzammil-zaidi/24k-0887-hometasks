#include<iostream>
#include<string>
using namespace std;

class ResearchPaper{
private:
    string* authors;
    int authorCount;

public:
    ResearchPaper(int count,string names[]){
        authorCount=count;
        authors=new string[authorCount];
        for(int i=0;i<authorCount;i++){
            authors[i]=names[i];
        }
    }

    ResearchPaper(const ResearchPaper& other){
        authorCount=other.authorCount;
        authors=new string[authorCount];
        for(int i=0;i<authorCount;i++){
            authors[i]=other.authors[i];
        }
    }

    ResearchPaper& operator=(const ResearchPaper& other){
        if(this==&other) return *this;

        delete[] authors;

        authorCount=other.authorCount;
        authors=new string[authorCount];
        for(int i=0;i<authorCount;i++){
            authors[i]=other.authors[i];
        }

        return *this;
    }

    ~ResearchPaper(){
        delete[] authors;
    }

    void display() const{
        cout<<"Authors: ";
        for(int i=0;i<authorCount;i++){
            cout<<authors[i];
            if(i<authorCount-1){
                cout<<", ";
            }
        }
        cout<<endl;
    }
};

int main(){
    string a1[]={"Alice","Harry","Charlie"};
    ResearchPaper p1(3,a1);

    cout<<"Original Paper:\n";
    p1.display();

    ResearchPaper p2=p1;
    cout<<"\nCopied Paper (via Copy Constructor):\n";
    p2.display();

    string a2[]={"David","Tom"};
    ResearchPaper p3(2,a2);
    p3=p1;
    cout<<"\nPaper3 after Assignment:\n";
    p3.display();

    return 0;
}
