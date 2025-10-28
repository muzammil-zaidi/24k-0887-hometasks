#include<iostream>
#include<vector>
using namespace std;

int getMax(vector<int>& arr){
    int maxVal=arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]>maxVal)
            maxVal=arr[i];
    }
    return maxVal;
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

    for(int exp=1;maxVal/exp>0;exp*=10){
        countingSort(arr,exp);
    }
}

int main(){
    int n;
    cout<<"Enter number of transactions: ";
    cin>>n;

    vector<int> transactions(n);
    cout<<"\nEnter transaction amounts:\n";
    for(int i=0;i<n;i++){
        cout<<"Transaction "<<i+1<<": ";
        cin>>transactions[i];
    }

    cout<<"\nOriginal Transaction Amounts:\n";
    for(int i=0;i<n;i++){
        cout<<transactions[i]<<" ";
    }
    cout<<endl;

    radixSort(transactions);

    cout<<"\nTransactions Sorted in Ascending Order (Stable):\n";
    for(int i=0;i<n;i++){
        cout<<transactions[i]<<" ";
    }
    cout<<endl;

    return 0;
}
