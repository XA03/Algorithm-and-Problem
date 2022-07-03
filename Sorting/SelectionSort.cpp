#include <bits/stdc++.h>

using namespace std;

//流程說明，將資料分成已排序和未排序，從未排序的部分取出 最大值 或是 最小值加入到已排序的尾巴
// Best Case: O(n^2)     就算排好也得(n-1)+(n-2)+....+1次=n*(n-1)/2 =O(n^2)
// Average Case: O(n^2)
// Worst Case: O(n^2)
// SC :O(1)
// Unstable Sort，舉個例子說明  {2*,3,1,4,2}的流程是→{1,3,2*,4,2}→{1,2*,3,4,2}→{1,2*,2,3,4} 由此可知2*,2明明值相同但是位置卻交換了ㄋ

void showlist(vector<int>arr){
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
    cout<<endl;
}

void SelectionSort(vector<int>arr){
    int index;

    for(int i=0;i<arr.size()-1;i++){
        index=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[index])index=j;
        }
        if(i!=index){
            swap(arr[i],arr[index]);
            showlist(arr);
        }
    }
    showlist(arr);
}


int main(){

    vector<int>arr;
    int data;
    while(cin>>data)arr.push_back(data);
    SelectionSort(arr);

    return 0;
}