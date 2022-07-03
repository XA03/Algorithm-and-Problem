#include <bits/stdc++.h>

using namespace std;

//流程說明選一個基準值(Pivot)，把比Pivot小的擺左邊，比Pivot大的擺右邊 (Partition)
//分別對Pivot左邊序列和Pivot右邊序列重複動作(Recursive)，直到序列長度=1或沒有元素
// Divide and Conquer的典型，將原陣列的排序問題分成無數個長度為一的序列排序問題
// Pivot可以是隨機、第一個、中位數
// Best Case:O(nlogn) 第一個元素剛好是中位數
// Average Case:O(nlogn)
// Worst Case:O(n^2) 由小到大或由大到小

// SC:需要的不是儲存的記憶體空間，而是遞迴需要的StackFrame空間，由遞迴深度決定
// Best Case:O(nlogn)
// Worst Case:O(n^2)
// Unstable Sorting

void showlist(vector<int>arr){
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
    cout<<endl;
}

void partition(vector<int>arr,int pivot){
    int i=-1;
    for(int iter=0;iter<arr.size();iter++){
        if(iter==pivot)continue;
        if(arr[iter]<arr[pivot]){
            i++;
            if(i==pivot)pivot=iter;
            swap(arr[i],arr[iter]);
        }
    }
    swap(arr[i+1],arr[pivot]);
    showlist(arr);
}

int partitionforQsort(vector<int>&arr,int left,int right){
    int pivot=arr[left];
    int i=left-1;
    for(int iter=left+1;iter<right+1;iter++){
        if(arr[iter]<pivot){
            i++;
            swap(arr[i+1],arr[iter]);
        }
    }
    i++;
    swap(arr[i],arr[left]);
    return i;
}


void QuickSort(vector<int>&arr,int left,int right){
    if(left<right){
        int pivot=partitionforQsort(arr,left,right);
        QuickSort(arr,left,pivot-1);
        QuickSort(arr,pivot+1,right);
    }
}


int main(){

    vector<int>test={1,7,5,3,9};

    QuickSort(test,0,test.size()-1);
    

    return 0;
}