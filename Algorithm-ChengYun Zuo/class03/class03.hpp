//
//  class03.hpp
//  Algorithm-ChengYun Zuo
//
//  Created by Yan on 2022/6/26.
//

#ifndef class03_hpp
#define class03_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>

using namespace std;

//比较器

struct Stu{
    string name;
    int id;
    int age;
    Stu() {};
    Stu(string name, int id, int age): name(name), id(id), age(age){};
};

void printStudents(Stu* students, int len);

class Comparator{
public:
    //接口类
    virtual ~Comparator() {}
    virtual int comparator() = 0;
};

bool idAscendingComparator(Stu o1, Stu o2);
bool idDescendingComparator(Stu o1, Stu o2);
bool ageAscendingComparator(Stu o1, Stu o2);
bool ageDescendingComparator(Stu o1, Stu o2);

class Student{
public:
    string name;
    int id;
    int age;
    Student():name("yoking"), id(2021020892), age(24) { }
    Student(string name, int id, int age){
        this->name = name;
        this->id = id;
        this->age = age;
    }
    static void printStudents(vector<Student> students);
    class IdAscendingComparator: public Comparator{
        int comparator(Student o1, Student o2);
    };
};

void printArr(int* arr, int len);

//计数排序
//only for 0~200 value
class CountSort{
public:
    static void countSort(vector<int>& arr);
};

//基数排序
class RadixSort{
public:
    static void radixSort(vector<int>& arr);
    static int maxBits(vector<int> arr);
    static void radixSort(vector<int>& arr, int begin, int end, int digit);
    static int getDigit(int x, int d);
};


#endif /* class03_hpp */
