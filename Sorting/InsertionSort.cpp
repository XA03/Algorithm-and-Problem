#include <bits/stdc++.h>

using namespace std;

//流程說明：分成已排序和未排序兩部分，每次處理未排序的第一筆將其放到已排序的部分中適當位置
//並且從已排序的尾端往前掃描，遇到
// Best Case: O(n)
// Average Case: O(n^2)
// Worst Case: O(n^2)
// SC :O(1)
// Stable Sorting

void showlist(vector<int>arr){
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
    cout<<endl;
}

void InsertionSort(vector<int>arr){
    int i,j,temp;
    for(i=1;i<arr.size();i++){                              
        temp=arr[i];                                        
        for(j=i-1;j>=0 && temp<arr[j];j--)arr[j+1]=arr[j];  
        arr[j+1]=temp;
        showlist(arr);
    }
}

int main(){

    vector<int>arr;
    int data;
    while(cin>>data)arr.push_back(data);
    InsertionSort(arr);

    return 0;
}