#include<iostream>
using namespace std;

int getMax(int arr[],int n){
    int maxVal=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>maxVal)
            maxVal=arr[i];
    }
    return maxVal;
}

void countingSort(int arr[],int n,int exp){
    int output[n];
    int count[10]={0};

    for(int i=0;i<n;i++){
        count[(arr[i] / exp) % 10]++;
    }

    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }

    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

void radixSort(int arr[],int n){
    int maxVal=getMax(arr,n);
    for(int exp=1;maxVal/exp>0;exp*=10){
        countingSort(arr,n,exp);
    }
}

int main(){
    int scores[50]={
        78,90,45,23,88,95,67,54,12,100,34,76,81,50,9,30,44,63,99,25,84,56,68,47,71,53,40,91,85,19,97,66,32,60,14,27,58,72,83,20,92,64,77,11,36,49,80,29,59,70
    };

    int n=50;

    cout<<"Original Scores:\n";
    for(int i=0;i<n;i++){
        cout<<scores[i]<<" ";
    }
    cout<<"\n\n";

    radixSort(scores,n);

    cout<<"Scores Sorted in Ascending Order:\n";
    for(int i=0;i<n;i++){
        cout<<scores[i]<<" ";
    }
    cout<<"\n\n";

    cout<<"Ranks of Students (1 = Highest Score):\n";
    for(int i=n-1,rank=1;i>=0;i--,rank++){
        cout<<"Rank "<<rank<<" -> Score: "<<scores[i]<<endl;
    }

    return 0;
}
