//
//  class02.hpp
//  Algorithm-ChengYun Zuo
//
//  Created by Yan on 2022/6/18.
//

#ifndef class02_hpp
#define class02_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class MergeSort{
public:
    static void mergeSort(vector<int>& arr);
    static void mergeSort(vector<int>& arr, int l, int r);
    static void merge(vector<int>& arr, int l, int m, int r);
};

class SmallSum{
public:
    static int smallSum(vector<int>& arr);
    static int mergeSort(vector<int>& arr, int l, int r);
    static int merge(vector<int>& arr, int l, int m, int r);
};

class NetherlandsFlag{
public:
    static vector<int> partition(vector<int>& arr, int l, int r, int p);
};

class QuickSort{
public:
    static void quickSort(vector<int> &arr, int L, int R);
    static vector<int> partition(vector<int> &arr, int L, int R);
};


#endif /* class02_hpp */
