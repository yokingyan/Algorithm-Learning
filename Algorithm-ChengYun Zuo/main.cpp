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
#include "class03.hpp"


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
    
    /*
     class 03 详解桶排序以及排序内容大总结
     */
    
//    `比较器（c++仿函数）的使用
    /*
     1.比较器的实质就是重载比较运算符
     2.特殊标准的排序
     */
    
    //抽象类与接口的使用(to be continue...)
//    Student o1;
//    Student o2("yan", 2021020989, 25);
//    vector<Student> students = {o1, o2};
    //Student::printStudents(students);
    
    //cpp仿函数
    //1.使用STL提供的仿函数（greater, less, greater_equal, less_equal）
    //静态数组
//    int arr7[10] = {65,59,96,13,21,80,72,33,44,99};
//    printArr(arr7, 10);
//    sort(arr7, arr7+10, greater<int>());
//    printArr(arr7, 10);
    //vector
//    vector<int> arr8 = {65,59,96,13,21,80,72,33,44,99,100,12,3,2,1,7,6,9};
//    printArr(arr8);
//    sort(arr8.begin(), arr8.begin() + arr8.size(), greater<int>());
//    printArr(arr8);
//    //2.自己编写仿函数，用于特定抽象数据类型
//    Stu stu[3];
//    string name;
//    int id, age;
    
//    for(int i = 0;i < 3;i++){
//        cin>>name>>id>>age;
//        stu[i] = Stu(name,id,age);
//    }
//    stu[1] = {"yan liang", 1, 21};
//    stu[0] = {"wang aobo", 2, 23};
//    stu[2] = {"he zhaopu", 3, 24};
    
//    printStudents(stu, 3);
//    sort(stu, stu+3, idAscendingComparator);
//    printStudents(stu, 3);
//    sort(stu, stu+3, idDescendingComparator);
//    printStudents(stu, 3);
//    sort(stu, stu+3, ageAscendingComparator);
//    printStudents(stu, 3);
//    sort(stu, stu+3, ageDescendingComparator);
//    printStudents(stu, 3);

    
    
//    `非基于比较的排序-需要根据具体数据状况来制定比较规则
//    `基数排序
//    int digit = RadixSort::maxBits(arr1);
//    cout<<digit<<endl;
//    cout<<RadixSort::getDigit(89, 2)<<endl;
//    vector<int> arr5 = {31,82,63,32,25,13,107,534,421,92,321,31,9021,2192};
//    printArr(arr5);
//    RadixSort::radixSort(arr5);
//    printArr(arr5);
//    `计数排序
//    vector<int> arr6 = {32,45,23,12,34,54,89,45,3,187};
//    printArr(arr6);
//    CountSort::countSort(arr6);
//    printArr(arr6);
    
    return 0;
}
