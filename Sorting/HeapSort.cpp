#include <bits/stdc++.h>

using namespace std;

void heapify(vector<int>&arr,int index,int range){
    int left=2*index+1,
        right=2*index+2,
        target;

    if(left<=range && arr[left] < arr[index])target=left;
    else target=index;
    
    if(right<=range && arr[right] < arr[target])target=right;
    
    if(target!=index){
        swap(arr[target],arr[index]);
        heapify(arr,target,range);
    }
}

void HeapSort(vector<int>&arr){
    for(int i=arr.size()/2-1;i>=0;i--)heapify(arr,i,arr.size()-1);

    for(int i=arr.size()-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,0,i-1);
    }
    
}


int main(){

    vector<int>arr={9,6,4,2,3,5,7,1,1};
    HeapSort(arr);
    
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";



    return 0;
}