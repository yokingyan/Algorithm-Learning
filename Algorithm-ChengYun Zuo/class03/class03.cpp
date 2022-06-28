//
//  class03.cpp
//  Algorithm-ChengYun Zuo
//
//  Created by Yan on 2022/6/26.
//

#include "class03.hpp"


//比较器（仿函数）
int Student::IdAscendingComparator::comparator(Student o1, Student o2){
    return o1.id - o2.id;
}

void Student::printStudents(vector<Student> students){
    for(Student student : students){
        cout<<"Name : "<<student.name<<", Id : "<<student.id<<", age : "<<student.age<<endl;
    }
}

void printArr(int* arr, int len){
    for (int i = 0; i < len; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printStudents(Stu* students, int len){
    for (int i = 0; i < len; i++) {
        cout<<students[i].name<<" "<<students[i].id<<" "<<students[i].age<<" // ";
    }
    cout<<endl;
}

bool idAscendingComparator(Stu o1, Stu o2){
    return o1.id > o2.id;
}

bool idDescendingComparator(Stu o1, Stu o2){
    return o1.id < o2.id;
}

bool ageAscendingComparator(Stu o1, Stu o2){
    return o1.age > o2.age;
}

bool ageDescendingComparator(Stu o1, Stu o2){
    return o1.age < o2.age;
}
//计数排序
//only for 0~200 value
void CountSort::countSort(vector<int> &arr){
    if (arr.size() < 2) {
        return;
    }else{
        int max = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            max = std::__1::max(max, arr[i]);
        }
        vector<int> bucket(max + 1, 0);
        for (int i = 0; i < arr.size(); i++) {
            bucket[arr[i]]++;
        }
        int i = 0;
        for (int j = 0; j < bucket.size(); j++) {
            while (bucket[j]-- > 0 ) {
                arr[i++] = j;
            }
        }
    }
}

//基数排序
void RadixSort::radixSort(vector<int> &arr){
    if(arr.size() <= 1){
        return;
    }else{
        radixSort(arr, 0, arr.size()-1, maxBits(arr));
    }
}

int RadixSort::maxBits(vector<int> arr){
    int max = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        max = std::__1::max(max, arr[i]);
    }
    
    int res = 0;
    while (max != 0) {
        res++;
        max /= 10;
    }
    return res;
}

void RadixSort::radixSort(vector<int> &arr, int begin, int end, int digit){
    const int radix = 10;
    int i = 0, j = 0;
    
    vector<int> bucket(end - begin + 1, 0);
    for(int d = 1;d <= digit;d++){
        vector<int> count(radix, 0);
        for(i = begin;i <= end;i++){
            j = getDigit(arr[i], d);
            count[j]++;
        }
        for (i = 1; i < radix;i++) {
            count[i] = count[i] + count[i - 1];
        }
        for (i = end; i >= begin; i--) {
            j = getDigit(arr[i], d);
            bucket[count[j] - 1] = arr[i];
            count[j]--;
        }
        for (i = begin, j = 0; i <= end; i++, j++) {
            arr[i] = bucket[j];
        }
    }
}

int RadixSort::getDigit(int x, int d){
    return ((x / ((int)pow(10, d - 1))) % 10);
}
