#include <bits/stdc++.h>

using namespace std;

//流程說明：首先我們將容器分為未排序和已排序的部分，如果前一筆>後一筆則交換
//優化：只要在未排序的部分中比對都沒有交換位置→代表 未排序的部分本身已有序 + 已排序的部分 整體排序完成 →退出loop
//時間複雜度 (Time Complexity)
// Best Case:O(n) 只需要跑一輪就退出，表示本來就是排序好的 (n-1)次比較 所以次數=O(n)
// Worst Case:O(n^2) 因為每次都要交換直到最後一輪的最後一次才會完成 所以次數=(n-1)+(n-2)+.....+1=n*(n-1)/2=O(n^2)
// Average Case:O(n^2) 但Average Case的證明我們之後再補上 Average不是邊界狀況，我們需要模擬平均的狀況才能證明
// Space Complexity : 只需要一個變數用來暫存交換時的變數值
// Stable Sort，理由是等於時不會交換 (同樣的鍵值不會因為排序而改變相對位置)

void showlist(vector<int>arr){
    for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
    cout<<endl;
}

void BubbleSort(vector<int>arr){
    for(int i=1;i<arr.size();i++){
        for(int j=0;j<arr.size()-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                showlist(arr);
            }
        }
    }
    showlist(arr);
}

void GoodBubbleSort(vector<int>arr){

    bool end=false;                             
    for(int i=1;i<arr.size()&&!end;i++){
        end=true;
        for(int j=0;j<arr.size()-i;j++){        
            if(arr[j]>arr[j+1]){                
                swap(arr[j],arr[j+1]);
                end=false;
                showlist(arr);         
            }
        }
    }
    showlist(arr);
}

//兩者差異在於一個永遠是O(n^2) 另一個會依照資料而有不同複雜度。

int main(){

    vector<int>arr;
    int data;
    while(cin>>data)arr.push_back(data);
    BubbleSort(arr);

    return 0;
}