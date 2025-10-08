/* Reason: Shell Sort is used because it is more efficient than Bubble Sort,
it compares elements far apart first, reducing total swaps and improving performance,
especially for larger or nearly sorted data.*/

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
    vector<int> luggage={32,25,40,12,18,50,28};

    cout<<"Original Luggage Weights: ";
    printArray(luggage);

    shellSort(luggage);

    cout<<"\nSorted Luggage Weights (lightest to heaviest): ";
    printArray(luggage);

    return 0;
}
