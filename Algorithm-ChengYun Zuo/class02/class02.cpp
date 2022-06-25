//
//  class02.cpp
//  Algorithm-ChengYun Zuo
//
//  Created by Yan on 2022/6/18.
//

#include "class02.hpp"

//mergeSort：归并排序
void MergeSort::mergeSort(vector<int>& arr){
    if(arr.size() < 2){
        return;
    }else{
        MergeSort::mergeSort(arr, 0, arr.size()-1);
    }
}

void MergeSort::mergeSort(vector<int>& arr, int l, int r){
    if(l == r){
        return;
    }else{
        int mid = l + ((r - l)>>1);
        MergeSort::mergeSort(arr, l, mid);
        MergeSort::mergeSort(arr, mid+1, r);
        MergeSort::merge(arr, l, mid, r);
    }
}

void MergeSort::merge(vector<int>& arr, int l, int m, int r){
    //int* help = new int[r-l+1];
    vector<int> help(r-l+1);
    int i = 0;
    int p1 = l;
    int p2 = m+1;
    while(p1 <= m && p2 <= r){
        help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= m) {
        help[i++] = arr[p1++];
    }
    while (p2 <= r) {
        help[i++] = arr[p2++];
    }

    for(int i = 0;i < help.size();i++){
        arr[l+i] = help[i];
    }
    //delete [] help;
}

//小和问题
int SmallSum::smallSum(vector<int> &arr){
    if(arr.size() < 2){
        return 0;
    }else{
        return SmallSum::mergeSort(arr, 0, arr.size()-1);
    }
}

int SmallSum::mergeSort(vector<int> &arr, int l, int r){
    if(l == r){
        return 0;
    }else{
        int mid = l + ((r - l) >> 1);
        return SmallSum::mergeSort(arr, l, mid)
        + SmallSum::mergeSort(arr, mid+1, r)
        + SmallSum::merge(arr, l, mid, r);
    }
}

int SmallSum::merge(vector<int> &arr, int l, int m, int r){
    vector<int> help(r-l+1);
    int i = 0;
    int p1 = l;
    int p2 = m + 1;
    int res = 0;
    
    while(p1 <= m && p2 <= r){
        res += arr[p1] < arr[p2] ? (r - p2 + 1) * arr[p1] : 0;
        help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }
    while(p1 <= m){
        help[i++] = arr[p1++];
    }
    while (p2 <= r) {
        help[i++] = arr[p2++];
    }
    
    for(int i = 0;i < help.size();i++){
        arr[l+i] = help[i];
    }
    return res;
}

//荷兰国旗问题
vector<int> NetherlandsFlag::partition(vector<int> &arr, int l, int r, int p){
    int less = l - 1;
    int more = r + 1;
    
    while(l < more){
        if(arr[l] < p){
            swap(arr[++less], arr[l++]);
        }else if(arr[l] > p){
            swap(arr[--more], arr[l]);
        }else{
            l++;
        }
    }
    return arr;
}

//快速排序
vector<int> QuickSort::partition(vector<int> &arr, int L, int R){
    int less = L - 1;
    int more = R;
    
    while(L < more){
        if(arr[L] < arr[R]){
            swap(arr[++less], arr[L++]);
        }else if (arr[L] > arr[R]){
            swap(arr[--more], arr[L]);
        }else{
            L++;
        }
    }
    swap(arr[more], arr[R]);
    return vector<int> {less + 1, more};
}

void QuickSort::quickSort(vector<int> &arr, int L, int R){
    if(L < R){
        //swap(arr[L+(int)(random()*(R - L + 1))], arr[R]);//快排 3.0
        vector<int> p = partition(arr, L, R);
        quickSort(arr, L, p[0] - 1);
        quickSort(arr, p[1] + 1, R);
    }
}
