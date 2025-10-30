#include<iostream>
#include<vector>
using namespace std;

int getMax(vector<int>& arr){
    int maxVal=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]>maxVal){
            maxVal=arr[i];
        }
    }
    return maxVal;
}

void display(vector<int>& arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void countingSort(vector<int>& arr,int exp){
    int n=arr.size();
    vector<int> output(n);
    int count[10]={0};

    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }

    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }

    for(int i=n-1;i>=0;i--){
        int digit=(arr[i]/exp)%10;
        output[count[digit]-1]=arr[i];
        count[digit]--;
    }

    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

void radixSort(vector<int>& arr){
    int maxVal=getMax(arr);

    for(int exp=1,pass=1;maxVal/exp>0;exp*=10,pass++){
        countingSort(arr,exp);
        cout<<"After pass "<<pass<<" (sorting by digit at position "<<exp<<"):\n";
        display(arr);
        cout<<endl;
    }
}

int main(){
    int n=20;
    vector<int> productIDs(n);

    cout<<"Enter 20 product IDs (each 5-digit integer):\n";
    for(int i=0;i<n;i++){
        cout<<"Product "<<i+1<<": ";
        cin>>productIDs[i];
    }

    cout<<"\nOriginal Product IDs:\n";
    display(productIDs);
    cout<<endl;

    radixSort(productIDs);

    cout<<"Final Sorted Product IDs (Ascending Order):\n";
    display(productIDs);

    return 0;
}
