/*Shell Sort is more efficient than Insertion Sort 
because it compares elements that are far apart,
reducing the number of movements early on. As the gap decreases,
the list becomes nearly sorted, and the final pass is very fast.*/

#include<iostream>
#include<vector>
using namespace std;

void printArray(const vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void shellSort(vector<int>& arr){
    int n=arr.size();
    int pass=1;
    
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int temp=arr[i];
            int j;
            for(j=i;j>=gap && arr[j-gap]>temp;j-=gap)
                arr[j]=arr[j-gap];
            arr[j]=temp;
        }

        cout<<"After pass "<<pass++<<" (gap = "<<gap<<"): ";
        printArray(arr);
    }
}

int main(){
    vector<int> IDs={205,102,310,450,120,90};

    cout<<"Original Book IDs: ";
    printArray(IDs);

    shellSort(IDs);

    cout<<"\nSorted Book IDs: ";
    printArray(IDs);

    return 0;
}
