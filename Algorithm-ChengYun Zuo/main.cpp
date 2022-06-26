//
//  main.cpp
//  Algorithm-ChengYun Zuo
//
//  Created by Yan on 2022/6/18.
//

#include <iostream>
#include <vector>
#include "class01.hpp"
#include "class02.hpp"


using namespace std;

int main(int argc, const char * argv[]){
    
    vector<int> arr1 = {3,8,6,3,2,1,10,5,4,9};
//    printArr(arr1);
        
    /*
     class 01 认识复杂度和简单排序算法
     */

//        cout<<"select sort: ";
//        selectSort(arr1);
//        printArr(arr1);
//
//        cout<<"bubble sort: ";
//        bubbleSort(arr);
//        printArr(arr);
//
//        异或运算
//        1. 一种数出现了奇数次，其他所有数出现了偶数次，怎么找到出现奇数次的数？
//        2. 两种数出现了奇数次，其他所有数出现了偶数次，怎么找到这两种出现奇数次的数？
//
//        vector<int> arr2_1 = {1,1,2,2,3,3,6,6,7,7,7,8,8,9,9};
//        vector<int> arr2_2 = {1,1,1,2,2,3,3,6,6,7,7,7,8,8,9,9};
//
//        printOddTimesNum1(arr2_1);
//        printOddTimesNum2(arr2_2);
//
//        cout<<"insert sort: ";
//        insertSort(arr1);
//        printArr(arr1);
//        
//        二分法
//        1）在一个有序数组中，找某个数是否存在？
//        vector<int> sortedArr1 = {1,2,3,4,5,6,7,8,9,10};
//        int searchNum1 = 5, searchNum2 = 11;
//        cout<<"search the first num: "<<BSExist(sortedArr1, searchNum1)<<" "<<"search the second num: "<<BSExist(sortedArr1, searchNum2)<<endl;
//        2）在一个有序数组中，找>=某个数最左侧的位置？
//        vector<int> sortedArr2 = {1,1,2,2,3,3,3,4,4,5,5,6,6,6,7,7,8,8,8,9,9,9,10};
//        cout<<BSNearLeft(sortedArr2, 5)<<endl;
//        3）局部最小值问题？
//        vector<int> arr3 = { 6, 5, 3, 4, 6, 7, 8 };
//        printArr(arr3);
//        cout<<FindOneLessValueIndex(arr3)<<endl;
//
//        求最大值（递归）
//        vector<int> arr4 = {6, 5, 3, 4, 6, 7, 8, 11, 12, 34, 1};
//        cout<<getMax(arr4)<<endl;
        
    /*
     class 02 认识nlog(n)的排序
     */
    
//    `归并排序
//    MergeSort::mergeSort(arr1);
//    cout<<"merge sort: ";
//    printArr(arr1);
    
//    `小和问题
//    cout<<"Small Sum: ";
//    printArr(arr1);
//    cout<<SmallSum::smallSum(arr1)<<endl;
    
//    `荷兰国旗问题
//    vector<int> res = NetherlandsFlag::partition(arr1, 0, arr1.size() - 1, 5);
//    printArr(res);
    
//    `快速排序
//    QuickSort::quickSort(arr1, 0, arr1.size()-1);
//    printArr(arr1);
    
//    `堆排序
//    HeapSort::heapSort(arr1);
//    printArr(arr1);
    
//    test priority_queue with small Heap;
//    priority_queue<int, vector<int>, greater<int>> smallHeap;
//    vector<int> vals = {11, 77, 33, 55, 44, 66, 99, 88, 22};
//    for(auto &e : vals) smallHeap.push(e);
//    while(!smallHeap.empty()){
//        cout << smallHeap.top() << " ";
//        smallHeap.pop();
//    }
//    cout<<endl;
//    priority_queue<int, vector<int>, greater<int>> heap;
//    for(auto &e : arr1) heap.push(e);
//    while(!heap.empty()){
//        cout << heap.top() << " ";
//        heap.pop();
//    }
//    `堆排序扩展问题
    //要满足数组几乎有序，即数组中每个元素移动距离不超过k
//    printArr(arr1);
//    SortArrayDistanceLessK::sortArrayDistanceLessK(arr1, 8);
//    printArr(arr1);
    
    
    return 0;
}
