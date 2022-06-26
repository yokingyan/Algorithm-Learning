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

//堆排序
//某个数处在现在index位置，往上继续移动
void HeapSort::heapInsert(vector<int> &arr, int index){
    while (arr[index] > arr[(index - 1) / 2]) {
        swap(arr[index], arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void HeapSort::heapify(vector<int> &arr, int index, int heapSize){
    int left = index * 2 + 1;
    while (left < heapSize) {
        int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
        largest = arr[largest] > arr[index] ? largest : index;
        
        if(largest == index){
            break;
        }
        
        swap(arr[largest], arr[index]);
        index = largest;
        left = 2 * index + 1;
    }
}

void HeapSort::heapSort(vector<int> &arr){
    if (arr.size() < 1) {
        return;
    }else{
        int heapSize = arr.size();
//        for (int i = 0; i < arr.size(); i++) { //O(N)
//            heapInsert(arr, i);  //O(logN)
//        }
        for (int i = arr.size() - 1; i >= 0; i--) {//O(N)
            heapify(arr, i, heapSize);
        }
        
        //int heapSize = arr.size();
        swap(arr[0], arr[--heapSize]);
        while (heapSize > 0) {
            heapify(arr, 0, heapSize);
            swap(arr[0], arr[--heapSize]);
        }
    }
}

//堆排序扩展题目
void SortArrayDistanceLessK::sortArrayDistanceLessK(vector<int>& arr, int k){
    priority_queue<int, vector<int>, greater<int>> heap;  //小根堆
    int index = 0;
    int len = arr.size();
    
    for(;index <= min(len, k);index++){
        heap.push(arr[index]);
    }
    int i = 0;
    for (; index < arr.size(); i++, index++) {
        heap.push(arr[index]);
        arr[i] = heap.top();
        heap.pop();
    }
    while (!heap.empty()) {
        arr[i++] = heap.top();
        heap.pop();
    }
}
