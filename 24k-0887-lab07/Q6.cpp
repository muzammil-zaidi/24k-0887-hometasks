#include<iostream>
#include<string>
using namespace std;

struct Employee{
    string name;
    int id;
    double salary;
};

void merge(Employee arr[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;

    Employee L[n1],R[n2];

    for(int i=0;i<n1;i++){
        L[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }

    int i=0,j=0,k=left;

    while(i<n1 && j<n2){
        if(L[i].salary>=R[j].salary){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(Employee arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void displayTop3(Employee arr[],int n){
    cout<<"\nTop 3 Highest Paid Employees:\n";
    for(int i=0;i<3 && i<n;i++){
        cout<<i+1<<". "<<arr[i].name<<" (ID: "<<arr[i].id<<", Salary: "<<arr[i].salary<<")\n";
    }
}

int main(){
    Employee employees[12]={
        {"Raza",101,45000},
        {"Zara",102,60000},
        {"Ahmed",103,52000},
        {"Sara",104,95000},
        {"Bilal",105,48000},
        {"Fatima",106,90000},
        {"Hassan",107,40000},
        {"Ali",108,81000},
        {"Mustafa",109,60000},
        {"Ayesha",110,72000},
        {"Tariq",111,67000},
        {"Saad",112,56000}
    };

    int n=12;

    mergeSort(employees,0,n-1);

    cout<<"Employees Sorted by Salary (Descending):\n";
    for(int i=0;i<n;i++){
        cout<<employees[i].name<<" (ID: "<<employees[i].id<<", Salary: "<<employees[i].salary<<")\n";
    }

    displayTop3(employees,n);

    return 0;
}
